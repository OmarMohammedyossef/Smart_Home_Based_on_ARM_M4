/*
  =============================================================================
 * Name		:SysTic_PROGRAM.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
/*
 *  Description : this file contain on implementation for APIs of system tick driver
 *   1-void SysTic_voidinit(void);
 *   2-void SysTic_void_delay_ms(u16 copy_u16delay_time);
 *   3-void SysTic_voidone_tick_time_ms(u16 copy_u16one_tick_time);
 *   4-void SysTic_voidenable_count(void);
 *   5-void SysTic_voiddisable_count(void);
 *   6-void SysTic_voidenable_interrupt(void);
 *   7-void SysTic_voiddisable_interrupt(void);
 */

#include "../../LIB/STD_datatypes.h"
#include "../../LIB/state_errors.h"
#include "SysTic_PRIVATE.h"
#include "SysTic_CONFIGURATION.h"
#include "SysTic_INTERFACE.h"

void(*Sys_prt)(void) = Null;
u16 Max_Time=0;

/* this function select System Tick clock source
 *  which be (SYSTIC_AHP or SYSTIC_AHP_8)
 *  and select what the time of one tick in mile second
 *  and enable or disable the SysTic interrupt
 *  and enable or disable the SysTic count
 *  and calculate the maximum time of one tic
 */
void SysTic_voidinit(void){

	    /* select the clock source of the SysTic
	     * and load the SYSTIC_LOAD register at the initial value
	     * and calculate the maximum time of one tic
	     * */
#if    SYSTIC_CLOCK == SYSTIC_AHB_8
	     clear_bit(SYSTIC_CTRL,CLKSOURCE);
	     SYSTIC_LOAD = (u32)(((f32)SYSTIC_TIME_TIC)/((((f32)8)/((f32)SYSTEM_CLOCK))*((f32)1000)));
	     Max_Time = (u16)(((f32)16777215)*((((f32)8)/((f32)SYSTEM_CLOCK))*((f32)1000)));
#else
	     set_bit(SYSTIC_CTRL,CLKSOURCE);
	     SYSTIC_LOAD = (u32)(((f32)SYSTIC_TIME_TIC)/((((f32)1)/((f32)SYSTEM_CLOCK))*((f32)1000)));
	     Max_Time = (u16)(((f32)16777215)*((((f32)1)/((f32)SYSTEM_CLOCK))*((f32)1000)));
#endif

	     /* enable or disable the interrupt of the SysTic */
#if     SYSTIC_INTERRUPT_ENABLE == oFF
	     clear_bit(SYSTIC_CTRL,TICKINT);
#else
	     set_bit(SYSTIC_CTRL,TICKINT);
#endif

	     /* enable or disable the SysTic */
#if     SYSTIC_COUNT_ENABLE == OFF
	     clear_bit(SYSTIC_CTRL,ENABLE);
#else
	     set_bit(SYSTIC_CTRL,ENABLE);
#endif

}

void SysTic_voidenable_count(void){

	set_bit(SYSTIC_CTRL,ENABLE);
}
void SysTic_voiddisable_count(void){

	clear_bit(SYSTIC_CTRL,ENABLE);
}
void SysTic_voidenable_interrupt(void){

	set_bit(SYSTIC_CTRL,TICKINT);
}
void SysTic_voiddisable_interrupt(void){

	clear_bit(SYSTIC_CTRL,TICKINT);
}

ES_t SysTic_enum_delay_ms(u16 copy_u16delay_time){

	ES_t state_error = ES_NOK;
	if(copy_u16delay_time<=Max_Time){
		u32 val = SYSTIC_LOAD;  /* copy the value of SYSTIC_LOAD to val */
	clear_bit(SYSTIC_CTRL,ENABLE); /* disable the count */
	clear_bit(SYSTIC_CTRL,TICKINT); /* disable the interrupt */
	SYSTIC_LOAD = (u32)(((f32)copy_u16delay_time)/((((f32)8)/((f32)SYSTEM_CLOCK))*((f32)1000)));
	set_bit(SYSTIC_CTRL,ENABLE); /* enable the count */
	SYSTIC_LOAD = val; /* reload the value of the val to SYSTIC_LOAD */
	while(!(read_bit(SYSTIC_CTRL,COUNTFLAG))); /* wait until the flag is rising */
	SYSTIC_VAL = 0; /* clear the flag */
	//set_bit(SYSTIC_CTRL,TICKINT);
	state_error = ES_OK;
	}
	else{
		state_error = ES_OUT_OF_RANGE;
	}

	return state_error;
}
ES_t SysTic_enum_one_tick_time_ms(u16 copy_u16one_tick_time){

	ES_t state_error = ES_NOK;
		if(copy_u16one_tick_time<=Max_Time){
			clear_bit(SYSTIC_CTRL,ENABLE);
			SYSTIC_LOAD = (u32)(((f32)copy_u16one_tick_time)/((((f32)8)/((f32)SYSTEM_CLOCK))*((f32)1000)));
			state_error = ES_OK;
		}
		else{
			state_error = ES_OUT_OF_RANGE;
		}

		return state_error;

}

ES_t SysTic_enumcallback_and_time_tic(void(*ptr)(void), u16 copy_u16time_tic){
	Max_Time = (u16)(((f32)16777215)*((((f32)8)/((f32)SYSTEM_CLOCK))*((f32)1000)));
	ES_t state_error = ES_NOK;
		if(copy_u16time_tic<=Max_Time){
			if(ptr!=Null){
		    clear_bit(SYSTIC_CTRL,ENABLE);  /* disable the count */
		 //    clear_bit(SYSTIC_CTRL,TICKINT); /* disable the interrupt */
		    Sys_prt = ptr;  /* push the app function to the ISR of the SysTic */
		    SYSTIC_LOAD = (u32)(((f32)copy_u16time_tic)/((((f32)8)/((f32)SYSTEM_CLOCK))*((f32)1000)));
		    set_bit(SYSTIC_CTRL,TICKINT);  /* enable the interrupt */
		    set_bit(SYSTIC_CTRL,ENABLE);   /* enable the count */
		    state_error = ES_OK;
			}
			else{
				state_error = ES_NULL_POINTER;
			}

		}
		else{
			state_error = ES_OUT_OF_RANGE;
		}

		return state_error;
}
void SysTic_void_callback(void(*ptr)(void)){
	Sys_prt = ptr;
}
void SysTick_Handler (void){
	SYSTIC_VAL = 0; /* clear the flag */
    if(Sys_prt != Null){
		Sys_prt();
	}
	else{

	}

}


