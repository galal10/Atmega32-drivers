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
}

