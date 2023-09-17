/*
 =============================================================================
 * Name		    :SysTic_INTERFACE.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */
/*
 *  Description : this file contain on prototypes for APIs of System Tick driver like
 *  1-void SysTic_voidinit(void);
 *  2-void SysTic_void_delay_ms(u16 copy_u16delay_time);
 *  3-void SysTic_voidone_tick_time_ms(u16 copy_u16one_tick_time);
 *  4-void SysTic_voidenable_count(void);
 *  5-void SysTic_voiddisable_count(void);
 *  6-void SysTic_voidenable_interrupt(void);
 *  7-void SysTic_voiddisable_interrupt(void);
 */

/* file guards */
#ifndef SYSTIC_INTERFACE_H_
#define SYSTIC_INTERFACE_H_

/* this function select System Tick clock source
 *  which be (SYSTIC_AHP or SYSTIC_AHP_8)
 *  and select what the time of one tick in mile second
 *  and enable or disable the SysTic interrupt
 *  and enable or disable the SysTic count
 */
void SysTic_voidinit(void);

/* this function to make the SysTic to start the counting */
void SysTic_voidenable_count(void);

/* this function to make the SysTic to stop the counting */
void SysTic_voiddisable_count(void);

/* this function to enable the interrupt of the SysTic */
void SysTic_voidenable_interrupt(void);

/*  this function to disable the interrupt of the SysTic */
void SysTic_voiddisable_interrupt(void);

/* this function take time in mile second
 * and make hold for the processor(delay) by this time
 * Maximum is 8388ms
 * */
ES_t SysTic_enum_delay_ms(u16 copy_u16delay_time);

/* this function take time in mile second
 * to make it the time of the tic
 * Maximum is 8388ms
 *  */
ES_t SysTic_enum_one_tick_time_ms(u16 copy_u16one_tick_time);

/* this function take pointer to function that will be pushed to ISR of SysTic
 * and take time in mile second for tic time
 * Maximum is 8388ms
 *  */
ES_t SysTic_enumcallback_and_time_tic(void(*ptr)(void), u16 copy_u16time_tic);
void SysTic_void_callback(void(*ptr)(void));

#endif /* SYSTIC_INTERFACE_H_ */
