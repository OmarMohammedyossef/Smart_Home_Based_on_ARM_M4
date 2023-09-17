/*
 * LCD_prog.c
 *
	 *  Created on: March 1, 2022
	 *      Author: Omar Elshamy
 */
#include "../../LIB/STD_datatypes.h"
#include "../../LIB/state_errors.h"
#include "../../LIB/Delay_interface.h"

#include "../../MCAL/RCC_DRIVER/RCC_interface.h"
#include "../../MCAL/GPIO_DRIVER/GPIO_interface.h"
#include "../../MCAL/SysTic_Driver/SysTic_INTERFACE.h"
#include "LCD_config.h"
#include "LCD_priv.h"


/*
	MGPIO_enumselect_pin_mode		(R1_GRP ,R1_PIN ,_MODE_INPUT  );
	MGPIO_enumselect_output_type	(R1_GRP ,R1_PIN ,GPIO_PUSH_PULL );
	MGPIO_vSetPinOutSpeed	(R1_GRP ,R1_PIN ,_OUTPUT_SPEED_MEDUIM );
	GPIO_SetPinInputType		(R1_GRP ,R1_PIN ,_PULL_DOWN );
	MGPIO_u8ReadData		(R1_GRP ,R1_PIN);
	MGPIO_enumset_pin_value		(R1_GRP ,R1_PIN ,GPIO_LOW );
 */


void LCD_enuInit(void)
{


	MGPIO_enumselect_pin_mode(RS_GRP, RS_PIN, GPIO_OUTPUT , GPIO_FLOATING);
	MGPIO_enumselect_pin_mode(RW_GRP, RW_PIN, GPIO_OUTPUT , GPIO_FLOATING);
	MGPIO_enumselect_pin_mode(EN_GRP, EN_PIN, GPIO_OUTPUT , GPIO_FLOATING);

	MGPIO_enumselect_pin_mode(D7_GRP, D7_PIN, GPIO_OUTPUT , GPIO_FLOATING);
	MGPIO_enumselect_pin_mode(D6_GRP, D6_PIN, GPIO_OUTPUT , GPIO_FLOATING);
	MGPIO_enumselect_pin_mode(D5_GRP, D5_PIN, GPIO_OUTPUT , GPIO_FLOATING);
	MGPIO_enumselect_pin_mode(D4_GRP, D4_PIN, GPIO_OUTPUT , GPIO_FLOATING);


	MGPIO_enumselect_output_type(RS_GRP, RS_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED);
	MGPIO_enumselect_output_type(RW_GRP, RW_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED);
	MGPIO_enumselect_output_type(EN_GRP, EN_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED);

	MGPIO_enumselect_output_type(D7_GRP, D7_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED);
	MGPIO_enumselect_output_type(D6_GRP, D6_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED);
	MGPIO_enumselect_output_type(D5_GRP, D5_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED );
	MGPIO_enumselect_output_type(D4_GRP, D4_PIN, GPIO_PUSH_PULL ,GPIO_HIGH_SPEED);





//	MGPIO_vSetPinOutSpeed(RS_GRP, RS_PIN, _OUTPUT_SPEED_MEDUIM );
//	MGPIO_vSetPinOutSpeed(RW_GRP, RW_PIN, _OUTPUT_SPEED_MEDUIM );
//	MGPIO_vSetPinOutSpeed(EN_GRP, EN_PIN, _OUTPUT_SPEED_MEDUIM );
//
//	MGPIO_vSetPinOutSpeed(D7_GRP, D7_PIN, _OUTPUT_SPEED_MEDUIM );
//	MGPIO_vSetPinOutSpeed(D6_GRP, D6_PIN, _OUTPUT_SPEED_MEDUIM );
//	MGPIO_vSetPinOutSpeed(D5_GRP, D5_PIN, _OUTPUT_SPEED_MEDUIM );
//	MGPIO_vSetPinOutSpeed(D4_GRP, D4_PIN, _OUTPUT_SPEED_MEDUIM );

#if LCD_MODE == EIGHT_BIT

	MGPIO_enumselect_pin_mode(D3_GRP, D3_PIN, GPIO_OUTPUT );
	MGPIO_enumselect_pin_mode(D2_GRP, D2_PIN, GPIO_OUTPUT );
	MGPIO_enumselect_pin_mode(D1_GRP, D1_PIN, GPIO_OUTPUT );
	MGPIO_enumselect_pin_mode(D0_GRP, D0_PIN, GPIO_OUTPUT );

	MGPIO_enumselect_output_type(D3_GRP, D3_PIN, GPIO_PUSH_PULL );
	MGPIO_enumselect_output_type(D2_GRP, D2_PIN, GPIO_PUSH_PULL );
	MGPIO_enumselect_output_type(D1_GRP, D1_PIN, GPIO_PUSH_PULL );
	MGPIO_enumselect_output_type(D0_GRP, D0_PIN, GPIO_PUSH_PULL );

	Delay_vMsIn16MHz(35);

	MGPIO_enumset_pin_value(RS_GRP, RS_PIN, GPIO_LOW );
	LCD_enuWriteNLatch(0x38);

#elif LCD_MODE == FOUR_BIT

	MGPIO_enumset_pin_value(RS_GRP, RS_PIN, GPIO_LOW );

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW);
	MGPIO_enumset_pin_value(RW_GRP, RW_PIN, GPIO_LOW);
	MGPIO_enumset_pin_value(D7_GRP, D7_PIN, 0 );
	MGPIO_enumset_pin_value(D6_GRP, D6_PIN, 0 );
	MGPIO_enumset_pin_value(D5_GRP, D5_PIN, 1 );
	MGPIO_enumset_pin_value(D4_GRP, D4_PIN, 0 );

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_HIGH );
	Delay_vMsIn16MHz(1);
	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW );
	Delay_vMsIn16MHz(20);

	LCD_enuWriteNLatch(0x28);

