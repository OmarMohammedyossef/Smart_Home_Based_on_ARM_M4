*
  =============================================================================
 * Name		:main.c
 * Author		:Omar Elshamy
 * Description 	: main master code
 * Created on	:5/9/2023
 ==============================================================================
 */

#include "LIB/STD_datatypes.h"
#include "LIB/state_errors.h"
#include "LIB/Delay_interface.h"
#include "MCAL/RCC_DRIVER/RCC_interface.h"
#include "MCAL/GPIO_DRIVER/GPIO_interface.h"
#include "MCAL/03_NVIC/NVIC_Interface.h"
#include "MCAL/04_EXTI/EXTI_Interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/TWI/TWI_int.h"
#include "HAL/EEPROM/EEPROM_int.h"
#include "HAL/LCD/LCD_int.h"
#include "HAL/05_KEYPAD/KEYPAD_Interface.h"
#include "HAL/01_LED/LED_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
u8 DoorIsOpen_Flag = 1;
void LockDoor_ISR(void);
DC_MOTOR_t Door = { GPIOA , GPIO_PIN_12, GPIO_PIN_14};
int main()
{

  RCC_voidinit();
  RCC_voidenable_peripheral_clock(RCC_GPIOA,RCC_HIGH_POWER);
  RCC_voidenable_peripheral_clock(RCC_GPIOB,RCC_HIGH_POWER);
  RCC_voidenable_peripheral_clock(RCC_ADC1,RCC_HIGH_POWER);
  RCC_voidenable_peripheral_clock(RCC_SYSCFG,RCC_HIGH_POWER);
  RCC_voidenable_peripheral_clock(RCC_USART1,RCC_HIGH_POWER);



  MGPIO_enumselect_pin_mode(GPIOA , GPIO_PIN_0 , GPIO_INPUT, GPIO_PULL_DOWN);
  EXTI_SetEXTIPort(EXTI_LINE0 , GPIOA);
  EXTI_SetSenseControl(EXTI_LINE0 , EXTI_RISING_EDGE);
  EXTI_SetCallBackFunction(EXTI_LINE0 , LockDoor_ISR);

  LED_t WrongPass_Led   = {GPIOA, GPIO_PIN_13,LED_ACTIVE_HIGH};
  LED_t CorrectPass_Led = {GPIOA, GPIO_PIN_15,LED_ACTIVE_HIGH};


  /* password */
  u8 Saved_Pass[4]={};
	/* i           --> counter for array of pass
	 * Pass_count  --> counter for password
	 * Press_value --> read pressed key from keypad
	 * */
  u8 i=0, Press_value = KEYPAD_NOT_PRESSED ,Pass_count ;
  u8 Trails=0 , CorrectPass_Flag = 0;

  EXTI_InterruptUnMask(EXTI_LINE0);
  NVIC_vInterruptEnable(6);
  LCD_enuInit();
  KEYPAD_Init();
  LED_Init(CorrectPass_Led);
  LED_Init(WrongPass_Led);
  DC_MOTOR_INIT(&Door);
  LED_OFF(CorrectPass_Led);


	LCD_enuWriteCommand(0x01);
	LCD_enuSendString("SET New Pass: ");
	for(i=0 ; i<4 ; i++)
	{
		LCD_enuGoToPosition(2 , i+1);
		Press_value = KEYPAD_GetPressedKey();
		while(Press_value == KEYPAD_NOT_PRESSED)
		{
				Press_value = KEYPAD_GetPressedKey();
		}
		LCD_enuWriteData('*');
		Saved_Pass[i]=Press_value;
	}
	while(1)
	{

		CorrectPass_Flag = 0;
		DoorIsOpen_Flag = 1 ;
		Pass_count=0;
		LCD_enuWriteCommand(0x01);
		LCD_enuSendString("Enter Password :");
		for(i=0 ; i<4 ; i++)
		{
			LCD_enuGoToPosition(2 , i+1);
			Press_value = KEYPAD_GetPressedKey();
			while(Press_value == KEYPAD_NOT_PRESSED)
			{
				Press_value = KEYPAD_GetPressedKey();
			}
			{
				LCD_enuWriteData('*');
				if(Saved_Pass[i] == Press_value)
				{
					Pass_count++;
				}
			}
		}
		if(Pass_count==4)
		{
			LCD_enuWriteCommand(0x01);
			LCD_enuSendString("WELCOME");
			LED_ON(CorrectPass_Led);
			DC_MOTOR_ON_CW(&Door);
			Delay_vMsIn16MHz(500);
			DC_MOTOR_OFF(&Door);
			CorrectPass_Flag = 1;

		}
		else
		{
			Trails++;
			LCD_enuWriteCommand(0x01);
			if(Trails !=3){
				LCD_enuSendString("TRY AGAIN ");
				Delay_vMsIn16MHz(300);
			}else{
				/*Do Nothing*/
			}

		}
		if(Trails == 3){
			LED_ON(WrongPass_Led);
			Trails = 0;
			u8 iterator = 0;
			LCD_enuWriteCommand(0x01);
			LCD_enuSendString("Wait for 3sec :");
			Delay_vMsIn16MHz(100);
			LCD_enuWriteCommand(0x01);
			for(iterator = 1 ; iterator <4 ; iterator++){
				LCD_SendNumber(iterator);
				LCD_enuWriteData('.');
				Delay_vMsIn16MHz(700);
			}
			LED_OFF(WrongPass_Led);
		}

		while( DoorIsOpen_Flag == 1 && CorrectPass_Flag == 1);
		if( DoorIsOpen_Flag == 0){
			DC_MOTOR_ON_CCW(&Door);
			Delay_vMsIn16MHz(500);
			DC_MOTOR_OFF(&Door);
			LED_OFF(CorrectPass_Led);
		}

	}
	return 0 ;
}
void LockDoor_ISR(void)
{
	DoorIsOpen_Flag = 0;


}
