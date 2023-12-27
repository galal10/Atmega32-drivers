/*
 * MUSART_Private.h
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_

/* USART I/O Data Register */
#define UDR			*((volatile u8*)(0x2C))
/********************************************/

/* USART Baud Rate Register low */
#define UBBRL		*((volatile u8*)(0x29))

/* USART Baud Rate Register high */
#define UBBRH		*((volatile u8*)(0x40))
/********************************************/

/* USART Control and Status Register A */
#define UCSRA		*((volatile u8*)(0x2B))

#define RXC 		7
#define TXC 		6
#define UDRE 		5
#define FE 			4
#define DOR 		3
#define PE			2
#define U2X			1
#define MPCM		0
/********************************************/

/* USART Control and Status Register B */
#define UCSRB		*((volatile u8*)(0x2A))

#define RXCIE 		7
#define TXCIE 		6
#define UDRIE 		5
#define RXEN		4
#define TXEN		3
#define UCSZ2 		2
#define RXB8 		1
#define TXB8		0
/********************************************/

/* USART Control and Status Register C */
#define UCSRC		*((volatile u8*)(0x40))

#define URSEL 		7
#define UMSEL 		6
#define UPM1 		5
#define UPM0 		4
#define USBS 		3
#define UCSZ1 		2
#define UCSZ0 		1
#define UCPOL		0
/********************************************/

/* USART modes */
#define USART_ASYNCHRONOUS_MODE		0
#define USART_SYNCHRONOUS_MODE		1

/* USART Parity mode */
#define USART_DISABLE_PARITY		0
#define USART_EVEN_PARITY			2
#define USART_ODD_PARITY			3

#define USART_PARITY_MASK			0xCF


/* USART Stop mode */
#define USART_STOP_ONE_BIT			0
#define USART_STOP_TWO_BIT			1

/* USART data size */
#define USART_DATA_SIZE_5			5
#define USART_DATA_SIZE_6			6
#define USART_DATA_SIZE_7			7
#define USART_DATA_SIZE_8			8
#define USART_DATA_SIZE_9			9

/* USART UBRR value  */
#define USART_UBRR_VALUE			51

#define USART_RisingTx_FallingRx	0
#define USART_FallingTx_RisingRx	1

/* USART Interrupts */
#define Enable						1
#define Disable						0

/* Number of UART interrupts */
#define UART_ISR					3

#define ISR(vector, ...)	\
void vector(void) __attribute__((signal)) __VA_ARGS__;\
void vector(void)

#define USART_RXC			__vector_13
#define USART_UDRE			__vector_14
#define USART_TXC			__vector_15

#endif /* MUSART_PRIVATE_H_ */
