/*
 =============================================================================
 * Name		    :LED_Interface.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */
#ifndef LED_INTERFACE_H
#define	LED_INTERFACE_H

#include "../../LIB/Delay_interface.h"
#include "../../LIB/state_errors.h"

#define LED_ACTIVE_HIGH 1
#define LED_ACTIVE_LOW 0

typedef struct
{
    u8  PortNumber;
    u8  PinNumber ;
    u8  Active_Status ;
}LED_t;

/**
 * @brief                   :This function used to  initiate led and sets the configration of it
 *
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 *
 * @note                    :You mast call this function before you start using the Led
 */
void LED_Init      (LED_t LedConfigration);

/**
 * @brief                   :This function used turn  the led on
 *
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 */
void LED_ON        (LED_t LedConfigration);

/**
 * @brief                   :This function used turn  the led off
 *
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 */
void LED_OFF       (LED_t LedConfigration);


/**
 * @brief                   :This function used toggle the Led Statuss
 *
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 */
void LED_Toggle    (LED_t LedConfigration);

#endif /* LED_INTERFACE_H */
