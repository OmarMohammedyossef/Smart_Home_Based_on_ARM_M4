/*
  =============================================================================
 * Name		:RCC_configration.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

/*File Guard*/
#ifndef RCC_CONFIGURATION_H_
#define RCC_CONFIGURATION_H_

/*configuration of internal clock*/
#define RCC_HSI_ITERRUPT_READY_ENABLE                             OFF
#define RCC_HSI_ENABLE                                            ON
#define RCC_LSI_ITERRUPT_READY_ENABLE                             OFF
#define RCC_LSI_ENABLE                                            OFF

/*configuration of external clock*/
#define HSE_VALUE                                                 25
#define RCC_CSS_ENABLE                                            ON
#define RCC_HSE_PYBAS_ENABLE                                      OFF
#define RCC_HSE_ITERRUPT_READY_ENABLE                             OFF
#define RCC_HSE_ENABLE                                            ON
#define RCC_LSE_PYBAS_ENABLE                                      OFF
#define RCC_LSE_ITERRUPT_READY_ENABLE                             OFF
#define RCC_LSE_ENABLE                                            OFF

/*configuration of PLLCLK
 *    PLLCLK=(PLL_INPUT_CLK*N_VALUE)/(M_VALUE*P_VALUE)
 *    PLLCLK must <=84 if PLLCLK is SYSTEM_CLOCK */
#define RCC_PLL_INPUT_CLK    /*HSE/HSI*/                          HSE
#define RCC_PLLCLK           /* 24<=PLLCLK<=84*/                  84
#define RCC_PLL_ITERRUPT_READY_ENABLE                             OFF
#define RCC_PLL_ENABLE                                            ON
/****************************************************************************/
#define RCC_SYSTEM_CLOCK                                          HSI
#define RCC_AHB_PRESCALER   /*1,2,4,8,16,64,128,256,512*/         1
#define RCC_APB_PRESCALER   /*1,4,8,16*/                          4
#define RCC_TIMERS_HIGH_CLOCK_ENABLE                              OFF

/*configuration of RTC*/
#define RCC_RTC_HSE_PRESCALER	    /* 2 TO 31 */                 8
#define RCC_RTC_CLOCK_SOURCE                                      HSE

#endif /* RCC_CONFIGURATION_H_ */
