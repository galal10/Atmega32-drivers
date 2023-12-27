/*
 * MSPI_Interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: galal
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/* SPI Master Initialization */
void MSPI_Vid_Master_Init(void);
/* SPI Slave Initialization */
void MSPI_Vid_Slave_Init(void);
/* SPI Master Send_Receive Char */
u8 MSPI_u8_Send_Receive(u8 Copy_u8_char);

#endif /* MSPI_INTERFACE_H_ */
