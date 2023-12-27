/*
 * SUSART.c
 *
 *  Created on: Oct 26, 2023
 *      Author: galal
 */

#include "../../MCAL/MUART/MUSART_Interface.h"
#include "SUSART.h"

/******************************* Variables *******************************/
static u8 *Asynch_Send_str = NULL_PTR;
static u8 *Asynch_Receive_str = NULL_PTR;
static volatile UART_Flag_t UART_Flag = Tx;
/******************************* Tx CallBack Function *******************************/
static void Func_Tx(void)
{
	static u8 index = 1;

	if(Asynch_Send_str[index] != '\0')
	{
		/* send the remaining frame */
		MUSART_Vid_SendDataNoBlock(Asynch_Send_str[index]);
		/* increase index to send the next frame */
		index++;
	}

	else
	{
		MUSART_Vid_DisableInterrupt(TXC_INT);
		index = 1;
	}
}

static void Func_Tx_NoCodeInt(void)
{
	UART_Flag = Tx;
}

/******************************* Rx CallBack Function *******************************/
static void Func_Rx(void)
{
	static u8 index = 0;

	/* Receive the frame */
	Asynch_Receive_str[index] = MUSART_u8_ReceiveDataNoBlock();

	if(Asynch_Receive_str[index] == 0x0d)
	{
		MUSART_Vid_DisableInterrupt(RXC_INT);
		Asynch_Receive_str[index] = '\0';
		index = 0;
	}

	else
	{
		index++;
	}
}

/******************************* Synchronous *******************************/
void SUSART_Vid_SendString(u8* P_u8_str)
{
	while(*P_u8_str)
	{
		MUSART_Vid_SendData(*P_u8_str++);
	}
}

void SUSART_Vid_ReceiveString(u8* P_u8_buffer)
{
	u8 index = 0;

	P_u8_buffer[index] = MUSART_u8_ReceiveData();

	/* ascii code of Enter */
	while(P_u8_buffer[index] != 0x0d)
	{
		index++;
		P_u8_buffer[index] = MUSART_u8_ReceiveData();
	}

	P_u8_buffer[index] = '\0';
}

/******************************* Asynchronous *******************************/
void SUSART_Vid_SendStringAsynch(u8* str)
{
	/* Set CallBack function */
	MUSART_Vid_SetCallBack(TXC_INT, Func_Tx);

	/* Enable interrupt Tx */
	MUSART_Vid_EnableInterrupt(TXC_INT);

	/* Send first Byte */
	MUSART_Vid_SendDataNoBlock(str[0]);

	/* copy the address of string to the global array */
	Asynch_Send_str = str;
}

void SUSART_Vid_ReceiveStringAsynch(u8* Buffer)
{
	/* Set CallBack function */
	MUSART_Vid_SetCallBack(RXC_INT, Func_Rx);

	/* Enable Rx interrupt */
	MUSART_Vid_EnableInterrupt(RXC_INT);

	/* copy the address of buffer to global array */
	Asynch_Receive_str = Buffer;
}

/**************************** Asynchronous but no code in ISR ****************************/
void SUSART_Vid_SendString_NoCodeInt(u8* str)
{
	MUSART_Vid_SetCallBack(TXC_INT, Func_Tx_NoCodeInt);
	MUSART_Vid_EnableInterrupt(TXC_INT);
	static u8 index = 0;
	if(UART_Flag)
	{
		if(str[index])
		{
			MUSART_Vid_SendDataNoBlock(str[index]);
			index++;
		}

		else
		{
			MUSART_Vid_DisableInterrupt(TXC_INT);
			index = 0;
		}
		UART_Flag = Idle;
	}
}

/******************************* Check Sum Algorithm ************************/
void SUSART_Vid_SendString_MyProtocol(u8* P_u8_str)
{
	u8 len = 0;
	u16 sum = 0;

	/* check sum algorithm [ DataLen - Data - sum_of_data ] */
	while(P_u8_str[len] != '\0')
	{
		sum += P_u8_str[len];
		len++;
	}

	/* send length of the string */
	MUSART_Vid_SendData(len);

	/* send pure data */
	SUSART_Vid_SendString(P_u8_str);

	/* send LSB the MSB */
	MUSART_Vid_SendData((u8)sum);
	MUSART_Vid_SendData((sum>>8));
}

u8 SUSART_u8_ReceiveString_MyProtocol(u8* P_u8_buffer)
{
	/* length of the string */
	u8 	status, i, len = MUSART_u8_ReceiveData();

	/* vars to check sum */
	u16 sum_rece, sum_cal = 0;
	u8 FirstByte = 0, SecondByte = 0;

	for(i = 0; i < len; i++)
	{
		P_u8_buffer[i] = MUSART_u8_ReceiveData();
		sum_cal += P_u8_buffer[i];
	}

	P_u8_buffer[i] = '\0';

	FirstByte = MUSART_u8_ReceiveData();
	SecondByte = MUSART_u8_ReceiveData();
	/* the sum that received */
	sum_rece = FirstByte | (SecondByte << 8);


	if(sum_rece == sum_cal)
	{
		status = USART_FRAME_OK;
	}

	else
	{
		status = USART_FRAME_NOK;
	}

	return status;
}
