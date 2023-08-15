#ifndef HCLCD_INTERFACE_H_
#define HCLCD_INTERFACE_H_

void HCLCD_Vid_8Bits_Init(void);

void HCLCD_Vid_4Bits_Init(void);

void HCLCD_Vid_Write_Char_8Bits(u8 Copy_u8_Data);

void HCLCD_Vid_Write_Char_4Bits(u8 Copy_u8_Data);

void HCLCD_Vid_Write_Command_8Bits(u8 Copy_u8_Command);

void HCLCD_Vid_Write_Command_4Bits(u8 Copy_u8_Command);

void HCLCD_Vid_Write_String_8Bits(u8 *Copy_u8_Data);

void HCLCD_Vid_Write_String_4Bits(u8 *Copy_u8_Data);

void HCLCD_Vid_SetPosition(u8 Copy_u8_LineNumber, u8 Copy_u8_PositionNumber);

#endif /* HCLCD_INTERFACE_H_ */
