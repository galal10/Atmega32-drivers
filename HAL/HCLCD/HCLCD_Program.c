#include "HCLCD_Interface.h"
#include <util/delay.h>

void HCLCD_Vid_Write_Command_8Bits(u8 Copy_u8_Command)
{
	/* select Command register ==> RS = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_LOW);
}

void HCLCD_Vid_8Bits_Init(void)
{
	/* Wait for more than 30ms */
	_delay_ms(30);
}
