/*
 * MUSART_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */
#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MUSART_Interface.h"
#include "MUSART_Config.h"
#include "MUSART_Private.h"

static void (* GP_UART_CallBack[UART_ISR])(void) = {NULL_PTR};

void MUSART_Vid_Init(void)
{
	u8 LOC_u8Copy_UCSRC = 0;

	/* frame */
	/* select USART mode */
#if USART_MODE == USART_ASYNCHRONOUS_MODE
	CLR_BIT(LOC_u8Copy_UCSRC, UMSEL);
#elif USART_MODE == USART_SYNCHRONOUS_MODE
	SET_BIT(LOC_u8Copy_UCSRC, UMSEL);

	/* set CLK polarity -> with synch. mode only */
	#if USART_CLOCK_POLARITY == USART_RisingTx_FallingRx
		CLR_BIT(UCSRC, UCPOL);
	#elif USART_CLOCK_POLARITY == USART_FallingTx_RisingRx
		SET_BIT(UCSRC, UCPOL);
	#else
		#error "USART CLK polarity mode is not valid"
	#endif

#else
	#error "USART mode is not valid"
#endif

	/* Parity mode */
	LOC_u8Copy_UCSRC &= USART_PARITY_MASK;
	LOC_u8Copy_UCSRC |= USART_PARITY_MODE << UPM0;

	/* Stop bits mode */
#if USART_STOP_MODE == USART_STOP_ONE_BIT
	CLR_BIT(LOC_u8Copy_UCSRC, USBS);
#elif USART_STOP_MODE == USART_STOP_TWO_BIT
	SET_BIT(LOC_u8Copy_UCSRC, USBS);
#else
	#error "USART Stop bit mode is not valid"
#endif

	/* Data size */
#if USART_DATA_SIZE == USART_DATA_SIZE_5
	CLR_BIT(LOC_u8Copy_UCSRC, UCSZ0);
	CLR_BIT(LOC_u8Copy_UCSRC, UCSZ1);
	CLR_BIT(UCSRB, UCSZ2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_6
	SET_BIT(LOC_u8Copy_UCSRC, UCSZ0);
	CLR_BIT(LOC_u8Copy_UCSRC, UCSZ1);
	CLR_BIT(UCSRB, UCSZ2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_7
	CLR_BIT(LOC_u8Copy_UCSRC, UCSZ0);
	SET_BIT(LOC_u8Copy_UCSRC, UCSZ1);
	CLR_BIT(UCSRB, UCSZ2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_8
	SET_BIT(LOC_u8Copy_UCSRC, UCSZ0);
	SET_BIT(LOC_u8Copy_UCSRC, UCSZ1);
	CLR_BIT(UCSRB, UCSZ2);
#elif USART_DATA_SIZE == USART_DATA_SIZE_9
	SET_BIT(LOC_u8Copy_UCSRC, UCSZ0);
	SET_BIT(LOC_u8Copy_UCSRC, UCSZ1);
	SET_BIT(UCSRB, UCSZ2);
#else
	#error "USART Data size mode is not valid"
#endif

	/* select UCSRC Register*/
	SET_BIT(LOC_u8Copy_UCSRC, URSEL);
	/* Set LOC_u8Copy_UCSRC Value in UCSRC Register */
	UCSRC = LOC_u8Copy_UCSRC;
	/********************************************/

	/* Baud Rate ==> 9600 */
	UBBRL = USART_UBRR_VALUE;
	/********************************************/

	/* USART RX Complete Interrupt mode */
#if RX_Complete_Interrupt == Enable
	SET_BIT(UCSRB, RXCIE);
#elif RX_Complete_Interrupt == Disable
	CLR_BIT(UCSRB, RXCIE);
#else
	#error "USART RX Complete Interrupt mode is not valid"
#endif

	/* USART TX Complete Interrupt mode */
#if TX_Complete_Interrupt == Enable
	SET_BIT(UCSRB, TXCIE);
#elif TX_Complete_Interrupt == Disable
	CLR_BIT(UCSRB, TXCIE);
#else
	#error "USART TX Complete Interrupt mode is not valid"
#endif

	/* USART Data Register Empty Interrupt mode */
#if DataReg_Empty_Interrupt == Enable
	SET_BIT(UCSRB, UDRIE);
#elif DataReg_Empty_Interrupt == Disable
	CLR_BIT(UCSRB, UDRIE);
#else
	#error "USART Data Register Empty Interrupt mode is not valid"
#endif

	/* Enable Peripheral */
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
}

/***************************** Polling ********************************************/
void MUSART_Vid_SendData(u8 Copy_u8_data)
{
	/* wait until empty flag is set */
	while( GET_BIT(UCSRA, UDRE) == 0 );

	UDR = Copy_u8_data;
}

u8 MUSART_u8_ReceiveData(void)
{
	/* wait until register Complete flag is set */
	while( GET_BIT(UCSRA, RXC) == 0 );

	return UDR;
}

/***************************** Interrupt ********************************************/
void MUSART_Vid_SendDataNoBlock(u8 Copy_u8_data)
{
	UDR = Copy_u8_data;
}

u8 MUSART_u8_ReceiveDataNoBlock(void)
{
	return UDR;
}

/**************************** Enable USART Interrupts *******************************/
void MUSART_Vid_EnableInterrupt(u8 Copy_u8_InterruptID)
{
	switch(Copy_u8_InterruptID)
	{
		case RXC_INT  : SET_BIT(UCSRB, RXCIE); break;
		case UDRE_INT : SET_BIT(UCSRB, UDRIE); break;
		case TXC_INT  : SET_BIT(UCSRB, TXCIE); break;
	}
}

/**************************** Disable USART Interrupts ******************************/
void MUSART_Vid_DisableInterrupt(u8 Copy_u8_InterruptID)
{
	switch(Copy_u8_InterruptID)
	{
		case RXC_INT  : CLR_BIT(UCSRB, RXCIE); break;
		case UDRE_INT : CLR_BIT(UCSRB, UDRIE); break;
		case TXC_INT  : CLR_BIT(UCSRB, TXCIE); break;
	}
}

/************************** Set CallBack functions *********************************/
void MUSART_Vid_SetCallBack(u8 Copy_u8_InterruptID, void (*P_Vid_CallBack)(void))
{
	switch(Copy_u8_InterruptID)
	{
		case RXC_INT  : GP_UART_CallBack[RXC_INT]  = P_Vid_CallBack; break;
		case UDRE_INT : GP_UART_CallBack[UDRE_INT] = P_Vid_CallBack; break;
		case TXC_INT  : GP_UART_CallBack[TXC_INT]  = P_Vid_CallBack; break;
	}
}

/*************************************** ISR *******************************************/
ISR(USART_RXC)
{
	if(GP_UART_CallBack[RXC_INT] != NULL_PTR)
	{
		GP_UART_CallBack[RXC_INT]();
	}
}

ISR(USART_UDRE)
{
	if(GP_UART_CallBack[UDRE_INT] != NULL_PTR)
	{
		GP_UART_CallBack[UDRE_INT]();
	}
}

ISR(USART_TXC)
{
	if(GP_UART_CallBack[TXC_INT] != NULL_PTR)
	{
		GP_UART_CallBack[TXC_INT]();
	}
}
