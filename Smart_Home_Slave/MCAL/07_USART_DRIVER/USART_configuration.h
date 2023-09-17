/*
 =============================================================================
 * Name		    :UART_configuration.h
 * Author		:Omar Elshamy
 * Version      : _1_	
 * Created on	:10/9/2023
 ==============================================================================
 */
/*
 *  Description :  this file contain on configurations of UART peripheral
 *
 *  e.x : type of parity bit , number of stop bits , number of data bits
 *  , value of baud rate , job of UART and interrupts capability
 */

#ifndef USART_CONFIGURATION_H_
#define USART_CONFIGURATION_H_

/* select type of parity bit */
#define parity_type                no_parity

/* select number of stop bits */
#define number_of_stop_bits        one_stop_bit

/* select number of data bits */
#define number_of_data_bits        eight_data_bits

/* select frequency of system clock */
#define frequency                  16000000

/* select value of baud rate */
#define baud_rate                  9600

/* select UART job */
#define USART_job                  reciever

/* enable/disable receive complete interrupt */
#define RXC_interrupt              enable

/* enable/disable data register interrupt */
#define TXC_interrupt              disable

/* enable/disable transmit complete interrupt */
#define TC_interrupt               disable


#endif /* USART_CONFIGURATION_H_ */
