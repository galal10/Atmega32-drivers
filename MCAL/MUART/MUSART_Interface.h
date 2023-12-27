/*
 * MUSART_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"

/* Copy_u8_InterruptID Options:*/
typedef enum
{
	RXC_INT = 0,
	UDRE_INT,
	TXC_INT
}USART_InterruptID_t;

/* USART initialization */
void MUSART_Vid_Init(void);

/* USART send Data */
void MUSART_Vid_SendData(u8 Copy_u8_data);

/* USART receive Data */
u8 MUSART_u8_ReceiveData(void);

void MUSART_Vid_SendDataNoBlock(u8 Copy_u8_data);

u8 MUSART_u8_ReceiveDataNoBlock(void);

/* Enable USART Interrupts */
void MUSART_Vid_EnableInterrupt(u8 Copy_u8_InterruptID);

/* Disable USART Interrupts */
void MUSART_Vid_DisableInterrupt(u8 Copy_u8_InterruptID);

/* Set CallBack functions */
void MUSART_Vid_SetCallBack(u8 Copy_u8_InterruptID, void (*P_Vid_CallBack)(void));

#endif /* MUSART_INTERFACE_H_ */
