/*
 =============================================================================
 * Name		    :DELAY_interface.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */
 
/*========================================================================================
========================   guard of file will call on time in .c  ========================
========================================================================================*/ 




#ifndef DELAY_INTERFACE_H
#define DELAY_INTERFACE_H
	 
#include "STD_datatypes.h"


/*========================================================================================
 *                      Functions Prototypes                                   *
========================================================================================*/


  /* =============  Function To Delay By Milliseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_vMsIn16MHz(u16 copy_u16CountNum);

 /* =============  Function To Delay By Microseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_vUsIn16MHzint (u16 copy_u16CountNum);






#endif //DELAY_INTERFACE_H
