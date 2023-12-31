/*
  =============================================================================
 * Name		:SPI_config.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
		
		
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

	

	#define  BUSY_FLAG					7
	
	#define MSP1_STATUS          MSPI_ENABLE

	#define MSPI1_CLOCK_MODE     MSPI_MODE3

	#define MSPI1_MASTER_SLAVE   MSPI_MASTER



	#define MSPI1_DATA_ORDER     MSPI_MSB_FIRST

	#define MSPI1_SS_MANAGE      HW_SLAVE_MANAGEMENT

	#define MSPI1_DATA_SIZE      MSPI_8BIT_DATA

	#define MSPI1_INT_STATUS     MSPI_INT_DISABLE




#endif //SPI_CONFIG_H
