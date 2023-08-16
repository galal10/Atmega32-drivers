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
}

void HCLCD_Vid_8Bits_Init(void)
{
	/* Wait for more than 30ms */
	_delay_ms(30);
}
