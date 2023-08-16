#include "HCLCD_Interface.h"
#include <util/delay.h>

void HCLCD_Vid_Write_Command_8Bits(u8 Copy_u8_Command)
{
	/* select Command register ==> RS = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_LOW);
	/* select Write mode ==> Rw = 0 */
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
	MDIO_Error_state_SetPinDirection(RS, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(RW, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(E, PIN_OUTPUT);
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
	/* select Write mode ==> Rw = 0 */
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

void HCLCD_Vid_Write_String_8Bits(u8 *Copy_u8_Data)
	}
}