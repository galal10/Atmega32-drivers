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

#if TIMER1_SET_MODE == TIMER1_NORMAL_MODE
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_8_bit
	SET_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_9_bit
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_10_bit
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_CTC_OCR1A
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_8_bit
	SET_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_9_bit
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_10_bit
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A
	SET_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_CTC_ICR1
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_ICR1
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_OCR1A
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

#else
	#error "TIMER1 Mode is not valid"

#endif

	/* Timer1 OC1A, OC1B PINs */
	/* CLR bit COM1A1, COM1A0, COM1B1, COM1B0 */
	TCCR1A &= 0x0F;

	/* Output Compare Pins Behavior of Phase Correct and Phase and Frequency Correct PWM modes */
#if TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_8_bit || TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_9_bit \
		|| TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_10_bit || TIMER1_SET_MODE == \
		TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1 || TIMER1_SET_MODE == \
		TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A || TIMER1_SET_MODE == \
		TIMER1_PWM_PHASE_CORRECT_ICR1 || TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A

	TCCR1A |= (TIMER1_OC1A_PHASE << COM1A0) | (TIMER1_OC1B_PHASE << COM1B0);

	/* Output Compare Pins Behavior of non-PWM mode */
#elif TIMER1_SET_MODE == TIMER1_NORMAL_MODE || TIMER1_SET_MODE == TIMER1_CTC_ICR1 || TIMER1_SET_MODE == TIMER1_CTC_OCR1A
	TCCR1A |= (TIMER1_OC1A_NON_PWM << COM1A0) | (TIMER1_OC1B_NON_PWM << COM1B0);

	/* Output Compare Pins Behavior of fast-PWM mode */
#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_8_bit || TIMER1_SET_MODE == TIMER1_FAST_PWM_9_bit || TIMER1_FAST_PWM_10_bit || \
		TIMER1_SET_MODE == TIMER1_FAST_PWM_ICR1 || TIMER1_SET_MODE == TIMER1_FAST_PWM_OCR1A

	TCCR1A |= (TIMER1_OC1A_FAST_PWM << COM1A0) | (TIMER1_OC1B_FAST_PWM << COM1B0);


#else
	#error "TIMER1 Compare Output Mode is not valid"

#endif

#if TIMER1_ICU == ENABLE

	#if ICU_NoiseCanceler == ENABLE
		SET_BIT(TCCR1B, ICNC1);

	#elif ICU_NoiseCanceler == DISABLE
		CLR_BIT( TCCR1B, ICNC1 ) ;
	#endif

	// Select the beginning of the ICU edge.
	#if ICU_Edge_Select == ICU_RISING_EDGE
		SET_BIT(TCCR1B, ICES1);

	#elif ICU_Edge_Select == ICU_FALLING_EDGE
		CLR_BIT(TCCR1B, ICES1);

	#endif

#endif
}

void MTIMER2_Vid_Init(void)
{
	/* select the suitable pre scaler */
	/* clear CS22 CS21 CS20 bits */
	TCCR2 &= 0xF8;
	TCCR2 |= TIMER2_SET_PRESCALER;
	/* select mode */
#if TIMER2_SET_MODE == TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);

#elif TIMER2_SET_MODE == TIMER2_PHASECORRECT_MODE
	SET_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);

#elif TIMER2_SET_MODE == TIMER2_CTC_MODE
	CLR_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);

#elif TIMER2_SET_MODE == TIMER2_FASTPWM_MODE
	SET_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);

#else
	#error "TIMER2 Mode is not valid"

#endif

	/* Timer2 OC2 PIN */
	/* CLR bit COM21 COM20 */
	TCCR2 &= 0xCF;
	TCCR2 |= (TIMER2_SET_OC2_PIN_MODE << COM20);
}

void MTIMERS_Vid_StopTimer(u8 Copy_u8_TimerID)
{
	switch(Copy_u8_TimerID)
	{
		case TIMER0: TCCR0  &= 0xF8;  break; /* Clear bits CS02 CS01 CS00 */
		case TIMER1: TCCR1B &= 0xF8;  break; /* Clear bits CS12 CS11 CS10 */
		case TIMER2: TCCR2  &= 0xF8;  break; /* Clear bits CS22 CS21 CS20 */
	}
}

void MTIMERS_Vid_SetPreLoad(u8 Copy_u8_TimerID, u16 Copy_u16_Preload)
{
	switch(Copy_u8_TimerID)
	{
		case TIMER0: TCNT0 = Copy_u16_Preload; break;

		case TIMER1: TCNT1 = Copy_u16_Preload; break;

		case TIMER2: TCNT2 = Copy_u16_Preload; break;

	}
}

void MTIMERS_Vid_SetCTCValue(u8 Copy_u8_TimerID, u16 Copy_u16_CTCValue)
{
	switch(Copy_u8_TimerID)
	{
		case TIMER0: OCR0 = Copy_u16_CTCValue; break;

		case TIMER1:
			#if TIMER1_COMPARE_REGISTER == CMP_1A
				OCR1A = Copy_u16_CTCValue;
			#elif TIMER1_COMPARE_REGISTER == CMP_1B
				OCR1B = Copy_u16_CTCValue;
			#endif

			break;

		case TIMER2: OCR2 = Copy_u16_CTCValue; break;
	}
}

void MTIMER1_Vid_SetTopValue(u16 Copy_u16_TopValue)
{
#if TIMER1_SET_TOP_VALUE == SET_ON_ICR1
	ICR1 = Copy_u16_TopValue;

#elif TIMER1_SET_TOP_VALUE == SET_ON_OCR1A
	OCR1A = Copy_u16_TopValue;

#endif
}

