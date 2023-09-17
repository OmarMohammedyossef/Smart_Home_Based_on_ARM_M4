/*
  =============================================================================
 * Name		:GPIO_interface.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
       /*file guards*/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "../../LIB/state_errors.h"
/* define various speeds for output pin*/
#define GPIO_low_SPEED                         0
#define GPIO_MEDIUM_SPEED                      1
#define GPIO_HIGH_SPEED                        2
#define GPIO_VERY_HIGH_SPEED                   3

#define GPIO_LOW                               0
#define GPIO_HIGH                              1
#define GPIO_PULL_UP                           1
#define GPIO_PULL_DOWN                         2
#define GPIO_FLOATING                          0
#define GPIO_PUSH_PULL                         0
#define GPIO_OPEN_DRAIN                        1
/* define states of pin*/

#define GPIO_INPUT                             0
#define GPIO_OUTPUT                            1
#define GPIO_ALTERNATE_F                       2
#define GPIO_ANALOG                            3
/*define types of ports*/

#define GPIOA                                  0
#define GPIOB                                  1
#define GPIOC                                  2
#define GPIOD                                  3
#define GPIOE                                  4
#define GPIOH                                  1792

/*#define GPIO_PORT_A                                  0
#define GPIO_PORT_B                                  1
#define GPIO_PORT_C                                  2
#define GPIO_PORT_D                                  3
#define GPIO_PORT_E                                  4
#define GPIO_PORT_H                                  5*/
/* define types of pins in each port*/

#define GPIO_PIN_0                             0
#define GPIO_PIN_1                             1
#define GPIO_PIN_2                             2
#define GPIO_PIN_3                             3
#define GPIO_PIN_4                             4
#define GPIO_PIN_5                             5
#define GPIO_PIN_6                             6
#define GPIO_PIN_7                             7
#define GPIO_PIN_8                             8
#define GPIO_PIN_9                             9
#define GPIO_PIN_10                            10
#define GPIO_PIN_11                            11
#define GPIO_PIN_12                            12
#define GPIO_PIN_13                            13
#define GPIO_PIN_14                            14
#define GPIO_PIN_15                            15

/* define various alternative functions*/
#define GPIO_AF0_SYSTEM                        0
#define GPIO_AF1_TIM1_TIM2                     1
#define GPIO_AF2_TIM3_TIM5                     2
#define GPIO_AF3_TIM9_TIM11                    3
#define GPIO_AF4_I2C1_I2C3                     4
#define GPIO_AF5_SPI1_SPI4                     5
#define GPIO_AF6_SPI3                          6
#define GPIO_AF7_USART1_USART2                 7
#define GPIO_AF8_USART6                        8
#define GPIO_AF9_I2C2_I2C3                     9
#define GPIO_AF10_OTG_FS                       10
#define GPIO_AF11                              11
#define GPIO_AF12_SDIO                         12
#define GPIO_AF13                              13
#define GPIO_AF14                              14
#define GPIO_AF15_EVENTOUT                     15

/* each function take port name and pin number and another parameters*/
/* this function take pin mode and does this pin pull up or pull down*/
ES_t MGPIO_enumselect_pin_mode(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8pin_mode,u8 copy_u8pullup_down);

/*this function take output type and output speed*/
ES_t MGPIO_enumselect_output_type(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8output_type,u8 copy_u8pin_speed);

/*this function take input type */
//ES_t GPIO_enumselect_input_type(u8 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8input_type);

/*this function take alternate function name*/
ES_t MGPIO_enumselect_alternate_fun(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8alternate_name);

/* this function take output value*/
ES_t MGPIO_enumset_pin_value(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8pin_value);

/*this function take pointer to char to get on input value of the pin*/
ES_t MGPIO_enumget_pin_value(u16 copy_u8port_name,u8 copy_u8pin_id,u8* copy_u8pin_mode);

ES_t MGPIO_enumlocked_pin_configuration(u16 copy_u8port_name,u8 copy_u8pin_id);

ES_t MGPIO_enumrelease_pin_configuration(u16 copy_u8port_name,u8 copy_u8pin_id);

ES_t MGPIO_enumlocked_port_configuration(u16 copy_u8port_name);

ES_t MGPIO_enumrelease_port_configuration(u16 copy_u8port_name);

#endif /* GPIO_INTERFACE_H_ */
