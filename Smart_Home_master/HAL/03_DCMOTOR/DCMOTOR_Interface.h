/*
  =============================================================================
 * Name		:DCMOTOR_Interface.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */


#ifndef DCMOTOR_INTERFACE_H
#define	DCMOTOR_INTERFACE_H

typedef struct {
    u8 PortNumber ;
    u8 Pin1Number ;
    u8 Pin2Number ;

}DC_MOTOR_t;

void DC_MOTOR_INIT(DC_MOTOR_t *pMotor_Config);
void DC_MOTOR_ON_CW(DC_MOTOR_t *pMotor_Config);
void DC_MOTOR_ON_CCW(DC_MOTOR_t *pMotor_Config);
void DC_MOTOR_OFF(DC_MOTOR_t *pMotor_Config);

#endif	/* DCMOTOR_INTERFACE_H */

