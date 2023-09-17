/*
  =============================================================================
 * Name		:SPI_program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */

/************** INCLUDE LIB **************/
#include "../../LIB/STD_datatypes.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"
/*****************************************/
 
 
 void MSPI_VidInit ( void ){

	 #if   MSP1_STATUS == MSPI_ENABLE

	 #if		MSPI1_CLOCK_MODE == MSPI_MODE0

	 clear_bit( MSPI1 -> CR1 , 0 ); clear_bit( MSPI1 -> CR1 , 1 );

	 #elif	MSPI1_CLOCK_MODE == MSPI_MODE1

	 set_bit( MSPI1 -> CR1 , 0 ); clear_bit( MSPI1 -> CR1 , 1 );

	 #elif	MSPI1_CLOCK_MODE == MSPI_MODE2

	 clear_bit( MSPI1 -> CR1 , 0 ); set_bit( MSPI1 -> CR1 , 1 );

	 #elif	MSPI1_CLOCK_MODE == MSPI_MODE3

	 set_bit( MSPI1 -> CR1 , 0 ); set_bit( MSPI1 -> CR1 , 1 );

	 #endif

	 #if    MSPI1_MASTER_SLAVE == MSPI_MASTER

	 set_bit( MSPI1 -> CR1 , 2 );

	 #elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE

	 clear_bit( MSPI1 -> CR1 , 2 );

	 #endif

	 #if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST

	 clear_bit( MSPI1 -> CR1 , 7 );

	 #elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST

	 set_bit( MSPI1 -> CR1 , 7 );

	 #endif

	 #if   MSPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT

	 clear_bit( MSPI1 -> CR1 , 9 );

	 #elif MSPI1_SS_MANAGEb == SW_SLAVE_MANAGEMENT

	 set_bit( MSPI1 -> CR1 , 9 );

	 #endif

	 #if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA

	 clear_bit( MSPI1 -> CR1 , 11 );

	 #elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA

	 set_bit( MSPI1 -> CR1 , 11 );

	 #endif

	 #if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

	 MSPI1 -> CR2 = 0 ;

	 #elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

	 set_bit( MSPI1 -> CR2 , 7 );

	 #elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

	 set_bit( MSPI1 -> CR2 , 6 );

	 #endif

	 MSPI1 -> CR1 &= 0xFFC7 ;


	 set_bit( MSPI1 -> CR1 , 6 );

	 #elif MSP1_STATUS == MSPI_DISABLE
	 clear_bit( MSPI1 -> CR1 , 6 );
	 #endif

 }
 void SPI_voidInitHardCode(void)
 {
	 MSPI1->CR1 = 0x0347 ;
	 
 }
 
		//	Only One Slave
 void MSPI1_voidSendReceiveSynch(u8 Copt_u8DataToTransmit  , u8 *Copy_DataToReceive)
 {

			/* Send Data */
	 MSPI1 -> DR =Copt_u8DataToTransmit ;
			/* Wait Busy Flag */
		while(read_bit(MSPI1 ->SR , BUSY_FLAG) ==1) ;
			/* Return Recive Data */
		*Copy_DataToReceive = MSPI1 ->DR ;

 }
 void MSPI1_voidInitForTFT(void)
 {
	 /* CPOL = 1 / CPHA =1 / Prescaller = Clk/2 / SPI_EN / MSB Frist  */
	 MSPI1->CR1 = 0X0347	;
 }
