/*
 * SUSART.h
 *
 *  Created on: Oct 26, 2023
 *      Author: galal
 */

#ifndef SUSART_H_
#define SUSART_H_

typedef enum
{
	USART_FRAME_OK,
	USART_FRAME_NOK
}USART_FRAME_t;

typedef enum
{
	Idle = 0,
	Tx,
	Rx
}UART_Flag_t;

void SUSART_Vid_SendString(u8* P_u8_str);

void SUSART_Vid_ReceiveString(u8* P_u8_buffer);

void SUSART_Vid_SendStringAsynch(u8* str);

void SUSART_Vid_SendString_NoCodeInt(u8* str);

void SUSART_Vid_ReceiveStringAsynch(u8* Buffer);

void SUSART_Vid_SendString_MyProtocol(u8* P_u8_str);

u8 SUSART_u8_ReceiveString_MyProtocol(u8* P_u8_buffer);


#endif /* SUSART_H_ */
