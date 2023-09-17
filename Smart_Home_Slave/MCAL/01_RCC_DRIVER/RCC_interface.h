/*
 =============================================================================
 * Name		    :RCC_interface.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_GPIOA         0
#define RCC_GPIOB         1
#define RCC_GPIOC         2
#define RCC_GPIOD         3
#define RCC_GPIOE         4
#define RCC_GPIOH         7
#define RCC_DMA2          22
#define RCC_DMA1          21
#define RCC_CRC           12
#define RCC_OTGFS         39
#define RCC_PWR           156
#define RCC_I2C3          151
#define RCC_I2C2          150
#define RCC_I2C1          149
#define RCC_USART2        145
#define RCC_SPI3          143
#define RCC_SPI2          142
#define RCC_WWDG          139
#define RCC_RTC           18
#define RCC_TIM5          131
#define RCC_TIM4          130
#define RCC_TIM3          129
#define RCC_TIM2          128
#define RCC_TIM11         178
#define RCC_TIM10         177
#define RCC_TIM9          176
#define RCC_SYSCFG        174
#define RCC_SPI4          173
#define RCC_SPI1          172
#define RCC_SDIO          171
#define RCC_ADC1          168
#define RCC_USART6        165
#define RCC_USART1        164
#define RCC_TIM1          160
#define RCC_SRAM1         272
#define RCC_FLITF         271
#define RCC_LOW_POWER     0
#define RCC_HIGH_POWER    1

/* this function to configure RCC driver */
void RCC_voidinit(void);

/*this function to enable clock for each peripheral you select it
 *and select which power mode for this peripheral LOW_POWER or HIGH_POWER
 *e.x: GPIOA/GPIOB/GPIOC/GPIOD/GPIOE/GPIOH/DMA2/DMA1/CRC/OTGFS/PWR/I2C3/I2C2/I2C1/
 *     USART2/SPI3/SPI2/WWDG/RTC/
 *     TIM5/TIM4/TIM3/TIM2/TIM11/TIM10/TIM9/SYSCFG/SPI4/SPI1/SDIO/ADC1/USART6/
 *     USART1/TIM1/SRAM1/FLITF
 * */
void RCC_voidenable_peripheral_clock(u16 copy_u8prepheiral_name,u8 copy_u8power_mode);

/*this function to disable clock for each peripheral you select it
 *e.x: GPIOA/GPIOB/GPIOC/GPIOD/GPIOE/GPIOH/DMA2/DMA1/CRC/OTGFS/PWR/I2C3/I2C2/I2C1/
 *     USART2/SPI3/SPI2/WWDG/RTC/
 *     TIM5/TIM4/TIM3/TIM2/TIM11/TIM10/TIM9/SYSCFG/SPI4/SPI1/SDIO/ADC1/USART6/
 *     USART1/TIM1/SRAM1/FLITF
 * */
void RCC_voiddisable_peripheral_clock(u16 copy_u8prepheiral_name,u8 copy_u8power_mode);

#endif /* RCC_INTERFACE_H_ */
