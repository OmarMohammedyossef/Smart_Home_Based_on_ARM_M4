/*
  =============================================================================
 * Name		:RCC_program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */


#include "../../LIB/STD_datatypes.h"
#include "RCC_private.h"
#include "RCC_configuration.h"
#include "RCC_interface.h"
/* this function to configure RCC driver */
void RCC_voidinit(void){

    /* configuration of HSI*/
#if    RCC_HSI_ITERRUPT_READY_ENABLE == ON
	     set_bit(RCC_CIR,RCC_HSIREADYIE);
#elif  RCC_HSI_ITERRUPT_READY_ENABLE == OFF
         clear_bit(RCC_CIR,RCC_HSIREADYIE);
#endif
/**********************************************/
#if   RCC_HSI_ENABLE == ON
        set_bit(RCC_CR,RCC_HSION);
#elif RCC_HSI_ENABLE == OFF
        clear_bit(RCC_CR,RCC_HSION);
#endif

	/* configuration of LSI*/
#if   RCC_LSI_ITERRUPT_READY_ENABLE == ON
	    set_bit(RCC_CIR,RCC_LSIREADYIE);
#elif RCC_LSI_ITERRUPT_READY_ENABLE == OFF
	    clear_bit(RCC_CIR,RCC_LSIREADYIE);
#endif
/**********************************************/
#if   RCC_LSI_ENABLE == ON
	    set_bit(RCC_CSR,RCC_LSION);
#elif RCC_LSI_ENABLE == OFF
	    clear_bit(RCC_CSR,RCC_LSION);
#endif

	/* configuration of LSE*/
#if    RCC_LSE_ITERRUPT_READY_ENABLE == ON
	     set_bit(RCC_CIR,RCC_LSEREADYIE);
#elif  RCC_LSE_ITERRUPT_READY_ENABLE == OFF
	     clear_bit(RCC_CIR,RCC_LSEREADYIE);
#endif
/****************************************/
#if    RCC_LSE_PYBAS_ENABLE == ON
	     set_bit(RCC_BDCR,RCC_LSEBYP);
#elif  RCC_LSE_PYBAS_ENABLE == OFF
	     clear_bit(RCC_BDCR,RCC_LSEBYP);
#endif
/***************************************/
#if    RCC_LSE_ENABLE == ON
	     set_bit(RCC_BDCR,RCC_LSEON);
#elif  RCC_LSE_ENABLE == OFF
	     clear_bit(RCC_BDCR,RCC_LSEON);
#endif

   /* configuration for HSE*/
#if   RCC_CSS_ENABLE == ON
	    set_bit(RCC_CR,RCC_CSSON);
#elif RCC_CSS_ENABLE == OFF
	    clear_bit(RCC_CR,RCC_CSSON);
#endif
/***************************************/
#if   RCC_HSE_PYBAS_ENABLE ==ON
	    set_bit(RCC_CR,RCC_HSEBYP);
#elif RCC_HSE_PYBAS_ENABLE == OFF
	    clear_bit(RCC_CR,RCC_HSEBYP);
#endif
/**************************************/
#if    RCC_HSE_ITERRUPT_READY_ENABLE == ON
	     set_bit(RCC_CIR,RCC_HSEREADYIE);
#elif  RCC_HSE_ITERRUPT_READY_ENABLE == OFF
	     clear_bit(RCC_CIR,RCC_HSEREADYIE);
#endif
/****************************************/
#if   RCC_HSE_ENABLE == ON
        set_bit(RCC_CR,RCC_HSEON);
#elif RCC_HSE_ENABLE == OFF
        clear_bit(RCC_CR,RCC_HSEON);
#endif
      /* configuration of PLLCLK*/
#if   RCC_PLL_INPUT_CLK == HSE
        set_bit(RCC_PLLCFGR,RCC_PLLSRC);
        RCC_PLLCFGR&=~((u32)63);       /* this step to clear first six bits in RCC_PLLCFGR register*/
        RCC_PLLCFGR|=(u32)HSE_VALUE;
#elif RCC_PLL_INPUT_CLK == HSI
        clear_bit(RCC_PLLCFGR,RCC_PLLSRC);
        RCC_PLLCFGR&=~((u32)63);       /* this step to clear first six bits in RCC_PLLCFGR register*/
        RCC_PLLCFGR|=(u32)HSI_VALUE;
#endif
/*****************************************/
#if  (RCC_PLLCLK >=24) && (RCC_PLLCLK <=54)
        /*assign value for P_value */
        set_bit(RCC_PLLCFGR,RCC_PLLP_1);
        set_bit(RCC_PLLCFGR,RCC_PLLP_0);
        /* assign value for n_value */
        RCC_PLLCFGR&=~(((u32)511)<<RCC_PLLN_0); /*this step to clear bits belong to PLLN*/
        RCC_PLLCFGR|=(((u32)(RCC_PLLCLK*P_VALUE1))<<RCC_PLLN_0);
#elif (RCC_PLLCLK >54) && (RCC_PLLCLK <=84)
        /*assign value for P_value */
        set_bit(RCC_PLLCFGR,RCC_PLLP_0);
        clear_bit(RCC_PLLCFGR,RCC_PLLP_1);
        /* assign value for n_value */
        RCC_PLLCFGR&=~(((u32)511)<<RCC_PLLN_0); /*this step to clear bits belong to PLLN*/
        RCC_PLLCFGR|=(((u32)(RCC_PLLCLK*P_VALUE2))<<RCC_PLLN_0);
#endif
/*****************************************************/
#if   RCC_PLL_ITERRUPT_READY_ENABL == ON
        set_bit(RCC_CIR,RCC_PLLREADYIE);
#elif RCC_PLL_ITERRUPT_READY_ENABL == OF
        clear_bit(RCC_CIR,RCC_PLLREADYIE);
#endif
        /*enable or disable PLL*/
#if   RCC_PLL_ENABLE == ON
        set_bit(RCC_CR,RCC_PLLON);
#elif RCC_PLL_ENABLE == OF
        clear_bit(RCC_CR,RCC_PLLON);
#endif
        /* select which system clock source*/
#if   RCC_SYSTEM_CLOCK == HSI
        clear_bit(RCC_CFGR,RCC_SW_0);
        clear_bit(RCC_CFGR,RCC_SW_1);
#elif RCC_SYSTEM_CLOCK == HSE
        set_bit(RCC_CFGR,RCC_SW_0);
        clear_bit(RCC_CFGR,RCC_SW_1);
#elif RCC_SYSTEM_CLOCK == PLLCLK
        clear_bit(RCC_CFGR,RCC_SW_0);
        set_bit(RCC_CFGR,RCC_SW_1);
#endif
        /* select AHB prescaler*/
#if   RCC_AHB_PRESCALER == 1
        clear_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 2
        clear_bit(RCC_CFGR,RCC_AHBPRE_0);
        clear_bit(RCC_CFGR,RCC_AHBPRE_1);
        clear_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 4
        set_bit(RCC_CFGR,RCC_AHBPRE_0);
        clear_bit(RCC_CFGR,RCC_AHBPRE_1);
        clear_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 8
        clear_bit(RCC_CFGR,RCC_AHBPRE_0);
        set_bit(RCC_CFGR,RCC_AHBPRE_1);
        clear_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 16
        set_bit(RCC_CFGR,RCC_AHBPRE_0);
        set_bit(RCC_CFGR,RCC_AHBPRE_1);
        clear_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 64
        clear_bit(RCC_CFGR,RCC_AHBPRE_0);
        clear_bit(RCC_CFGR,RCC_AHBPRE_1);
        set_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 128
        set_bit(RCC_CFGR,RCC_AHBPRE_0);
        clear_bit(RCC_CFGR,RCC_AHBPRE_1);
        set_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 256
        clear_bit(RCC_CFGR,RCC_AHBPRE_0);
        set_bit(RCC_CFGR,RCC_AHBPRE_1);
        set_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#elif RCC_AHB_PRESCALER == 512
        set_bit(RCC_CFGR,RCC_AHBPRE_0);
        set_bit(RCC_CFGR,RCC_AHBPRE_1);
        set_bit(RCC_CFGR,RCC_AHBPRE_2);
        set_bit(RCC_CFGR,RCC_AHBPRE_3);
#endif
        /* select APB prescaler */
#if   RCC_APB_PRESCALER == 1
        clear_bit(RCC_CFGR,RCC_APBPRE_2);
#elif RCC_APB_PRESCALER == 2
        clear_bit(RCC_CFGR,RCC_APBPRE_0);
        clear_bit(RCC_CFGR,RCC_APBPRE_1);
        set_bit(RCC_CFGR,RCC_APBPRE_2);
#elif RCC_APB_PRESCALER == 4
        set_bit(RCC_CFGR,RCC_APBPRE_0);
        clear_bit(RCC_CFGR,RCC_APBPRE_1);
        set_bit(RCC_CFGR,RCC_APBPRE_2);
#elif RCC_APB_PRESCALER == 8
        clear_bit(RCC_CFGR,RCC_APBPRE_0);
        set_bit(RCC_CFGR,RCC_APBPRE_1);
        set_bit(RCC_CFGR,RCC_APBPRE_2);
#elif RCC_APB_PRESCALER == 16
        set_bit(RCC_CFGR,RCC_APBPRE_0);
        set_bit(RCC_CFGR,RCC_APBPRE_1);
        set_bit(RCC_CFGR,RCC_APBPRE_2);
#endif
        /*configuration of RTC*/
#if   RCC_RTC_CLOCK_SOURCE == LSI
        clear_bit(RCC_BDCR,RCC_RTCSEL_0);
        set_bit(RCC_BDCR,RCC_RTCSEL_1);
#elif RCC_RTC_CLOCK_SOURCE == LSE
        set_bit(RCC_BDCR,RCC_RTCSEL_0);
        clear_bit(RCC_BDCR,RCC_RTCSEL_1);
#elif RCC_RTC_CLOCK_SOURCE == HSE
        RCC_CFGR&=~(((u32)31)<<16);
        RCC_CFGR|=(((u32)RCC_RTC_HSE_PRESCALER)<<16);
        set_bit(RCC_BDCR,RCC_RTCSEL_0);
        set_bit(RCC_BDCR,RCC_RTCSEL_1);
#endif
        /* enable or disable timers high clock */
#if   RCC_TIMERS_HIGH_CLOCK_ENABLE == ON
        set_bit(RCC_DCKCFGR,RCC_TIMPRE);

#elif RCC_TIMERS_HIGH_CLOCK_ENABLE == OF
        clear_bit(RCC_DCKCFGR,RCC_TIMPRE);

#endif
}

