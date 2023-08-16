#include "HCLCD_Interface.h"
#include "HCLCD_Private.h"
#include "HCLCD_Config.h"
#include <util/delay.h>

void HCLCD_Vid_Write_Command_8Bits(u8 Copy_u8_Command)
{
	/* select Command register ==> RS = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_LOW);
	/* select Write mode ==> RW = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RW, PIN_LOW);
	/* send command on port data */
	MDIO_Error_state_SetPortValue(DATA_PORT, Copy_u8_Command);
	/* Send Enable */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_LOW);
	_delay_ms(2);
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_HIGH);
}

void HCLCD_Vid_8Bits_Init(void)
{
	/* LCD Data and Control port initialization */
	MDIO_Error_state_SetPortDirection(DATA_PORT, PORT_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, RS, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, RW, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, E, PIN_OUTPUT);
	/* Wait for more than 30ms */
	_delay_ms(30);
	/* send function set command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_FUNCTION_SET);
	/* wait 39 µs */
	_delay_ms(1);
	/* Display ON/OFF command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_DISPLAY_ON_OFF);
	/* wait 39 µs */
	_delay_ms(1);
	/* Display Clear command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_DISPLAY_CLEAR);
	/* Wait for more than 1.53ms */
	_delay_ms(2);
	HCLCD_Vid_Write_Command_8Bits(HCLCD_ENTRY_MODE);
}

void HCLCD_Vid_Write_Char_8Bits(u8 Copy_u8_Data)
{
	/* select Data register ==> RS = 1 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_HIGH);
	/* select Write mode ==> RW = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RW, PIN_LOW);
	/* send Data on port data */
	MDIO_Error_state_SetPortValue(DATA_PORT, Copy_u8_Data);
	/* Send Enable */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_LOW);
	_delay_ms(2);
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_HIGH);
}

void HCLCD_Vid_Write_String_8Bits(u8 *PCopy_u8_String)
{
	u8 Loc_u8_count = 0;
	while(PCopy_u8_String[Loc_u8_count])
	{
		HCLCD_Vid_Write_Char_8Bits(PCopy_u8_String[Loc_u8_count]);
		Loc_u8_count++;
	}
}

void HCLCD_Vid_Write_Number_8Bits(u32 Copy_u32_Number)
{
	u8 ARR_Digits[10];
	u8 LOC_Count = 0;
		while(Copy_u32_Number)
		{
			ARR_Digits[LOC_Count] = Copy_u32_Number%10;
			Copy_u32_Number /= 10;
			LOC_Count++;
		}
	}	
}