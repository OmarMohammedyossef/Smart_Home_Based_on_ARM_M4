/*
  =============================================================================
 * Name		:SysTic_CONFIGURATION.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
/* file guards */
#ifndef SYSTIC_CONFIGURATION_H_
#define SYSTIC_CONFIGURATION_H_

/* select what is the clock of MCU */
#define SYSTEM_CLOCK                       16000000U

/* systick clock can be (SYSTIC_AHP or SYSTIC_AHP_8) */
#define SYSTIC_CLOCK                       SYSTIC_AHB_8

/* time tick be in mile second */
#define SYSTIC_TIME_TIC                    500

/* enable or disable the interrupt for SysTic */
#define SYSTIC_INTERRUPT_ENABLE            ON

/* enable or disable the SysTic */
#define SYSTIC_COUNT_ENABLE                ON

#endif /* SYSTIC_CONFIGURATION_H_ */