/*this function to enable clock for each peripheral you select it
 *and select which power mode for this peripheral LOW_POWER or HIGH_POWER
 *e.x: GPIOA/GPIOB/GPIOC/GPIOD/GPIOE/GPIOH/DMA2/DMA1/CRC/OTGFS/PWR/I2C3/I2C2/I2C1/
 *     USART2/SPI3/SPI2/WWDG/RTC/
 *     TIM5/TIM4/TIM3/TIM2/TIM11/TIM10/TIM9/SYSCFG/SPI4/SPI1/SDIO/ADC1/USART6/
 *     USART1/TIM1/SRAM1/FLITF   set_bit(regester_name,bit_number);
 * */
void RCC_voidenable_peripheral_clock(u16 copy_u8prepheiral_name,u8 copy_u8power_mode){

        if(copy_u8power_mode == RCC_LOW_POWER){
        	if((copy_u8prepheiral_name==RCC_SRAM1)||(copy_u8prepheiral_name==RCC_FLITF)){
        		set_bit(BUSES->BUS[((copy_u8prepheiral_name)/(u16)32)],copy_u8prepheiral_name%32);
        	}
        	else{
                set_bit(BUSES->BUS[((copy_u8prepheiral_name+(u32)256)/(u16)32)],copy_u8prepheiral_name%32);

        	}
        }
        else{
        	set_bit(BUSES->BUS[((copy_u8prepheiral_name)/(u16)32)],copy_u8prepheiral_name%32);
        }
}

