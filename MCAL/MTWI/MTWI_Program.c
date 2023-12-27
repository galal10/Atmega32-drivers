/*
 * MTWI_Program.c
 *
 *  Created on: Dec 1, 2023
 *      Author: galal
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITS.h"
#include "MTWI_Private.h"
#include "MTWI_Interface.h"
#include "MTWI_Config.h"

static u8 PreScaler[4] = {1, 4, 16, 64};

void MTWI_Vid_Init(void)
{
	//Prescaler
	TWSR &= ~(0x03);
	TWSR |= TWI_PRESCALER;
	//Bit Rate
	TWBR = ((CPU_Freq/SCL_Freq - 16)/(2*PreScaler[TWI_PRESCALER]));
	//Enable Peripheral
	SET_BIT(TWCR, TWEN);
}

void MTWI_Vid_SendByte(u8 copy_u8_data)
{
	/* Load to be sent to data Register (SLA+W/R or Data) */
	TWDR = copy_u8_data;
	/* clear flag + Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait until job is finished */
	while(GET_BIT(TWCR, TWINT) == 0);
}

void MTWI_Vid_SendStart(void)
{
	/* send start + clear flag + Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	/* Wait until job is finished */
	while(GET_BIT(TWCR, TWINT) == 0);
}

void MTWI_Vid_SendStop(void)
{
	/* send stop + clear flag + Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void MTWI_Vid_ReceiveByte_ACK(u8 *Buffer)
{
	/* clear flag + Enable TWI + Enable ACK */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	/* Wait until job is finished */
	while(GET_BIT(TWCR, TWINT) == 0);

	*Buffer = TWDR;
}

void MTWI_Vid_ReceiveByte_NoACK(u8 *Buffer)
{
	/* Disable ACK */
	CLR_BIT(TWCR, TWEA);
	/* clear flag + Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait until job is finished */
	while(GET_BIT(TWCR, TWINT) == 0);

	*Buffer = TWDR;
}

u8 MTWI_u8_GetStatus(void)
{
	return (TWSR & TWI_STATUS_MASK);
}
