/*
 * EEPROM_Interface.h
 *
 *  Created on: Dec 2, 2023
 *      Author: galal
 */

#ifndef HEEPROM_INTERFACE_H_
#define HEEPROM_INTERFACE_H_

typedef enum
{
	EEPROM_NO_ERROR,
	EEPROM_START_ERROR,
	EEPROM_RE_START_ERROR,
	EEPROM_ADDRESS_ERROR,
	EEPROM_DATA_ERROR,
}EEPROM_ERROR_t;

void HEEPROM_Vid_Init(void);
u8 HEEPROM_u8_WriteByte(u16 Copy_u16_addr, u8 Copy_u8_data);
u8 HEEPROM_u8_ReadByte(u16 Copy_u16_addr, u8 *Buffer);


#endif /* HEEPROM_INTERFACE_H_ */