/*this function to disable clock for each peripheral you select it
 *e.x: GPIOA/GPIOB/GPIOC/GPIOD/GPIOE/GPIOH/DMA2/DMA1/CRC/OTGFS/PWR/I2C3/I2C2/I2C1/
 *     USART2/SPI3/SPI2/WWDG/RTC/
 *     TIM5/TIM4/TIM3/TIM2/TIM11/TIM10/TIM9/SYSCFG/SPI4/SPI1/SDIO/ADC1/USART6/
 *     USART1/TIM1/SRAM1/FLITF
 * */
void RCC_voiddisable_peripheral_clock(u16 copy_u8prepheiral_name,u8 copy_u8power_mode){

	        if(copy_u8power_mode == RCC_LOW_POWER){
	        	if((copy_u8prepheiral_name==RCC_SRAM1)||(copy_u8prepheiral_name==RCC_FLITF)){
	        		clear_bit(BUSES->BUS[((copy_u8prepheiral_name)/(u16)32)],copy_u8prepheiral_name%32);
	        	}
	        	else{
	                clear_bit(BUSES->BUS[((copy_u8prepheiral_name+(u32)256)/(u16)32)],copy_u8prepheiral_name%32);
	        	}
	        }
	        else{
	        	clear_bit(BUSES->BUS[((copy_u8prepheiral_name)/(u16)32)],copy_u8prepheiral_name%32);
	        }
}
