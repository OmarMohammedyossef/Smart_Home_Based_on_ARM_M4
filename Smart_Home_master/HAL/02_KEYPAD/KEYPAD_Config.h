/*
  =============================================================================
 * Name		:KEYPAD_Config.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

#ifndef HAL_05_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_05_KEYPAD_KEYPAD_CONFIG_H_

/*Options:
 * 			kGPIOA
 * 			GPIOB
 * */
#define KEYPAD_Port GPIOB

#define KEYPAD_R1 GPIO_PIN_3
#define KEYPAD_R2 GPIO_PIN_4
#define KEYPAD_R3 GPIO_PIN_5
#define KEYPAD_R4 GPIO_PIN_6

#define KEYPAD_C1 GPIO_PIN_7
#define KEYPAD_C2 GPIO_PIN_8
#define KEYPAD_C3 GPIO_PIN_9
#define KEYPAD_C4 GPIO_PIN_10

u8 KEYPAD_Bottons[4][4] =
{
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'C','0','=','+'}
		
};



#endif /* HAL_05_KEYPAD_KEYPAD_CONFIG_H_ */
