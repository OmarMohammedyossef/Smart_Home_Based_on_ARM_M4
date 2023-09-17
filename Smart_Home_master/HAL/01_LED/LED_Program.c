/*
  =============================================================================
 * Name		:LED_Program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */


#include "../../LIB/STD_datatypes.h"
#include "../../LIB/state_errors.h"
#include "../../MCAL/GPIO_DRIVER/GPIO_interface.h"
#include "LED_Interface.h"

void LED_Init(LED_t LedConfigration)
{
    MGPIO_enumselect_pin_mode(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_OUTPUT, GPIO_PULL_DOWN );
    MGPIO_enumselect_output_type(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_PUSH_PULL, GPIO_HIGH_SPEED);
}

void LED_ON(LED_t LedConfigration)
{
    if(LED_ACTIVE_HIGH ==LedConfigration.Active_Status)
    {
       MGPIO_enumset_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_HIGH);
    }else if(LED_ACTIVE_LOW ==LedConfigration.Active_Status)
    {
       MGPIO_enumset_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_LOW);
    }else{
    }
}


void LED_OFF(LED_t LedConfigration)
{

    if(LED_ACTIVE_HIGH ==LedConfigration.Active_Status)
    {
       MGPIO_enumset_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_LOW);
    }else if(LED_ACTIVE_LOW ==LedConfigration.Active_Status)
    {
        MGPIO_enumset_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_HIGH);
    }else{

    }

}

void LED_Toggle(LED_t LedConfigration)
{

    u8 Pin_Value = GPIO_LOW;
    MGPIO_enumget_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , &Pin_Value);
    if ( Pin_Value == GPIO_HIGH){
    	MGPIO_enumset_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_LOW);
    }else if(Pin_Value == GPIO_LOW){
    	MGPIO_enumset_pin_value(LedConfigration.PortNumber , LedConfigration.PinNumber , GPIO_HIGH);
    }

}

