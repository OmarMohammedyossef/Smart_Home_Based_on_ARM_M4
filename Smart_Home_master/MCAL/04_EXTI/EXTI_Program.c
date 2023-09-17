/*
  =============================================================================
 * Name		:EXTI_Program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
#include "../../LIB/STD_datatypes.h"
#include "../../LIB/state_errors.h"
#include "../GPIO_DRIVER/GPIO_interface.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"

/* This array contain the Call back functions to pass it to the ISR */
static void (*pGlobalCallBackFunctions[7])(void) = {Null};

Error_t EXTI_SetEXTIPort(u8 Interrupt_Source, u8 GPIOPort)
{
    Error_t kErrorState = NoError;
    if(Interrupt_Source > EXTI_LINE15){
        kErrorState = ParameterError;
    }else{
        switch (GPIOPort)
        {
            case GPIOA:
                /* Clear the 4 bit of the Interrupt_Source before modifying them   */
                SYSCFG_REG->EXTICR[Interrupt_Source/4] &= ~((u32)EXTI_GPIOx_MASK << (Interrupt_Source%4)*4 );
                /* Select the EXTIx source [GPIOA , GPIOB ,GPIOC] */
                SYSCFG_REG->EXTICR[Interrupt_Source/4] |= ~((u32)EXTI_GPIOA << (Interrupt_Source%4)*4 );
                break;
            case GPIOB:
                SYSCFG_REG->EXTICR[Interrupt_Source/4] &= ~((u32)EXTI_GPIOx_MASK << (Interrupt_Source%4)*4 );
                SYSCFG_REG->EXTICR[Interrupt_Source/4] |= ~((u32)EXTI_GPIOB << (Interrupt_Source%4)*4 );
                break;    
            case GPIOC:
                SYSCFG_REG->EXTICR[Interrupt_Source/4] &= ~((u32)EXTI_GPIOx_MASK << (Interrupt_Source%4)*4 );
                SYSCFG_REG->EXTICR[Interrupt_Source/4] |= ~((u32)EXTI_GPIOC << (Interrupt_Source%4)*4 );
                break;
            default:
                kErrorState = ParameterError;
                break;
        }
    }
    return kErrorState;
}


Error_t EXTI_InterruptMask(u8 Interrupt_Source)
{
    Error_t kErrorState = NoError ;
    if(Interrupt_Source > EXTI_LINE15){
        kErrorState = ParameterError;
    }else{
        
        clear_bit(EXTI_REG->IMR , Interrupt_Source);
    }
    return kErrorState;    
}


Error_t EXTI_InterruptUnMask(u8 Interrupt_Source)
{
    Error_t kErrorState = NoError ;
    if(Interrupt_Source > EXTI_LINE15){
        kErrorState = ParameterError;
    }else{
        set_bit(EXTI_REG->IMR , Interrupt_Source);
    }
    return kErrorState;    
}

Error_t EXTI_ClearPendingFlag(u8 Interrupt_Source)
{
    Error_t kErrorState = NoError ;
    if(Interrupt_Source > EXTI_LINE15){
        kErrorState = ParameterError;
    }else{
        
        set_bit(EXTI_REG->PR , Interrupt_Source);
    }
    return kErrorState;      
}

Error_t EXTI_SetSenseControl(u8 Interrupt_Source , u8 kSenseControl)
{
    Error_t kErrorState = NoError ;
    if(Interrupt_Source > EXTI_LINE15){
        kErrorState = ParameterError;
    }else{

        switch(kSenseControl){
            case EXTI_RISING_EDGE:
                set_bit(EXTI_REG->RTSR , Interrupt_Source);
                break;

            case EXTI_FALLING_EDGE:
                set_bit(EXTI_REG->FTSR , Interrupt_Source);
                break;

            case EXTI_ON_CHANGE:
                set_bit(EXTI_REG->RTSR , Interrupt_Source);
                set_bit(EXTI_REG->FTSR , Interrupt_Source);
                break;

            default:
                kErrorState = ParameterError;
                break;        
        }
    }
    return kErrorState;    
}


Error_t EXTI_SetCallBackFunction(u8 Interrupt_Source , void (*pCallBackFun)(void))
{
    Error_t kErrorState = NoError ;
    if(Interrupt_Source > EXTI_LINE15){
        kErrorState = ParameterError;
    }else{

        if(Interrupt_Source >= EXTI_LINE5 && Interrupt_Source <= EXTI_LINE9){
            pGlobalCallBackFunctions[EXTI_LINE5_9] = pCallBackFun;

        }else if(Interrupt_Source >= EXTI_LINE10 && Interrupt_Source <= EXTI_LINE15){
            pGlobalCallBackFunctions[EXTI_LINE10_15] = pCallBackFun;
            
        }else {
            pGlobalCallBackFunctions[Interrupt_Source] = pCallBackFun;
        }
    }
    return kErrorState;     
}

/* EXTI ISR Functions Implementation  */
/* NOTE : ISR for EXTI9_5 and EXTI15_10 are not implemented yet */


void EXTI0_IRQHandler(void)
{
    /* Clear pending flag to ensure that the same ISR won't execute again */
    set_bit(EXTI_REG->PR , EXTI_LINE0);

    if ( pGlobalCallBackFunctions[EXTI_LINE0] != Null){
        pGlobalCallBackFunctions[EXTI_LINE0]();
    }else {
        /* Do Nothing */
    }
}

void EXTI1_IRQHandler(void)
{
    set_bit(EXTI_REG->PR , EXTI_LINE1);

    if ( pGlobalCallBackFunctions[EXTI_LINE1] != Null){
        pGlobalCallBackFunctions[EXTI_LINE1]();
    }else {
        /* Do Nothing */
    }
}


void EXTI2_IRQHandler(void)
{
    set_bit(EXTI_REG->PR , EXTI_LINE2);

    if ( pGlobalCallBackFunctions[EXTI_LINE2] != Null){
        pGlobalCallBackFunctions[EXTI_LINE2]();
    }else {
        /* Do Nothing */
    }
}

void EXTI3_IRQHandler(void)
{
    set_bit(EXTI_REG->PR , EXTI_LINE3);

    if ( pGlobalCallBackFunctions[EXTI_LINE3] != Null){
        pGlobalCallBackFunctions[EXTI_LINE3]();
    }else {
        /* Do Nothing */
    }
}

void EXTI4_IRQHandler(void)
{
    set_bit(EXTI_REG->PR , EXTI_LINE4);

    if ( pGlobalCallBackFunctions[EXTI_LINE4] != Null){
        pGlobalCallBackFunctions[EXTI_LINE4]();
    }else {
        /* Do Nothing */
    }
}

void EXTI9_5_IRQHandler(void)
{

}

void EXTI15_10_IRQHandler(void)
{

}





