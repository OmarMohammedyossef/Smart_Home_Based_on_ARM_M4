/*
 * LCD_config.h
 *
 *  Created on: March 10, 2022
 *      Author: Omar Elshamy
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*			Mode : EIGHT_BIT -  FOUR_BIT     */
#define LCD_MODE		FOUR_BIT

/*			Control Pins					*/
#define RS_GRP			GPIOA
#define RS_PIN			GPIO_PIN_4

#define RW_GRP			GPIOB
#define RW_PIN			GPIO_PIN_13

#define EN_GRP			GPIOB
#define EN_PIN			GPIO_PIN_12


/*				Data Pins		*/

#define D7_GRP			GPIOA
#define D7_PIN			GPIO_PIN_8

#define D6_GRP			GPIOA
#define D6_PIN			GPIO_PIN_7

#define D5_GRP			GPIOA
#define D5_PIN			GPIO_PIN_6

#define D4_GRP			GPIOA
#define D4_PIN			GPIO_PIN_5



#define D3_GRP			GPIOA
#define D3_PIN			GPIO_PIN_7

#define D2_GRP			GPIOA
#define D2_PIN			GPIO_PIN_6

#define D1_GRP			GPIOA
#define D1_PIN			GPIO_PIN_5

#define D0_GRP			GPIOA
#define D0_PIN			GPIO_PIN_4


#endif /* LCD_CONFIG_H_ */
