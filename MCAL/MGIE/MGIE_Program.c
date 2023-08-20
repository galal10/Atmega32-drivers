#include "../../LIB/LBITS.h"
#include "MGIE_Interface.h"
#include "MGIE_Private.h"

/*GIE Enable Function*/
void MGIE_Vid_Enable(void)
{
	SET_BIT(SREG, INT);
}

