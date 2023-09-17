/*
  =============================================================================
 * Name		:RCC_program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

/* file guards*/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* define masked names */
#define OFF                              0
#define ON                               1
#define HSI                              0
#define HSE                              1
#define PLLCLK                           2
#define LSI                              0
#define LSE                              2

/* define some values for PLLCLK configuration needs where PLLCLK=(PLL_INPUT_VALUE*N_value)/(M_VALUE*P_VALUE)
 *          where PLL_INPUT_VALUE equal HSI_VALUE OR HSE_VALUE according to what PLL input in configuration
 *          P_VALUE=P_VALUE1 when PLLCLK in configuration more than 23MHZ and lower than 55MHZ
 *          P_VALUE=P_VALUE2 when PLLCLK in configuration more than 54MHZ and lower than 85MHZ
 * */
#define HSI_VALUE                        16
#define P_VALUE1 /*2/4/6/8*/             8
#define P_VALUE2 /*2/4/6/8*/             4

/* define bits names */
#define RCC_PLLRDY                       25
#define RCC_PLLON                        24
#define RCC_CSSON                        19
#define RCC_HSEBYP                       18
#define RCC_HSERDY                       17
#define RCC_HSEON                        16
#define RCC_LSEBYP                       2
#define RCC_LSERDY                       1
#define RCC_LSEON                        0
#define RCC_HSIRDY                       1
#define RCC_HSION                        0
#define RCC_LSIRDY                       1
#define RCC_LSION                        0
#define RCC_PLLSRC                       22
#define RCC_PLLP_1                       17
#define RCC_PLLP_0                       16
#define RCC_PLLN_8                       14
#define RCC_PLLN_7                       13
#define RCC_PLLN_6                       12
#define RCC_PLLN_5                       11
#define RCC_PLLN_4                       10
#define RCC_PLLN_3                       9
#define RCC_PLLN_2                       8
#define RCC_PLLN_1                       7
#define RCC_PLLN_0                       6
#define RCC_PLLM_5                       5
#define RCC_PLLM_4                       4
#define RCC_PLLM_3                       3
#define RCC_PLLM_2                       2
#define RCC_PLLM_1                       1
#define RCC_PLLM_0                       0
#define RCC_MCO2_1                       31
#define RCC_MCO2_0                       30
#define RCC_MCO2PRE_2                    29
#define RCC_MCO2PRE_1                    28
#define RCC_MCO2PRE_0                    27
#define RCC_MCO1_1                       22
#define RCC_MCO1_0                       21
#define RCC_MCO1PRE_2                    26
#define RCC_MCO1PRE_1                    25
#define RCC_MCO1PRE_0                    24
#define RCC_RTCPRE_4                     20
#define RCC_RTCPRE_3                     19
#define RCC_RTCPRE_2                     18
#define RCC_RTCPRE_1                     17
#define RCC_RTCPRE_0                     16
#define RCC_APBPRE_2                     12
#define RCC_APBPRE_1                     11
#define RCC_APBPRE_0                     10
#define RCC_AHBPRE_3                     7
#define RCC_AHBPRE_2                     6
#define RCC_AHBPRE_1                     5
#define RCC_AHBPRE_0                     4
#define RCC_SW_1                         1
#define RCC_SW_0                         0
#define RCC_PLLREADYC                    20
#define RCC_HSEREADYC                    19
#define RCC_HSIREADYC                    18
#define RCC_LSEREADYC                    17
#define RCC_LSIREADYC                    16
#define RCC_PLLREADYIE                   12
#define RCC_HSEREADYIE                   11
#define RCC_HSIREADYIE                   10
#define RCC_LSEREADYIE                   9
#define RCC_LSIREADYIE                   8
#define RCC_PLLREADYF                    4
#define RCC_HSEREADYF                    3
#define RCC_HSIREADYF                    2
#define RCC_LSEREADYF                    1
#define RCC_LSIREADYF                    0
#define RCC_DMA2ENCLK                    22
#define RCC_DMA1ENCLK                    21
#define RCC_CRCENCLK                     12
#define RCC_GPIOHENCLK                   7
#define RCC_GPIOEENCLK                   4
#define RCC_GPIODENCLK                   3
#define RCC_GPIOCENCLK                   2
#define RCC_GPIOBENCLK                   1
#define RCC_GPIOAENCLK                   0
#define RCC_OTGFSENCLK                   7
#define RCC_PWRENCLK                     28
#define RCC_I2C3CLK                      23
#define RCC_I2C2CLK                      22
#define RCC_I2C1CLK                      21
#define RCC_USART2ENCLK                  17
#define RCC_SPI3ENCLK                    15
#define RCC_SPI2ENCLK                    14
#define RCC_WWDGENCLK                    11
#define RCC_RTCENCLK                     15
#define RCC_TIM5ENCLK                    3
#define RCC_TIM4ENCLK                    2
#define RCC_TIM3ENCLK                    1
#define RCC_TIM2ENCLK                    0
#define RCC_TIM11ENCLK                   18
#define RCC_TIM10ENCLK                   17
#define RCC_TIM9ENCLK                    16
#define RCC_SYSCFGENCLK                  14
#define RCC_SPI4ENCLK                    13
#define RCC_SPI1ENCLK                    12
#define RCC_SDIOENCLK                    11
#define RCC_ADC1ENCLK                    8
#define RCC_USART6ENCLK                  5
#define RCC_USART1ENCLK                  4
#define RCC_TIM1ENCLK                    0
#define RCC_SRAM1ENCLKLP                 16
#define RCC_FLITFENCLKLP                 15
#define RCC_RTCSEL_1                     9
#define RCC_RTCSEL_0                     8
#define RCC_TIMPRE                       24

/* define registers names*/
#define BASE_ADDRESS                     0x40023830

typedef struct {
	volatile u32 BUS[16];
}RCC_BUS;


#define BUSES             ((RCC_BUS*) (BASE_ADDRESS))



#define RCC_CR                           *((volatile u32*) 0x40023800)
#define RCC_PLLCFGR                      *((volatile u32*) 0x40023804)
#define RCC_CFGR                         *((volatile u32*) 0x40023808)
#define RCC_CIR                          *((volatile u32*) 0x4002380C)
#define RCC_BDCR                         *((volatile u32*) 0x40023870)
#define RCC_CSR                          *((volatile u32*) 0x40023874)
#define RCC_DCKCFGR                      *((volatile u32*) 0x4002388C)

#endif /* RCC_PRIVATE_H_ */
