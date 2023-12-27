/*
 * MUSART_Config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */

#ifndef MUSART_CONFIG_H_
#define MUSART_CONFIG_H_

/* USART mode Options:
 * 1- USART_ASYNCHRONOUS_MODE
 * 2- USART_SYNCHRONOUS_MODE
 */
#define USART_MODE				USART_ASYNCHRONOUS_MODE

/* USART Parity Options:
 * 1- USART_DISABLE_PARITY
 * 2- USART_EVEN_PARITY
 * 3- USART_ODD_PARITY
 */
#define USART_PARITY_MODE		USART_DISABLE_PARITY

/* USART Stop bits mode
 * 1- USART_STOP_ONE_BIT
 * 2- USART_STOP_TWO_BIT
 */
#define USART_STOP_MODE			USART_STOP_ONE_BIT

/* USART data size Options:
 * 1- USART_DATA_SIZE_5
 * 2- USART_DATA_SIZE_6
 * 3- USART_DATA_SIZE_7
 * 4- USART_DATA_SIZE_8
 * 5- USART_DATA_SIZE_9
 */
#define USART_DATA_SIZE			USART_DATA_SIZE_8

/* USART Clock Polarity Options:
 * 1- USART_RisingTx_FallingRx
 * 2- USART_FallingTx_RisingRx*/
#define USART_CLOCK_POLARITY	USART_RisingTx_FallingRx

/* USART RX Complete Interrupt Options:
 * 1- Enable
 * 2- Disable
 */
#define RX_Complete_Interrupt	Enable

/* USART TX Complete Interrupt Options:
 * 1- Enable
 * 2- Disable
 */
#define TX_Complete_Interrupt	Disable

/* USART Data Register Empty Interrupt Options:
 * 1- Enable
 * 2- Disable
 */
#define DataReg_Empty_Interrupt	Disable

#endif /* MUSART_CONFIG_H_ */
