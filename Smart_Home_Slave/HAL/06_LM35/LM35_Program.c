/*
 =============================================================================
 * Name		    :LM35_Program.c
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#include "../../LIB/STD_datatypes.h"
#include "../../LIB/state_errors.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "LM35_Interface.h"



Error_t LM35_GetTemp(u8 LM35_ChannelNumber , u8 *pTemp){
    Error_t Ret_ErrorState = NoError ; 
    u16 DigitalVal ;
    u16 AnalogVal  ;
    DigitalVal = ADC_u16Read(LM35_ChannelNumber);

    *pTemp = DigitalVal;
    // 10mv --> 1 C
    return Ret_ErrorState;
}
