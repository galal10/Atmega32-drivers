/*
 * MSPI_Private.h
 *
 *  Created on: Nov 8, 2023
 *      Author: galal
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/* SPI Control Register */
#define SPCR			*((volatile u8*)(0x2D))
#define SPIE 			7
#define	SPE 			6
#define DORD 			5
#define MSTR 			4
#define CPOL 			3
#define CPHA 			2
#define SPR1 			1
#define SPR0 			0

/* SPI Status Register */
#define SPSR			*((volatile u8*)(0x2E))
#define SPIF 			7
#define WCOL  			6
#define SPI2X			0

/* SPI Data Register */
#define SPDR			*((volatile u8*)(0x2F))

/* Data order */
#define SPI_DATA_ORDER_LSB			0
#define SPI_DATA_ORDER_MSB			1

/* Clock Polarity */
#define SPI_CPOL_LEADING_RISING		0
#define SPI_CPOL_LEADING_FALLING	1

/* Clock Phase */
#define SPI_CPHA_LEADING_SAMPLE		0
#define SPI_CPHA_LEADING_SETUP		1

/* Double Speed */
#define SPI_NO_DOUBLE_SPEED			0
#define SPI_DOUBLE_SPEED			1

/* Clock Rate */
#define SPI_CLK_RATE_4				0
#define SPI_CLK_RATE_16				1
#define SPI_CLK_RATE_64				2
#define SPI_CLK_RATE_128			3

#define SPI_CLK_Rate_Masking 		0xFC

/* SPI interrupt */
#define ENABLE						1
#define DISABLE						0

#endif /* MSPI_PRIVATE_H_ */
