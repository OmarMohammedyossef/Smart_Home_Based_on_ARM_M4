/*
  =============================================================================
 * Name		:LCD_config.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*			Mode : EIGHT_BIT -  FOUR_BIT     */
#define LCD_MODE		FOUR_BIT

/*			Control Pins					*/
#define RS_GRP			GPIOA
#define RS_PIN			GPIO_PIN_2

#define RW_GRP			GPIOA
#define RW_PIN			GPIO_PIN_3

#define EN_GRP			GPIOA
#define EN_PIN			GPIO_PIN_1


/*				Data Pins		*/

#define D7_GRP			GPIOB
#define D7_PIN			GPIO_PIN_13

#define D6_GRP			GPIOB
#define D6_PIN			GPIO_PIN_12

#define D5_GRP			GPIOA
#define D5_PIN			GPIO_PIN_5

#define D4_GRP			GPIOA
#define D4_PIN			GPIO_PIN_4



#define D3_GRP			GPIOA
#define D3_PIN			GPIO_PIN_7

#define D2_GRP			GPIOA
#define D2_PIN			GPIO_PIN_6

#define D1_GRP			GPIOA
#define D1_PIN			GPIO_PIN_5

#define D0_GRP			GPIOA
#define D0_PIN			GPIO_PIN_4


#endif /* LCD_CONFIG_H_ */
