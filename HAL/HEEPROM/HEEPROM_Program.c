/*
 * EEPROM_Program.c
 *
 *  Created on: Dec 2, 2023
 *      Author: galal
 */


#include "../../LIB/LSTD_TYPES.h"

#include "HEEPROM_Private.h"
#include "HEEPROM_Config.h"
#include "HEEPROM_Interface.h"

#include "../../MCAL/MTWI/MTWI_Interface.h"


void HEEPROM_Vid_Init(void)
{
	MTWI_Vid_Init();
}

u8 HEEPROM_u8_WriteByte(u16 Copy_u16_addr, u8 Copy_u8_data)
{
	/* Send STart */
	MTWI_Vid_SendStart();
	/* Check Status */
	if(!(MTWI_u8_GetStatus() == TWI_MT_START_SUCCESS))
	{
		return EEPROM_START_ERROR;
	}
	/* Send Slave Address + Write */
	/* frame MSB [1 0 1 0 A10 A9 A8 W]*/
	MTWI_Vid_SendByte((((Copy_u16_addr >> 7) & 0x0E) | 0xA0) + 0);
	if(!(MTWI_u8_GetStatus() == TWI_MT_SLA_W_ACK))
	{
		return EEPROM_ADDRESS_ERROR;
	}
	/* frame LSB [A8-0] */
	MTWI_Vid_SendByte(((u8)Copy_u16_addr));

	if(!(MTWI_u8_GetStatus() == TWI_MT_DATA_ACK))
	{
		return EEPROM_DATA_ERROR;
	}

	/* Send data to be Written */
	MTWI_Vid_SendByte(Copy_u8_data);

	if(!(MTWI_u8_GetStatus() == TWI_MT_DATA_ACK))
	{
		return EEPROM_DATA_ERROR;
	}

	/* send Stop */
	MTWI_Vid_SendStop();

	return EEPROM_NO_ERROR;
}

u8 HEEPROM_u8_ReadByte(u16 Copy_u16_addr, u8 *Buffer)
{
/* 1- write Send Address */
	/* Send STart */
	MTWI_Vid_SendStart();
	/* Check Status */
	if(!(MTWI_u8_GetStatus() == TWI_MT_START_SUCCESS))
	{
		//MTWI_Vid_SendStop();
		return EEPROM_START_ERROR;
	}
	/* Send Slave Address + Write */
	/* frame MSB [1 0 1 0 A10 A9 A8 W]*/
	MTWI_Vid_SendByte((((Copy_u16_addr >> 7) & 0x0E) | 0xA0) + 0);
	if(!(MTWI_u8_GetStatus() == TWI_MT_SLA_W_ACK))
	{
		return EEPROM_ADDRESS_ERROR;
	}
	/* frame LSB [A8-0] */
	MTWI_Vid_SendByte(((u8)Copy_u16_addr));

	if(!(MTWI_u8_GetStatus() == TWI_MT_DATA_ACK))
	{
		return EEPROM_DATA_ERROR;
	}

/* 2- Repeated Start */
	MTWI_Vid_SendStart();

	if(!(MTWI_u8_GetStatus() == TWI_MT_REPATED_START_SUCCESS))
	{
		return EEPROM_RE_START_ERROR;
	}

/* 3- Send SLave addr + Read command to Read data "Address is sent before so we'll send the fixed address only [A0]" */
	MTWI_Vid_SendByte(0xA0 + 1);
	if(!(MTWI_u8_GetStatus() == TWI_MR_SLA_R_ACK))
	{
		return EEPROM_DATA_ERROR;
	}

	MTWI_Vid_ReceiveByte_ACK(Buffer);

	if(!(MTWI_u8_GetStatus() == TWI_MR_DATA_ACK))
	{
		return EEPROM_DATA_ERROR;
	}
	/* Send Stop */
	MTWI_Vid_SendStop();

	return EEPROM_NO_ERROR;
}

