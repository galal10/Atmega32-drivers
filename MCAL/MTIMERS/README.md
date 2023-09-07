# Test Code
## test1 
```c
#include "HAL/HLED/HLED_Interface.h"
#include "MCAL/MGIE/MGIE_Interface.h"
#include "MCAL/MTIMERS/MTIMERS_Interface.h"

LED_t Led1={MDIO_PORTB,LED1};

void APP_Vid_TIMER0_OVF_ISR()
{
	static u8 count = 0;
	count++;
	if( count == 30 )
	{
		HLED_Vid_Led_Toggle(&Led1);
		count = 0;
		MTIMERS_Vid_SetPreLoad(TIMER0, 124);
	}
}

int main(void)
{
	HLED_Vid_Init(&Led1);
	/* Timer0 */
	MTIMERS_Vid_SetCallBack(TIMER0, TIMER0_OVF_INT, APP_Vid_TIMER0_OVF_ISR);

/*	equation
 * Tick time = (1024/(8*10^6)) * 10^3  = 0.128 ms
 * OVF count = Tick time * 256 = 0.128 * 256 = 32.768
 * 1000/32.768 = 30.517 num of overflows = 30 + ...
 * ... = 256 - 0.517*256 = 123.648
 * put in TCNT0 (124) only in first time then 30 once of OVF
 * */

	MTIMERS_Vid_SetPreLoad(TIMER0, 124);
	MTIMER0_Vid_Init();
	MTIMERS_Vid_EnableInterrupt(TIMER0, TIMER0_OVF_INT);
	/* Enable General interrupt */
	MGIE_Vid_Enable();
	while(1)
	{
	}
	return 0;
}
```

## test2
```c
#include "HAL/HLED/HLED_Interface.h"
#include "MCAL/MGIE/MGIE_Interface.h"
#include "MCAL/MTIMERS/MTIMERS_Interface.h"

LED_t Led1={MDIO_PORTB,LED1};

void APP_Vid_TIMER0_OC_ISR()
{
	static u8 count = 0;
	count++;
	if( count == 100 )
	{
		HLED_Vid_Led_Toggle(&Led1);
		count = 0;
	}
}

int main(void)
{
	HLED_Vid_Init(&Led1);
	/* Timer0 */
	MTIMERS_Vid_SetCallBack(TIMER0, TIMER0_CTC_INT, APP_Vid_TIMER0_OC_ISR);

/*	equation
 * Tick time = (1024/(8*10^6)) * 10^3 ms
 * OVF count = Tick time * 256 = 0.128 * 256 = 32.768
 *
 * 256			32.768 ms
 * x			10 ms			// 10ms * 100 = 1000ms
 *
 * x = (10*256)/32.768 = 78.125
 * */

	MTIMERS_Vid_SetCTCValue(TIMER0, 78);
	MTIMER0_Vid_Init();
	MTIMERS_Vid_EnableInterrupt(TIMER0, TIMER0_CTC_INT);
	/* Enable General interrupt */
	MGIE_Vid_Enable();
	while(1)
	{
	}
	return 0;
}
```
## Servo test3
```c
#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MTIMERS/MTIMERS_Interface.h"
#include <util/delay.h>

int main(void)
{
	/* OC1A as output pin for servo motor */
	MDIO_Error_state_SetPinDirection(MDIO_PORTD, PIN5, PIN_OUTPUT);


	/*	equation of servo motor
	 * Tick time = (8/(8*10^6)) * 10^3 = 0.001 = 10^-3 ms
	 * OVF count = Tick time * 65535 = 0.001 * 65535 = 65.535 ms
	 *
	 * 65535			65.535 ms
	 * x				20 ms
	 *
	 * x = (20*65535)/65.535 = 20000 = Top put it in ICR1
	 *
	 * 0 degree ==> 1.5 ms
	 * Ton of 0 degree = (1.5*65535)/65.535 = 1500  put in OCR1A or OCR1B
	 *
	 * 90 degree ==> 2 ms
	 * Ton of 0 degree = (2*65535)/65.535 = 2000  put in OCR1A or OCR1B
	 *
	 * -90 degree ==> 1 ms
	 * Ton of 0 degree = (1*65535)/65.535 = 1000  put in OCR1A or OCR1B
	 * */

	/* Timer1 */
	MTIMER1_Vid_SetTopValue(20000);
	MTIMER1_Vid_Init();

	while(1)
	{
		MTIMERS_Vid_SetCTCValue(TIMER1, 1000); /* -90 degree */
		_delay_ms(1000);
		MTIMERS_Vid_SetCTCValue(TIMER1, 1500); /*  0  degree */
		_delay_ms(1000);
		MTIMERS_Vid_SetCTCValue(TIMER1, 2000); /*  90 degree */
		_delay_ms(1000);
	}
	return 0;
}

```