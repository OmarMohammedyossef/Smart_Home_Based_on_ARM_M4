/*
  =============================================================================
 * Name		    :ADC_private.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */
/*
 * ***************************************************************
 *  @note      This program is distributed in the hope  that it
 * 	           will be useful,but WITHOUT ANY WARRANTY; without
 *	           even the implied warranty of  MERCHANTABILITY or
 *	           FITNESS FOR A PARTICULAR PURPOSE.
 *
 * ***************************************************************
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
#define ADC1_BASE_ADDRESS         0x40012000
//#define ADC2_BASE_ADDRESS       0x40012800
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct 
{
    volatile u32 SR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMPR1;
    volatile u32 SMPR2;
    volatile u32 JOFR1;
    volatile u32 JOFR2;
    volatile u32 JOFR3;
    volatile u32 JOFR4;
    volatile u32 HTR;
    volatile u32 LTR;
    volatile u32 SQR1;
    volatile u32 SQR2;
    volatile u32 SQR3;
    volatile u32 JSQR;
    volatile u32 JDR1;
    volatile u32 JDR2;
    volatile u32 JDR3;
    volatile u32 JDR4;
    volatile u32 DR;
}sADC_t;

//sADC_t * ADCx[2]=
//{
//	(( sADC_t*)ADC1_BASE_ADDRESS),
//	(( sADC_t*)ADC2_BASE_ADDRESS),
//};

#define ADC_1 ( ((volatile sADC_t*) ADC1_BASE_ADDRESS) )
/******************************************************************************
* Variables
*******************************************************************************/


#endif /*File_H_*/

/*** End of File **************************************************************/
