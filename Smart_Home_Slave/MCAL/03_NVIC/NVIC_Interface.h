/*
 =============================================================================
 * Name		    :NVIC_Interface.c
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#ifndef MCAL_NVIC_INTERFACE_H_
#define MCAL_NVIC_INTERFACE_H_


/* dont try to modify those values are fixed*/
#define _16GROUP_0PRIORITY (0b011)  
#define _8GROUP_2PRIORITY  (0b100)  
#define _4GROUP_4PRIORITY  (0b101)  
#define _2GROUP_8PRIORITY  (0b110)  
#define _0GROUP_16PRIORITY (0b111)  

/**
 * @brief : This function is used to Enable an interrupt
 * 
 * @param kInterruptNum : The Number of the interrupt (IRQn) 
 */
void NVIC_vInterruptEnable(u8 kInterruptNum);
void NVIC_vInterruptDisable(u8 kInterruptNum);

void NVIC_vSetPendingFlag(u8 kInterruptNum);
void NVIC_vClearPendingFlag(u8 kInterruptNum);


u8 NVIC_u8GetInterruptPendingState(u8 kInterruptNum);
u8 NVIC_u8GetInterruptActiveState(u8 kInterruptNum);

/**
 * @brief : This function is used to configure the number of groups and sub-priorities
 * 
 * @param kGroupingConfiguration : options:
 *                                  _16GROUP_0PRIORITY
 *                                  _8GROUP_2PRIORITY
 *                                  _4GROUP_4PRIORITY
 *                                  _2GROUP_8PRIORITY
 *                                  _0GROUP_16PRIORITY
 * @note : If you don't use this function by default number of Groups will be 0 and sub-priority will be 16  
 */
void NVIC_SetPriorityGrouping(u8 kGroupingConfiguration);

void NVIC_SetInterruptPriority(u8 kInterruptNum , u8 kGroupId, u8 kSubPriorityId);

#endif /* MCAL_NVIC_INTERFACE_H_ */
