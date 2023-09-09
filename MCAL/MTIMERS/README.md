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
## ICU test4
```c
/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: galal
 */
#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MGIE/MGIE_Interface.h"
#include "MCAL/MEXTI/MEXTI_Interface.h"
#include "MCAL/MTIMERS/MTIMERS_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "util/delay.h"

static u8 flag=0,count=0;
static u32 T1=0,T2=0,T3=0;

void APP_TIMER1ICU_ISR(void)
{
	if(flag == 0)
	{
		T1 = MTIMER1_u16_GetCaptureUnitValue() + count*65535;
		MTIMER1_Vid_SetICUTrigger(ICU_FALLING);
		flag = 1;
	}

	else if(flag == 1)
	{
		T2 = MTIMER1_u16_GetCaptureUnitValue() + count*65535;
		MTIMER1_Vid_SetICUTrigger(ICU_RISING);
		flag = 2;
	}

	else if(flag == 2)
	{
		T3 = MTIMER1_u16_GetCaptureUnitValue() + count*65535;
		flag = 3;
	}
}

int main(void)
{
	/* OC0 as output pin */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN3, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(MDIO_PORTD, PIN6, PIN_INPUT);
	/* lcd init */
	HCLCD_Vid_4Bits_Init();
	/* send welcome message */
	HCLCD_Vid_Write_String_4Bits((u8*)"Welcome");
	_delay_ms(1000);
	HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);

	/* set ctc value */
	MTIMERS_Vid_SetCTCValue(TIMER0, 90); /* 256*35% */
	/* Timer0 in fast PWM mode */
	MTIMER0_Vid_Init();
	/* Timer1 */
	/* enable OVF in Timer1 */
	MTIMERS_Vid_SetCallBack(TIMER1, TIMER1_ICU_INT, APP_TIMER1ICU_ISR);
	MTIMERS_Vid_EnableInterrupt(TIMER1, TIMER1_ICU_INT);
	MTIMER1_Vid_Init();

	/* enable general interrupt */
	MGIE_Vid_Enable();

	u32 freq = 0;
	u8 dutyCycle = 0;
	while(1)
	{
		if(flag == 3)
		{
			freq = 1000000/(T3 - T1);
			dutyCycle = ((T2 - T1)*100)/(T3 - T1);
			HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE1, 0);
			HCLCD_Vid_Write_String_4Bits((u8*)"Freq = ");
			HCLCD_Vid_Write_Number_4Bits(freq);

			HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE2, 0);
			HCLCD_Vid_Write_String_4Bits((u8*)"DutyCycle = ");
			HCLCD_Vid_Write_Number_4Bits(dutyCycle);

			flag = 4;
		}
	}

	return 0;
}
```