/*
 * MSPI_Program.c
 *
 *  Created on: Nov 8, 2023
 *      Author: galal
 */

#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MSPI_Private.h"
#include "MSPI_Config.h"
#include "MSPI_Interface.h"

void MSPI_Vid_Master_Init(void)
{
	/* Set data order */
#if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
	SET_BIT(SPCR, DORD);
#elif SPI_DATA_ORDER == SPI_DATA_ORDER_MSB
	CLR_BIT(SPCR, DORD);
#else
	#error "SPI Data ordered option is not valid"
#endif
	/* Set Clock polarity */
#if SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_RISING
	CLR_BIT(SPCR, CPOL);
#elif SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_FALLING
	SET_BIT(SPCR, CPOL);
#else
	#error "SPI clock polarity option is not valid"
#endif
	/* Set Clock phase */
#if SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SAMPLE
	CLR_BIT(SPCR, CPHA);
#elif SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SETUP
	SET_BIT(SPCR, CPHA);
#else
	#error "SPI clock phase option is not valid"
#endif
	/* Double SPI Speed Bit */
#if SPI_SET_DOUBLE_SPEED == SPI_NO_DOUBLE_SPEED
	CLR_BIT(SPSR, SPI2X);
#elif SPI_SET_DOUBLE_SPEED == SPI_DOUBLE_SPEED
	SET_BIT(SPSR, SPI2X);
#else
	#error "SPI Double speed option is not valid"
#endif
	/* SPI Clock Rate */
	SPCR &= SPI_CLK_Rate_Masking;
	SPCR |= SPI_CLK_RATE;
	/* select Master SPI mode */
	SET_BIT(SPCR, MSTR);
	/* SPI Enable */
	SET_BIT(SPCR, SPE);
	/* SPI interrupt */
#if SPI_INTERRUPT == ENABLE
	SET_BIT(SPCR, SPIE);
#elif SPI_INTERRUPT == DISABLE
	CLR_BIT(SPCR, SPIE);
#else
	#error "SPI Interrupt option is not valid"
#endif
}

void MSPI_Vid_Slave_Init(void)
{
	/* Set data order */
#if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
	SET_BIT(SPCR, DORD);
#elif SPI_DATA_ORDER == SPI_DATA_ORDER_MSB
	CLR_BIT(SPCR, DORD);
#else
	#error "SPI Data ordered option is not valid"
#endif
	/* Set Clock polarity */
#if SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_RISING
	CLR_BIT(SPCR, CPOL);
#elif SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_FALLING
	SET_BIT(SPCR, CPOL);
#else
	#error "SPI clock polarity option is not valid"
#endif
	/* Set Clock phase */
#if SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SAMPLE
	CLR_BIT(SPCR, CPHA);
#elif SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SETUP
	SET_BIT(SPCR, CPHA);
#else
	#error "SPI clock phase option is not valid"
#endif
	/* select Slave SPI mode */
	CLR_BIT(SPCR, MSTR);
	/* SPI Enable */
	SET_BIT(SPCR, SPE);
	/* SPI interrupt */
#if SPI_INTERRUPT == ENABLE
	SET_BIT(SPCR, SPIE);
#elif SPI_INTERRUPT == DISABLE
	CLR_BIT(SPCR, SPIE);
#else
	#error "SPI Interrupt option is not valid"
#endif
}

u8 MSPI_u8_Send_Receive(u8 Copy_u8_char)
{
	/* Send Char */
	SPDR = Copy_u8_char;
	/* wait until SPI flag is set */
	while(GET_BIT(SPSR, SPIF) == 0);
	return SPDR;
}
