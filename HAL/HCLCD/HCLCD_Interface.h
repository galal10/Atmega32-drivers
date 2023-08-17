#ifndef HCLCD_INTERFACE_H_
#define HCLCD_INTERFACE_H_

#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "../../LIB/LSTD_TYPES.h"

/* DISPLAY_CLEAR command */
#define HCLCD_DISPLAY_CLEAR		0x01

#define HCLCD_LINE1				1
#define HCLCD_LINE2				2

void HCLCD_Vid_8Bits_Init(void);

void HCLCD_Vid_4Bits_Init(void);

void HCLCD_Vid_Write_Char_8Bits(u8 Copy_u8_Data);

void HCLCD_Vid_Write_Char_4Bits(u8 Copy_u8_Data);

void HCLCD_Vid_Write_Command_8Bits(u8 Copy_u8_Command);

void HCLCD_Vid_Write_Command_4Bits(u8 Copy_u8_Command);

void HCLCD_Vid_Write_String_8Bits(u8 *PCopy_u8_String);

void HCLCD_Vid_Write_String_4Bits(u8 *PCopy_u8_String);

void HCLCD_Vid_Write_Number_8Bits(u32 Copy_u32_Number);

void HCLCD_Vid_Write_Number_4Bits(u32 Copy_u32_Number);

void HCLCD_Vid_SetPosition_8Bits(u8 Copy_u8_LineNumber, u8 Copy_u8_PositionNumber);

void HCLCD_Vid_SetPosition_4Bits(u8 Copy_u8_LineNumber, u8 Copy_u8_PositionNumber);


#endif /* HCLCD_INTERFACE_H_ */
