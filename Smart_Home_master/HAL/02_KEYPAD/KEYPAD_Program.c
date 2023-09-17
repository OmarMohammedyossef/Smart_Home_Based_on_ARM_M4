/*
  =============================================================================
 * Name		:KEYPAD_Program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */


#include "../../LIB/STD_datatypes.h"
#include "../../MCAL/GPIO_DRIVER/GPIO_interface.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Config.h"

void KEYPAD_Init(void)
{
	/*Define KeyPad Rows Pin as Input Pull Up*/
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_R1 , GPIO_INPUT, GPIO_PULL_UP);
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_R2 , GPIO_INPUT, GPIO_PULL_UP);
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_R3 , GPIO_INPUT, GPIO_PULL_UP);
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_R4 , GPIO_INPUT, GPIO_PULL_UP);


	/*Define KeyPad Column Pin as OUTPUT Pins*/
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_C1 , GPIO_OUTPUT, GPIO_HIGH_SPEED);
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_C2 , GPIO_OUTPUT, GPIO_HIGH_SPEED);
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_C3 , GPIO_OUTPUT, GPIO_HIGH_SPEED);
	MGPIO_enumselect_pin_mode(KEYPAD_Port , KEYPAD_C4 , GPIO_OUTPUT, GPIO_HIGH_SPEED);

	/*Set KeyPad Column Pin HIGH Pins*/
	MGPIO_enumset_pin_value(KEYPAD_Port , KEYPAD_C1 , GPIO_HIGH);
	MGPIO_enumset_pin_value(KEYPAD_Port , KEYPAD_C2 , GPIO_HIGH);
	MGPIO_enumset_pin_value(KEYPAD_Port , KEYPAD_C3 , GPIO_HIGH);
	MGPIO_enumset_pin_value(KEYPAD_Port , KEYPAD_C4 , GPIO_HIGH);
}
u8 KEYPAD_GetPressedKey(void)
{
	u8 LocReturnKey  = KEYPAD_NOT_PRESSED ;
	u8 LocPressedVal ;
	u8 Col_Iterator ;
	u8 Row_Iterator;
	u8 Row_Arr[4] = {KEYPAD_R1, KEYPAD_R2, KEYPAD_R3, KEYPAD_R4};
	u8 Col_Arr[4] = {KEYPAD_C1, KEYPAD_C2, KEYPAD_C3, KEYPAD_C4};

	for(Col_Iterator = 0 ; Col_Iterator < 4 ; Col_Iterator++ ){

		MGPIO_enumset_pin_value(KEYPAD_Port ,  Col_Arr[Col_Iterator] , GPIO_LOW );

		for(Row_Iterator=0 ; Row_Iterator < 4 ; Row_Iterator++ ){

			MGPIO_enumget_pin_value(KEYPAD_Port , Row_Arr[Row_Iterator] , &LocPressedVal);
			if(LocPressedVal == GPIO_LOW )
			{
					LocReturnKey = KEYPAD_Bottons[Row_Iterator][Col_Iterator];
			 	/* IF the key still pressed this function will return the same data again
					so we need to make a delay 200 ms or instead of this we do as the following -->
				 */
				MGPIO_enumget_pin_value(KEYPAD_Port , Row_Arr[Row_Iterator] , &LocPressedVal);
				while(LocPressedVal == GPIO_LOW){//Button still pressed
					MGPIO_enumget_pin_value(KEYPAD_Port ,  Row_Arr[Row_Iterator] , &LocPressedVal);
				}
				return LocReturnKey ;
			}
		}
		MGPIO_enumset_pin_value(KEYPAD_Port ,  Col_Arr[Col_Iterator] , GPIO_HIGH );
	}

	return LocReturnKey ;
}