#else
#error "LCD mode configuration is wrong"
#endif

	//Display Control
	MGPIO_enumset_pin_value(RS_GRP, RS_PIN, GPIO_LOW);
	LCD_enuWriteNLatch(0x0F);
	Delay_vMsIn16MHz(1);


	//Display Clear
	MGPIO_enumset_pin_value(RS_GRP, RS_PIN, GPIO_LOW);
	LCD_enuWriteNLatch(0x01);
	Delay_vMsIn16MHz(2);

	//Entry Mode
	MGPIO_enumset_pin_value(RS_GRP, RS_PIN, GPIO_LOW);
	LCD_enuWriteNLatch(0x06);
	Delay_vMsIn16MHz(1);

}

void LCD_enuWriteData(u8 Copy_u8Data)
{

	MGPIO_enumset_pin_value(RS_GRP , RS_PIN , GPIO_HIGH);
	LCD_enuWriteNLatch(Copy_u8Data);


}

void LCD_enuWriteIntegerNum(u16 Copy_u16IntegerData)
{

	u8 Local_Au8InegerDigits[6]={0,0,0,0,0};
	u8 Local_u8Iterator = 0;

	if (Copy_u16IntegerData == 0)
	{
		MGPIO_enumset_pin_value(RS_GRP , RS_PIN , GPIO_HIGH);
		LCD_enuWriteNLatch('0');
	}

	while (Copy_u16IntegerData)
	{
		Local_Au8InegerDigits[Local_u8Iterator] = Copy_u16IntegerData % 1 ;
		Copy_u16IntegerData /= 1;
		Local_u8Iterator++ ;
	}

	while (Local_u8Iterator > 0)
	{
		Local_u8Iterator--;
		MGPIO_enumset_pin_value(RS_GRP , RS_PIN , GPIO_HIGH);
		LCD_enuWriteNLatch(Local_Au8InegerDigits[Local_u8Iterator]+'0');

	}

}

void LCD_enuWriteCommand(u8 Copy_u8Command)
{

	MGPIO_enumset_pin_value(RS_GRP , RS_PIN , GPIO_LOW);
	LCD_enuWriteNLatch(Copy_u8Command);

}

void LCD_enuSendString(const char * Copy_pcString)
{

	if (Copy_pcString != Null)
	{
		while (*Copy_pcString)
		{
			MGPIO_enumset_pin_value(RS_GRP , RS_PIN , GPIO_HIGH);
			LCD_enuWriteNLatch(*Copy_pcString++);
			//LCD_enuWriteNLatch(*Copy_pcString);
			//Copy_pcString++;
		}
	}

}

void LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{

	if (Copy_u8Row >=1 && Copy_u8Row <=2
			&& Copy_u8Col >=1 && Copy_u8Col <=16)
	{
		u8 Local_Au8AddLine[]= { 0x80 , 0xC0 };
		MGPIO_enumset_pin_value(RS_GRP , RS_PIN , GPIO_LOW);
		LCD_enuWriteNLatch(Local_Au8AddLine[Copy_u8Row - 1] + Copy_u8Col -1);
	}
}