void MTIMER1_Vid_SetICUTrigger(ICU_Trigger_t ICU_trigger)
{
	switch(ICU_trigger)
	{
		case ICU_RISING : SET_BIT(TCCR1B, ICES1);	break;
		case ICU_FALLING: CLR_BIT(TCCR1B, ICES1);	break;
	}
}

u16 MTIMER1_u16_GetCaptureUnitValue(void)
{
	return ICR1;
}

void MTIMERS_Vid_EnableInterrupt(u8 Copy_u8_TimerID, u8 Copy_u8_InterruptType)
{
	switch(Copy_u8_TimerID)
	{
		case TIMER0:
			switch(Copy_u8_InterruptType)
			{
				case TIMER0_OVF_INT : SET_BIT(TIMSK, TOIE0);  break;
				case TIMER0_CTC_INT : SET_BIT(TIMSK, OCIE0);  break;
			}
		break;

		case TIMER1:
			switch(Copy_u8_InterruptType)
			{
				case TIMER1_OVF_INT : 	SET_BIT(TIMSK, TOIE1);  break;
				case TIMER1_CTC1A_INT : SET_BIT(TIMSK, OCIE1A);  break;
				case TIMER1_CTC1B_INT : SET_BIT(TIMSK, OCIE1B);  break;
				case TIMER1_ICU_INT : 	SET_BIT(TIMSK, TICIE1);  break;
			}
		break;

		case TIMER2:
			switch(Copy_u8_InterruptType)
			{
				case TIMER2_OVF_INT : SET_BIT(TIMSK, TOIE2);  break;
				case TIMER2_CTC_INT : SET_BIT(TIMSK, OCIE2);  break;
			}
		break;
	}
}

void MTIMERS_Vid_DisableInterrupt(u8 Copy_u8_TimerID, u8 Copy_u8_InterruptType)
{
	switch(Copy_u8_TimerID)
	{
		case TIMER0:
			switch(Copy_u8_InterruptType)
			{
				case TIMER0_OVF_INT : CLR_BIT(TIMSK, TOIE0);  break;
				case TIMER0_CTC_INT : CLR_BIT(TIMSK, OCIE0);  break;
			}
		break;

		case TIMER1:
			switch(Copy_u8_InterruptType)
			{
				case TIMER1_OVF_INT : 	CLR_BIT(TIMSK, TOIE1);  break;
				case TIMER1_CTC1A_INT : CLR_BIT(TIMSK, OCIE1A);  break;
				case TIMER1_CTC1B_INT : CLR_BIT(TIMSK, OCIE1B);  break;
				case TIMER1_ICU_INT : 	CLR_BIT(TIMSK, TICIE1);  break;
			}
		break;

		case TIMER2:
			switch(Copy_u8_InterruptType)
			{
				case TIMER2_OVF_INT : CLR_BIT(TIMSK, TOIE2);  break;
				case TIMER2_CTC_INT : CLR_BIT(TIMSK, OCIE2);  break;
			}
		break;
	}
}

void MTIMERS_Vid_SetCallBack(u8 Copy_u8_TimerID, u8 Copy_u8_InterruptType, void (*Copy_Vid_CallBack)(void))
{
	switch(Copy_u8_TimerID)
	{
		case TIMER0:
			switch(Copy_u8_InterruptType)
			{
				case TIMER0_OVF_INT : TIMER0_CallBack[TIMER0_OVF_INT] = Copy_Vid_CallBack;  break;
				case TIMER0_CTC_INT : TIMER0_CallBack[TIMER0_CTC_INT] = Copy_Vid_CallBack;  break;
			}
		break;

		case TIMER1:
			switch(Copy_u8_InterruptType)
			{
				case TIMER1_OVF_INT : 	TIMER1_CallBack[TIMER1_OVF_INT] = Copy_Vid_CallBack;  break;
				case TIMER1_CTC1A_INT : TIMER1_CallBack[TIMER1_CTC1A_INT] = Copy_Vid_CallBack; break;
				case TIMER1_CTC1B_INT : TIMER1_CallBack[TIMER1_CTC1B_INT] = Copy_Vid_CallBack; break;
				case TIMER1_ICU_INT : 	TIMER1_CallBack[TIMER1_ICU_INT] = Copy_Vid_CallBack;  break;
			}
		break;

		case TIMER2:
			switch(Copy_u8_InterruptType)
			{
				case TIMER2_OVF_INT : TIMER2_CallBack[TIMER2_OVF_INT] = Copy_Vid_CallBack;  break;
				case TIMER2_CTC_INT : TIMER2_CallBack[TIMER2_CTC_INT] = Copy_Vid_CallBack;  break;
			}
		break;
	}

}

/* Timers ISR */
ISR(TIMER0_OVF)
{
	TIMER0_CallBack[TIMER0_OVF_INT]();
}

ISR(TIMER0_COMP)
{
	TIMER0_CallBack[TIMER0_CTC_INT]();
}

ISR(TIMER1_OVF)
{
	TIMER1_CallBack[TIMER1_OVF_INT]();
}

ISR(TIMER1_COMPA)
{
	TIMER1_CallBack[TIMER1_CTC1A_INT]();
}

ISR(TIMER1_COMPB)
{
	TIMER1_CallBack[TIMER1_CTC1B_INT]();
}

ISR(TIMER1_CAPT)
{
	TIMER1_CallBack[TIMER1_ICU_INT]();
}

ISR(TIMER2_OVF)
{
	TIMER2_CallBack[TIMER2_OVF_INT]();
}

ISR(TIMER2_COMP)
{
	TIMER2_CallBack[TIMER2_CTC_INT]();
}
