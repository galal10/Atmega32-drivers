/*
 * MTIMER_Program.c
 *
 *  Created on: Aug 25, 2023
 *      Author: galal
 */

#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MTIMER0_Config.h"
#include "MTIMER1_Config.h"
#include "MTIMER2_Config.h"
#include "MTIMERS_Interface.h"
#include "MTIMERS_Private.h"

static void (*TIMER0_CallBack[TIMER0_ISR_VECTORS])(void) = {NULL_PTR};
static void (*TIMER1_CallBack[TIMER1_ISR_VECTORS])(void) = {NULL_PTR};
static void (*TIMER2_CallBack[TIMER2_ISR_VECTORS])(void) = {NULL_PTR};

void MTIMER0_Vid_Init(void)
{
	/* select the suitable pre scaler */
	/* clear cs00, cs01, cs02 bits */
	TCCR0 &= 0xF8;
	TCCR0 |= TIMER0_SET_PRESCALER;
	/* select mode */
#if TIMER0_SET_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);

#elif TIMER0_SET_MODE == TIMER0_PHASECORRECT_MODE
	SET_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);

#elif TIMER0_SET_MODE == TIMER0_CTC_MODE
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

#elif TIMER0_SET_MODE == TIMER0_FASTPWM_MODE
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

#else
	#error "TIMER0 Mode is not valid"

#endif

	/* Timer0 OC0 PIN */
	/* CLR bit COM00, COM01 */
	TCCR0 &= 0xCF;
	TCCR0 |= (TIMER0_SET_OC0_PIN_MODE << COM00);
}

void MTIMER1_Vid_Init(void)
{
	/* select the suitable pre scaler */
	/* clear CS12,CS11,CS10 bits */
	TCCR1B &= 0xF8;
	TCCR1B |= TIMER1_SET_PRESCALER;

}

}

