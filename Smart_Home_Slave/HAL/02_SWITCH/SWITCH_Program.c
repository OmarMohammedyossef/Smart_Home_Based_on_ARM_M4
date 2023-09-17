/*
 =============================================================================
 * Name		    :SWITCH_Program.c
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#include "../../LIB/STD_datatypes.h"
#include "../../LIB/Delay_interface.h"
#include "../../MCAL/GPIO_DRIVER/GPIO_interface.h"
#include"SWITCH_Interface.h"
#define _XTAL_FREQ 8000000L 

void SWITCH_Init(SWITCH_t *Switch_Config )
{

    MGPIO_enumselect_pin_mode(Switch_Config->SW_PortNum , Switch_Config->SW_PinNum , GPIO_INPUT, GPIO_FLOATING );
}

void SWITCH_GetPressed(SWITCH_t *Switch_Config , SWITCH_STATE_t *pPressedValue)
{

    
    u8 loc_PinVal = GPIO_HIGH;
    MGPIO_enumget_pin_value(Switch_Config->SW_PortNum , Switch_Config->SW_PinNum , &loc_PinVal);

    if(Switch_Config->SW_State == SW_PULL_UP)
    {
        if(loc_PinVal == GPIO_HIGH)
        {
            *pPressedValue = SW_NOT_PRESSED ; 

        }else if (loc_PinVal == GPIO_LOW)
        {
            Delay_vMsIn16MHz(30);
        	MGPIO_enumget_pin_value(Switch_Config->SW_PortNum , Switch_Config->SW_PinNum , &loc_PinVal);
        	if (loc_PinVal == GPIO_LOW)
        	{
        		*pPressedValue = SW_PRESSED ;
        	}

        }
    }
    else if(Switch_Config->SW_State == SW_PULL_DOWN)
    {

        if(loc_PinVal == GPIO_HIGH)
        {
            *pPressedValue = SW_PRESSED ; 

        }else if (loc_PinVal == GPIO_LOW)
        {
            *pPressedValue = SW_NOT_PRESSED ; 
        }
    }

}


