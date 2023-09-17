/*
 =============================================================================
 * Name		    :DCMOTOR_program.c
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#include "../../LIB/STD_datatypes.h"
#include "../../MCAL/GPIO_DRIVER/GPIO_interface.h"
#include "DCMOTOR_Interface.h"

void DC_MOTOR_INIT(DC_MOTOR_t *pMotor_Config)
{

    if(pMotor_Config != Null){
    	MGPIO_enumselect_pin_mode(pMotor_Config->PortNumber   , pMotor_Config->Pin1Number , GPIO_OUTPUT, GPIO_PULL_DOWN );
    	MGPIO_enumselect_output_type(pMotor_Config->PortNumber, pMotor_Config->Pin1Number , GPIO_PUSH_PULL, GPIO_HIGH_SPEED);
    	MGPIO_enumselect_pin_mode(pMotor_Config->PortNumber   , pMotor_Config->Pin2Number , GPIO_OUTPUT, GPIO_PULL_DOWN );
    	MGPIO_enumselect_output_type(pMotor_Config->PortNumber, pMotor_Config->Pin2Number , GPIO_PUSH_PULL, GPIO_HIGH_SPEED);
    }else{

    }

}
void DC_MOTOR_ON_CW(DC_MOTOR_t *pMotor_Config)
{

    if(pMotor_Config != Null){
         MGPIO_enumset_pin_value(pMotor_Config->PortNumber , pMotor_Config->Pin1Number ,  GPIO_HIGH);
         MGPIO_enumset_pin_value(pMotor_Config->PortNumber , pMotor_Config->Pin2Number ,  GPIO_LOW );
        
    }else{

    }

}
void DC_MOTOR_ON_CCW(DC_MOTOR_t *pMotor_Config)
{

    if(pMotor_Config != Null){
         MGPIO_enumset_pin_value(pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_LOW);
         MGPIO_enumset_pin_value(pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_HIGH );
        
    }else{

    }

}
void DC_MOTOR_OFF(DC_MOTOR_t *pMotor_Config)
{

    if(pMotor_Config != Null){
         MGPIO_enumset_pin_value(pMotor_Config->PortNumber , pMotor_Config->Pin1Number , GPIO_LOW );
         MGPIO_enumset_pin_value(pMotor_Config->PortNumber , pMotor_Config->Pin2Number , GPIO_LOW );
        
    }else{

    }

}