static void LCD_enuWriteNLatch(u8 Copy_u8Byte)
{

#if LCD_MODE == EIGHT_BIT

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW);
	MGPIO_enumset_pin_value(RW_GRP, RW_PIN, GPIO_LOW);

	MGPIO_enumset_pin_value(D7_GRP, D7_PIN, ((Copy_u8Byte>>7)&1) );
	MGPIO_enumset_pin_value(D6_GRP, D6_PIN, ((Copy_u8Byte>>6)&1) );
	MGPIO_enumset_pin_value(D5_GRP, D5_PIN, ((Copy_u8Byte>>5)&1) );
	MGPIO_enumset_pin_value(D4_GRP, D4_PIN, ((Copy_u8Byte>>4)&1) );

	MGPIO_enumset_pin_value(D3_GRP, D3_PIN, ((Copy_u8Byte>>3)&1) );
	MGPIO_enumset_pin_value(D2_GRP, D2_PIN, ((Copy_u8Byte>>2)&1) );
	MGPIO_enumset_pin_value(D1_GRP, D1_PIN, ((Copy_u8Byte>>1)&1) );
	MGPIO_enumset_pin_value(D0_GRP, D0_PIN, ((Copy_u8Byte>>0)&1) );

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_HIGH );
	Delay_vMsIn16MHz(1);
	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW );



	Delay_vMsIn16MHz(20);



#elif LCD_MODE == FOUR_BIT

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW);
	MGPIO_enumset_pin_value(RW_GRP, RW_PIN, GPIO_LOW);

	MGPIO_enumset_pin_value(D7_GRP, D7_PIN, ((Copy_u8Byte>>7)&1) );
	MGPIO_enumset_pin_value(D6_GRP, D6_PIN, ((Copy_u8Byte>>6)&1) );
	MGPIO_enumset_pin_value(D5_GRP, D5_PIN, ((Copy_u8Byte>>5)&1) );
	MGPIO_enumset_pin_value(D4_GRP, D4_PIN, ((Copy_u8Byte>>4)&1) );

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_HIGH );
	Delay_vMsIn16MHz(1);
	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW );
	Delay_vMsIn16MHz(5);

	MGPIO_enumset_pin_value(D7_GRP, D7_PIN, ((Copy_u8Byte>>3)&1) );
	MGPIO_enumset_pin_value(D6_GRP, D6_PIN, ((Copy_u8Byte>>2)&1) );
	MGPIO_enumset_pin_value(D5_GRP, D5_PIN, ((Copy_u8Byte>>1)&1) );
	MGPIO_enumset_pin_value(D4_GRP, D4_PIN, ((Copy_u8Byte>>0)&1) );

	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_HIGH );
	Delay_vMsIn16MHz(1);
	MGPIO_enumset_pin_value(EN_GRP, EN_PIN, GPIO_LOW );
	Delay_vMsIn16MHz(5);

#else
#error "LCD mode configuration is wrong"
#endif

}
void LCD_SendNumber(s16 Num)
{
	s16 Loc_Temp = Num ;
	u8 Iterator = 0 ;
	u8 Iterator_2 = 0 ;
	u8 Negative_Flag = 0 ;
	char Num_Arr[5] = {};
	/* Store Number in Num_Arr as a string
		but the number will be stored in reverse order in the array so we need to reverse this array again
	 */
	if(Num==0)
	{
		LCD_enuWriteData('0');
		return;
	}
	if(Num<0)
	{
		Num = Num * (-1) ;
		Negative_Flag = 1 ;
	}
	while(Num != 0 )
	{
		Loc_Temp = Num % 10 ;
		Num_Arr[Iterator++] = ( Loc_Temp + '0' ) ;
		Num = Num / 10 ;
	}
	/* Reverse Num_arr */
	for(Iterator_2 = 0 ; Iterator_2 < Iterator/2 ; Iterator_2++)
	{
		char temp = Num_Arr[Iterator_2];
		Num_Arr[Iterator_2 ] = Num_Arr[Iterator-Iterator_2-1];
		Num_Arr[Iterator-Iterator_2-1] = temp;
	}

	for(Iterator_2 = 0 ; Iterator_2 < Iterator ; Iterator_2++ )
	{
		if(Negative_Flag)
		{
			LCD_enuWriteData('-');
			Negative_Flag = 0 ;
		}
		LCD_enuWriteData(Num_Arr[Iterator_2]);
	}
}

