/*
 =============================================================================
 * Name		    :KEYPAD_Interface.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */


#ifndef HAL_05_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_05_KEYPAD_KEYPAD_INTERFACE_H_


#define KEYPAD_NOT_PRESSED 0XFF
void KEYPAD_Init(void);
u8 KEYPAD_GetPressedKey(void);

#endif /* HAL_05_KEYPAD_KEYPAD_INTERFACE_H_ */
