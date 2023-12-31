/*
  =============================================================================
 * Name		:SPI_interface.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
	
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI_VidInit(void);
void SPI_voidInitHardCode(void);
 //	Function Synh = Wait Until Job End 
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit  , u8 *Copy_DataToReceive); // Send & Receive  @ Same Time (It is full doublex ) 
 // Function Asynch = Must have call back here must be u8 becuse it will send as return data  
// void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit  , void (*CallBack)(u8));

 void MSPI1_voidInitForTFT(void);

#endif //SPI_INTERFACE_H
