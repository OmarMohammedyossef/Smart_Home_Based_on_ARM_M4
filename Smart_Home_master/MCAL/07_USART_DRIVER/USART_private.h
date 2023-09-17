/*
  =============================================================================
 * Name		:UART_private.h
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
/*
 *  Description: This file contain on names of USART registers
 *
 *  and some definitions of USART bits and definitions for the UART_configuration file
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/* base address of USART1 */
#define   USART_BASE_ADDRESS                      0x40011000

/* registers names of USART1 peripheral */
#define   USART_SR                                *((volatile u32*)(USART_BASE_ADDRESS+0x00))
#define   USART_DR                                *((volatile u32*)(USART_BASE_ADDRESS+0x04))
#define   USART_BRR                               *((volatile u32*)(USART_BASE_ADDRESS+0x08))
#define   USART_CR1                               *((volatile u32*)(USART_BASE_ADDRESS+0x0C))
#define   USART_CR2                               *((volatile u32*)(USART_BASE_ADDRESS+0x10))
#define   USART_CR3                               *((volatile u32*)(USART_BASE_ADDRESS+0x14))
#define   USART_GTPR                              *((volatile u32*)(USART_BASE_ADDRESS+0x18))

/* some definitions for bits of USART peripheral */
#define TXE                                       7
#define TC                                        6
#define RXNE                                      5
#define ORE                                       3
#define FE                                        1
#define PE                                        0
#define OVER                                      15
#define UE                                        13
#define DATA                                      12
#define PCE                                       10
#define PS                                        9
#define PEIE                                      8
#define TXEIE                                     7
#define TCIE                                      6
#define RXNEIE                                    5
#define TE                                        3
#define RE                                        2
#define STOP0                                     12
#define DMAT                                      7
#define DMAR                                      6
#define HDSEL                                     3
#define PSC0                                      0
/****************************************************/
#define no_parity                                 0
#define even_parity                               1
#define odd_parity                                2
#define one_stop_bit                              0
#define two_stop_bit                              2
#define eight_data_bits                           8
#define nine_data_bits                            9
#define reciever                                  0
#define transmitter                               1
#define reciever_and_transmitter                  2
#define disable                                   0
#define enable                                    1

#endif /* USART_PRIVATE_H_ */
