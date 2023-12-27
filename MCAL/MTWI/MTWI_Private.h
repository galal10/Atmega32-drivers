/*
 * MTWI_Private.h
 *
 *  Created on: Dec 1, 2023
 *      Author: galal
 */

#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_

/* TWI Bit Rate Register */
#define TWBR			*((volatile u8 *)(0x20))

/* TWI Status Register */
#define TWSR			*((volatile u8 *)(0x21))
/* Bits */
#define TWS7 			7
#define TWS6 			6
#define TWS5 			5
#define TWS4 			4
#define TWS3 			3
#define TWPS1 			1
#define TWPS0			0

/* my Address as a Slave Register */
#define TWAR			*((volatile u8 *)(0x22))
/* Bits */
#define TWGCE			0

/* TWI Data Register */
#define TWDR			*((volatile u8 *)(0x23))

/* TWI Control Register */
#define TWCR			*((volatile u8 *)(0x56))
/* Bits */
#define TWINT 			7
#define TWEA 			6
#define TWSTA 			5
#define TWSTO 			4
#define TWWC 			3
#define TWEN 			2
#define TWIE			0

/* TWI PreScaler */
#define TWI_PRESCALER_1		0x00
#define TWI_PRESCALER_4		0x01
#define TWI_PRESCALER_16	0x02
#define TWI_PRESCALER_64	0x03

/* TWI Clock */
#define SCL_Freq_100k		100000u
#define SCL_Freq_400k		400000u

#define TWI_STATUS_MASK		0xF8

#endif /* MTWI_PRIVATE_H_ */
