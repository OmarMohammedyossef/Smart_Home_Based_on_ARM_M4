/*
  =============================================================================
 * Name		:SWITCH_Interface.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

#ifndef SWITCH_INTERFACE_H
#define	SWITCH_INTERFACE_H



typedef struct
{
	u8 SW_PortNum ;
	u8 SW_PinNum ;
	u8 SW_State ;
}SWITCH_t;


enum SWITCH_MODE
{
	SW_PULL_UP ,
	SW_PULL_DOWN 
};
typedef enum 
{

	SW_NOT_PRESSED ,
	SW_PRESSED
}SWITCH_STATE_t;
/**
 * @brief                   :This function use ti initialize the switch
 * 
 * @param  pSwitch_Config   : is a pointer that is point to --> [SWITCH_t] -->  the configeration of the switch  
 * @return void   : This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
void SWITCH_Init(SWITCH_t *pSwitch_Config );


/**
 * @brief                     : This fuiction is used to get whether  the switch is pressed or not 
 * 
 * @param pSwitch_Config      : is a pointer that is point to --> [SWITCH_t] -->  the configeration of the switch  
 * @param pPressed_Value      : Pointer to the pressed value --> which could be [SW_NOT_PRESSED or SW_PRESSED]  
 * @return void
 */
void SWITCH_GetPressed(SWITCH_t *pSwitch_Config , SWITCH_STATE_t *pPressed_Value);

#endif	/* SWITCH_INTERFACE_H */

