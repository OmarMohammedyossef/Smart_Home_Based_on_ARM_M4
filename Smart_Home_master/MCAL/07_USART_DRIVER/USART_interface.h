/*
  =============================================================================
 * Name		:UART_interface.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
 

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_vInit(void);
void USART_vTransmit(u8 data);
u8 USART_u8Recieve(u8* data);
void USART_vTransmit_string(u8* data);
u8 USART_u8Recieve_string(u8* data);






void usart_voidtransmit_noblock(u8 data);
u8 usart_voidrecieve_noblock(void);
u16 usart_u16get_frame(u16 data);
void usart_voidtransmit_number(u32 data);
u8 usart_u8recieve_number(u32* data);
void uart_voidtransmit_checksum(u8* data);
u8 uart_u8recieve_checksum(u8* data);





void uart_voidcallbacktransmit(void(*ptr)(void));
void uart_voidcallbackrecieve(void(*ptr)(void));
u8* uart_voidtransmitstringASC(u8* data);
u8* uart_voidrecievestringASC(void);

#endif /* USART_INTERFACE_H_ */
