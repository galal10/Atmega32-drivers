/*
 * MWDT_Program.c
 *
 *  Created on: Dec 17, 2023
 *      Author: galal
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITS.h"
#include "MWDT_Private.h"
#include "MWDT_Interface.h"
#include "MWDT_Config.h"


void MWDT_Vid_Start(void)
{
	/* Clear preScaler bits */
	WDTCR &= PreScaler_Mask;
	/* Set preScaler value */
	WDTCR |= WDT_PreScaler;
	/* Watchdog Enable bit */
	SET_BIT(WDTCR, WDE);
}

void MWDT_Vid_Stop(void)
{
	/* to disables the Watchdog
	In the same operation, write a logic one to WDTOE and WDE.
	2. Within the next four clock cycles, write a logic 0 to WDE.
	*/
	WDTCR |= (1<<WDE) | (1<<WDTOE);
	WDTCR = 0x00;
}
