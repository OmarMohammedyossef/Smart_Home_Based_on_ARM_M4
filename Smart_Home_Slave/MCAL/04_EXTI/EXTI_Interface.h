/*
 =============================================================================
 * Name		    :EXTI_Interface.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */

#ifndef MCAL_EXTI_INTERFACE_H_
#define MCAL_EXTI_INTERFACE_H_
/**
 * @brief  Function Provided in this file : 
 * Error_t EXTI_SetEXTIPort(u8 kGPIOPort, u8 Interrupt_Source)
 * Error_t EXTI_InterruptMask(u8 Interrupt_Source)
 * Error_t EXTI_InterruptUnMask(u8 Interrupt_Source)
 * Error_t EXTI_ClearPendingFlag(u8 Interrupt_Source)
 * Error_t EXTI_SetSenseControl(u8 Interrupt_Source , u8 kSenseControl)
 * Error_t EXTI_SetCallBackFunction(u8 Interrupt_Source , void (*pCallBackFun)(void))
 * 
 */

#define EXTI_LINE0      (0)
#define EXTI_LINE1      (1)
#define EXTI_LINE2      (2)
#define EXTI_LINE3      (3)
#define EXTI_LINE4      (4)
#define EXTI_LINE5      (5)
#define EXTI_LINE6      (6)
#define EXTI_LINE7      (7)
#define EXTI_LINE8      (8)
#define EXTI_LINE9      (9)
#define EXTI_LINE10     (10)
#define EXTI_LINE11     (11)
#define EXTI_LINE12     (12)
#define EXTI_LINE13     (13)
#define EXTI_LINE14     (14)
#define EXTI_LINE15     (15)

#define EXTI_LINE5_9    (5)
#define EXTI_LINE10_15  (6)

#define EXTI_RISING_EDGE  (0)
#define EXTI_FALLING_EDGE (1)
#define EXTI_ON_CHANGE    (3) 

/**
 * @brief   : This function is sued to map EXTI to a port
 * 
 * @param kGPIOPort OPTIONS:
 *                      kGPIOA
 *                      kGPIOB
 *                      kGPIOC
 * 
 * @param Interrupt_Source  OPTIONS:
 *                              [ EXTI_LINE0 , EXTI_LINE1 ... EXTI_LINE15 ]
 *                               
 * 
 * @return Error_t : NoError -->> function Parameter is correct
 *                   ParameterError --> Error in function parameter 
 */
Error_t EXTI_SetEXTIPort(u8 Interrupt_Source, u8 kGPIOPort);


/**
 * @brief   : This function is used to mask an EXTI line
 * 
 * @param Interrupt_Source  OPTIONS:
 *                              EXTI_LINE0
 *                              EXTI_LINE1
 *                              EXTI_LINE2
 *                              EXTI_LINE3
 *                              EXTI_LINE4
 *                              EXTI_LINE5_9
 *                              EXTI_LINE10_15    
 * @return Error_t : NoError -->> function Parameter is correct
 *                   ParameterError --> Error in function parameter                     
 */
Error_t EXTI_InterruptMask(u8 Interrupt_Source);

/**
 * @brief   : This function is used to unmask mask an EXTI line
 * 
 * @param Interrupt_Source  OPTIONS:
 *                              EXTI_LINE0
 *                              EXTI_LINE1
 *                              EXTI_LINE2
 *                              EXTI_LINE3
 *                              EXTI_LINE4
 *                              EXTI_LINE5_9
 *                              EXTI_LINE10_15
 * @return Error_t : NoError -->> function Parameter is correct
 *                   ParameterError --> Error in function parameter                        
 */
Error_t EXTI_InterruptUnMask(u8 Interrupt_Source);


/**
 * @brief   : This function is used to clear Pending flag of an EXTI line
 * 
 * @param Interrupt_Source  OPTIONS:
 *                              EXTI_LINE0
 *                              EXTI_LINE1
 *                              EXTI_LINE2
 *                              EXTI_LINE3
 *                              EXTI_LINE4
 *                              EXTI_LINE5_9
 *                              EXTI_LINE10_15
 * 
 * @return Error_t : NoError -->> function Parameter is correct
 *                   ParameterError --> Error in function parameter 
 */
Error_t EXTI_ClearPendingFlag(u8 Interrupt_Source);
/**
 * @brief   : 
 * 
 * @param Interrupt_Source  OPTIONS:
 *                              EXTI_LINE0
 *                              EXTI_LINE1
 *                              EXTI_LINE2
 *                              EXTI_LINE3
 *                              EXTI_LINE4
 *                              EXTI_LINE5_9
 *                              EXTI_LINE10_15
 *  
 * @param kSenseControl  OPTIONS:
 *                           EXTI_RISING_EDGE
 *                           EXTI_FALLING_EDGE
 *                           EXTI_ON_CHANGE
 * 
 * @return Error_t : NoError -->> function Parameter is correct
 *                   ParameterError --> Error in function parameter                        
 */
 
Error_t EXTI_SetSenseControl(u8 Interrupt_Source , u8 kSenseControl);

/**
 * @brief   : This function is sued to set call back function(ISR handler )of an EXTI  
 * 
 * @param Interrupt_Source  OPTIONS:
 *                              EXTI_LINE0
 *                              EXTI_LINE1
 *                              EXTI_LINE2
 *                              EXTI_LINE3
 *                              EXTI_LINE4
 *                              EXTI_LINE5_9
 *                              EXTI_LINE10_15
 * 
 * @param pCallBackFun : pointer to a void function that will  be executed if the EXTI occurs 
 * @return Error_t 
 */
Error_t EXTI_SetCallBackFunction(u8 Interrupt_Source , void (*pvCallBackFun)(void));

#endif /* MCAL_EXTI_INTERFACE_H_ */
