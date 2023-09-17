/*
  =============================================================================
 * Name		    :main.c
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */


#include "../LIB/STD_datatypes.h"
#include "../LIB/state_errors.h"
#include "../LIB/Delay_interface.h"
#include "../MCAL/RCC_DRIVER/RCC_interface.h"
#include "../MCAL/GPIO_DRIVER/GPIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/SYSTIC_DRIVER/SysTic_INTERFACE.h"
#include "../MCAL/USART_DRIVER/USART_interface.h"
#include "../MCAL/03_NVIC/NVIC_Interface.h"
#include "../MCAL/04_EXTI/EXTI_Interface.h"
#include "../HAL/01_LED/LED_Interface.h"
#include "../HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/06_LM35/LM35_Interface.h"

#define USART1_IRQ    (37)
#define IRQ_EXTI2 (8)
#define IRQ_EXTI3 (9)

void HALL_Init(void);
void ROOM_Init(void);
void UART_ISR_Recieve(void);
void PIR1_ISR(void);
void PIR2_ISR(void);
/* HALL HW*/
LED_t led1  = {GPIOB , GPIO_PIN_4 , LED_ACTIVE_HIGH};
LED_t led2  = {GPIOB , GPIO_PIN_5 , LED_ACTIVE_HIGH};
DC_MOTOR_t Conditioner1 = {GPIOB , GPIO_PIN_2, GPIO_PIN_3 };

/* ROOM HW*/
LED_t led3  = {GPIOB , GPIO_PIN_6 , LED_ACTIVE_HIGH};
LED_t led4  = {GPIOB , GPIO_PIN_7 , LED_ACTIVE_HIGH};
DC_MOTOR_t Conditioner2 = {GPIOB , GPIO_PIN_8, GPIO_PIN_9 };

int main()
{

	RCC_voidinit();
	RCC_voidenable_peripheral_clock(RCC_GPIOA,RCC_HIGH_POWER);
	RCC_voidenable_peripheral_clock(RCC_GPIOB,RCC_HIGH_POWER);
	RCC_voidenable_peripheral_clock(RCC_ADC1,RCC_HIGH_POWER);
	RCC_voidenable_peripheral_clock(RCC_USART1,RCC_HIGH_POWER);


	/*Configure ADC Pin0 PIN1  as Analog Pins*/
	MGPIO_enumselect_pin_mode(GPIOA, GPIO_PIN_0, GPIO_ANALOG, GPIO_PULL_UP);
	MGPIO_enumselect_pin_mode(GPIOA, GPIO_PIN_1, GPIO_ANALOG, GPIO_PULL_UP);


	/*Configure USART PINS AS AF */
	MGPIO_enumselect_pin_mode(GPIOA, GPIO_PIN_9, GPIO_ALTERNATE_F, GPIO_PULL_UP);
	MGPIO_enumselect_alternate_fun(GPIOA, GPIO_PIN_9, GPIO_AF7_USART1_USART2);

	MGPIO_enumselect_pin_mode(GPIOA, GPIO_PIN_10, GPIO_ALTERNATE_F, GPIO_PULL_UP);
	MGPIO_enumselect_alternate_fun(GPIOA, GPIO_PIN_10, GPIO_AF7_USART1_USART2);


	/* Set USART Call Back Function*/
	USART_vCallbackRecieve(UART_ISR_Recieve);


	/*PIR1 , PIR2*/

	MGPIO_enumselect_pin_mode(GPIOA, GPIO_PIN_2, GPIO_INPUT, GPIO_FLOATING);
	MGPIO_enumselect_pin_mode(GPIOA, GPIO_PIN_3, GPIO_INPUT, GPIO_FLOATING);



	/* SET EXTIx SENSE CONTROL */
	EXTI_SetSenseControl(EXTI_LINE2 , EXTI_ON_CHANGE);
	EXTI_SetSenseControl(EXTI_LINE3 , EXTI_ON_CHANGE);

	/* SET CALL BACK FUNCTION  FOR PIR1 PIR2*/
	EXTI_SetCallBackFunction(EXTI_LINE2 , PIR1_ISR);
	EXTI_SetCallBackFunction(EXTI_LINE3 , PIR2_ISR);

	/*Un Mask "Enable" EXTI1 , EXTI2*/
	EXTI_InterruptUnMask(EXTI_LINE2);
	EXTI_InterruptUnMask(EXTI_LINE3);

	/* ENABLE NVIC IRQ  */
	NVIC_vInterruptEnable(IRQ_EXTI2);
	NVIC_vInterruptEnable(IRQ_EXTI3);

	/* Initialize Peripherals*/
	ADC_voidInit();
	USART_vInit();

	/* Enable USAERT Interrupt */
	NVIC_vInterruptEnable(USART1_IRQ);


	LCD_enuInit();
	HALL_Init();
	ROOM_Init();

	u16 Digital_Value;
	u16 Temerature1=0;
	u16 Temerature2=0;
	while (1)
	{
		Digital_Value = ADC_u16Read(0);
		Temerature1 = (Digital_Value * 3300UL)/4096.0;
		LCD_enuGoToPosition(1,1);
		LCD_enuSendString("HALL Temp = ");
		LCD_SendNumber(Temerature1/10);


		Digital_Value = ADC_u16Read(1);
		Temerature2 = (Digital_Value * 3300UL)/4096.0;
		LCD_enuGoToPosition(2,1);
		LCD_enuSendString("ROOM Temp = ");
		LCD_SendNumber(Temerature2/10);

		LCD_enuWriteCommand(0x01);
  }
}
void HALL_Init(void)
{

	LED_Init(led1);
	LED_Init(led2);
	DC_MOTOR_INIT(&Conditioner1);
}
void ROOM_Init(void)
{
	LED_Init(led3);
	LED_Init(led4);
	DC_MOTOR_INIT(&Conditioner2);

}
void UART_ISR_Recieve(void){

	u8 RecievedData=0;
	RecievedData = usart_voidrecieve_noblock();
	switch (RecievedData)
	{
		case '1': LED_ON(led1);  				break;
		case '2': LED_OFF(led1); 				break;
		case '3': LED_ON(led2);  				break;
		case '4': LED_OFF(led2); 				break;
		case '5': DC_MOTOR_ON_CW(&Conditioner1);break;
		case '6': DC_MOTOR_OFF(&Conditioner1);  break;
		case '7': LED_ON(led3); 				break;
		case '8': LED_OFF(led3); 				break;
		case '9': LED_ON(led4); 				break;
		case 'a': LED_OFF(led4); 				break;
		case 'b': DC_MOTOR_ON_CW(&Conditioner2);break;
		case 'c': DC_MOTOR_OFF(&Conditioner2); 	break;
		default : /*Do Nothing */ 				break;
	}
}

void PIR1_ISR(void)
{
	LED_Toggle(led1);
}
void PIR2_ISR(void)
{
	LED_Toggle(led3);
}
