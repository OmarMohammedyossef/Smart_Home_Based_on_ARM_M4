/*
  =============================================================================
 * Name		:SysTic_PRIVATE.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

/* file guards */
#ifndef SYSTIC_PRIVATE_H_
#define SYSTIC_PRIVATE_H_

#define CLKSOURCE                             2
#define COUNTFLAG                             16
#define TICKINT                               1
#define ENABLE                                0

/* system tick clock source types */
#define SYSTIC_AHB                            0
#define SYSTIC_AHB_8                          1

#define OFF                                   0
#define ON                                    1

/* system tick registers */
#define SYSTIC_CTRL                           *((volatile u32* )0xE000E010)
#define SYSTIC_LOAD                           *((volatile u32* )0xE000E014)
#define SYSTIC_VAL                            *((volatile u32* )0xE000E018)
#define SYSTIC_CALIP                          *((volatile u32* )0xE000E01C)

#endif /* SYSTIC_PRIVATE_H_ */
