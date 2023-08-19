# Test Code
```c
/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: galal
 */

#include "HAL/HCLCD/HCLCD_Interface.h"
#include "HAL/HKPD/HKPD_Config.h"
#include "HAL/HKPD/HKPD_Interface.h"
#include <util/delay.h>

int main(void)
{
	HKPD_Vid_init();
	HCLCD_Vid_4Bits_Init();
	HCLCD_Vid_Write_String_4Bits((u8*)"Galal Nasser Elfeky");

	_delay_ms(1000);
	HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);
	while(1)
	{
		u8 KPD_char = HKPD_u8_GetKeyPressed();
		if( KPD_char != NOT_PRESSED )
		{
			if( KPD_char == 'C' )
			{
				HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);
			}
			else
			{
				HCLCD_Vid_Write_Char_4Bits(KPD_char);
			}
		}
	}
	return 0;
}

```