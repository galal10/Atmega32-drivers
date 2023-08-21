# Test Code
```c
/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: galal
 */

#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MEXTI/MEXTI_Interface.h"
#include "MCAL/MGIE/MGIE_Interface.h"
#include "HAL/HLED/HLED_Interface.h"

LED_t Led1={MDIO_PORTC,LED3};
int main(void)
{
	/* set pinD2 as an input ==> EXTI0 */
	MDIO_Error_state_SetPinDirection(MDIO_PORTD, PIN2, PIN_INPUT);
	/* activate pull up resistor */
	MDIO_Error_state_ActivatePullUpResistor(MDIO_PORTD, PIN2);
	/* set pinC2 as an output ==> led*/
	HLED_Vid_Init(&Led1);
	/* Enable EXTI0 */
	MEXTI0_Vid_Init();
	/* Enable General interrupt */
	MGIE_Vid_Enable();
	MEXTI_Vid_SenseControl(EXTI0, RISING_EDGE);
	while(1)
	{
	}
	return 0;
}

void __vector_1(void)       __attribute__((signal));
void __vector_1(void)
{
	HLED_Vid_Led_Toggle(&Led1);
}

```