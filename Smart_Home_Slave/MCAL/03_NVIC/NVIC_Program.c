/*
 =============================================================================
 * Name		    :NVIC_Program.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#include "../../LIB/STD_datatypes.h"
#include "../../LIB/state_errors.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"

static u8 Global_GroupingConfig  = _0GROUP_16PRIORITY ;
void NVIC_vInterruptEnable(u8 kInterruptNum)
{
    set_bit( NVIC_REG->ISER[kInterruptNum/(u8)32] , kInterruptNum%(u8)32 );
}

void NVIC_vInterruptDisable(u8 kInterruptNum)
{
    clear_bit( NVIC_REG->ISER[kInterruptNum/(u8)32] , kInterruptNum%(u8)32 );
}

void NVIC_vSetPendingFlag(u8 kInterruptNum)
{
    set_bit(NVIC_REG->ISPR[kInterruptNum/(u8)32] , kInterruptNum%(u8)32 );
}

void NVIC_vClearPendingFlag(u8 kInterruptNum)
{
    set_bit( NVIC_REG->ICPR[kInterruptNum/(u8)32] , kInterruptNum%(u8)32 );
}

u8 NVIC_u8GetInterruptPendingState(u8 kInterruptNum)
{
    u8 Ret_InterruptState = 0;
    Ret_InterruptState = read_bit(NVIC_REG->ISPR[kInterruptNum/(u8)32] , kInterruptNum%(u8)32 );
    return Ret_InterruptState; 
}

u8 NVIC_u8GetInterruptActiveState(u8 kInterruptNum)
{
    u8 Ret_InterruptState = 0;
    Ret_InterruptState = read_bit(NVIC_REG->IABR[kInterruptNum/(u8)32] , kInterruptNum%(u8)32 );
    return Ret_InterruptState; 
}   

void NVIC_SetPriorityGrouping(u8 kGroupingConfiguration)
{
    u32 TempRegValue = 0;
    Global_GroupingConfig = kGroupingConfiguration;
    /* TempRegValue store the configuration of the Grouping info + Key to access AIRCR  */
    TempRegValue = ((u32)kGroupingConfiguration >> 8 ) | ((u32)VECTKEY<<16);
    
    /* Mask to the 3 bit of Interrupt priority grouping field before adding new configuration */
    AIRCR &= ~(PRIORITY_GROUP_MASK);
    AIRCR =  TempRegValue; 
}

void NVIC_SetInterruptPriority(u8 kInterruptNum , u8 kGroupId, u8 kSubPriorityId)
{
    switch (Global_GroupingConfig)
    {
        case _16GROUP_0PRIORITY :
            NVIC_REG->IPR[kInterruptNum] = (kGroupId<<4);
            break;
        
        case _8GROUP_2PRIORITY  :
            NVIC_REG->IPR[kInterruptNum] = (kGroupId<<5) | ( (kSubPriorityId&0b1) <<4);
            break;
        
        case _4GROUP_4PRIORITY  :
            NVIC_REG->IPR[kInterruptNum] = (kGroupId<<6) | ( (kSubPriorityId&0b11) <<4);
            break;

        case _2GROUP_8PRIORITY  :
            NVIC_REG->IPR[kInterruptNum] = (kGroupId<<7) | ( (kSubPriorityId&0b111) <<4);
            break;
        
        case _0GROUP_16PRIORITY :
            NVIC_REG->IPR[kInterruptNum] =  (kSubPriorityId<<4);
            break;

        default:
            /* do nothing */
            break;    
    }
    
}



