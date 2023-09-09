/*
 * MTIM_Private.h
 *
 *  Created on: Aug 25, 2023
 *      Author: galal
 */

#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_

/******************************** general ****************************************************/
/* Timer/Counter Interrupt Mask register */
#define TIMSK		*((volatile u8*)(0x59))
/* TIMSK bits */
#define OCIE2 							7 /* compare match timer2 */
#define TOIE2 							6 /* overflow timer2 */
#define TICIE1 							5
#define OCIE1A 							4 /* compare match timer1A */
#define OCIE1B 							3 /* compare match timer1B */
#define TOIE1							2 /* overflow timer1 */
#define OCIE0							1 /* compare match timer0 */
#define TOIE0							0 /* overflow timer0 */


#define ISR_NOBLOCK				__attribute__((interrupt))
#define ISR_NAKED				__attribute__((naked))

#define ISR(vector, ...)	\
void vector(void) __attribute__((signal)) __VA_ARGS__;\
void vector(void)

/***************************** Timer0 ****************************************************/
/* Timer counter control register : TCCR0 */
#define TCCR0		*((volatile u8*)(0x53))
/* TCCR0 bits */
#define WGM00							6
#define COM01							5
#define COM00							4
#define WGM01							3
#define CS02							2
#define CS01							1
#define CS00							0

/* Timer/Counter register */
#define TCNT0		*((volatile u8*)(0x52))

/* Output compare register */
#define OCR0		*((volatile u8*)(0x5C))

/* Macros for timer0 modes */
#define TIMER0_NORMAL_MODE  			0
#define	TIMER0_PHASECORRECT_MODE		1
#define	TIMER0_CTC_MODE					2
#define	TIMER0_FASTPWM_MODE				3

typedef enum
{
	TIMER0_STOP = 0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
}TIMER0Scaler_t;

/* Timer0 CTC OC0 PIN */
#define TIMER0_OC0_PIN_DISCONNECTED			0
#define TIMER0_OC0_PIN_TOGGLE				1
#define TIMER0_OC0_PIN_CLR_NON_INVERTING	2
#define TIMER0_OC0_PIN_SET_INVERTING		3

/* Timer0 vectors */
#define TIMER0_OVF				__vector_11
#define TIMER0_COMP				__vector_10

/***************************** Timer1 ****************************************************/

#define TCCR1A		*((volatile u8*)(0x4F))
/* TCCR1A bits */
#define COM1A1 							7
#define COM1A0 							6
#define COM1B1 							5
#define COM1B0 							4
#define FOC1A 							3
#define FOC1B 							2
#define WGM11 							1
#define WGM10 							0

/*Timer Counter1 Control RegisterB : TCCR1B */
#define TCCR1B		*((volatile u8*)(0x4E))
/* TCCR1B bits */
#define ICNC1 							7
#define ICES1							6
#define WGM13 							4
#define WGM12							3
#define CS12 							2
#define CS11 							1
#define CS10							0

#define TCNT1		*((volatile u16*)(0x4C))

#define OCR1A		*((volatile u16*)(0x4A))
#define OCR1B		*((volatile u16*)(0x48))
#define ICR1		*((volatile u16*)(0x46))

typedef enum
{
	TIMER1_STOP = 0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	TIMER1_EXTERNAL_FALLING,
	TIMER1_EXTERNAL_RISING
}TIMER1Scaler_t;

/* Macros for timer1 modes */
#define TIMER1_NORMAL_MODE  							0
#define TIMER1_PWM_PHASE_CORRECT_8_bit                  1
#define TIMER1_PWM_PHASE_CORRECT_9_bit                  2
#define TIMER1_PWM_PHASE_CORRECT_10_bit                 3
#define TIMER1_CTC_OCR1A                                4
#define TIMER1_FAST_PWM_8_bit                           5
#define TIMER1_FAST_PWM_9_bit                           6
#define TIMER1_FAST_PWM_10_bit                          7
#define TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1     8
#define TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A    9
#define TIMER1_PWM_PHASE_CORRECT_ICR1                   10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A                  11
#define TIMER1_CTC_ICR1                                 12
/* reserved												13 */
#define TIMER1_FAST_PWM_ICR1                            14
#define TIMER1_FAST_PWM_OCR1A                           15


/*             			OUTPUT COMPARE PIN (OC1A) BEHAVIOUR				           */
#define TIMER1_OC1A_DISCONNECTED				0
#define TIMER1_TOGGLE_OC1A						1
#define TIMER1_CLEAR_OC1A_NON_INVERTING			2
#define TIMER1_SET_OC1A_INVERTING				3

/*             			OUTPUT COMPARE PIN (OC1B) BEHAVIOUR				           */
#define TIMER1_OC1B_DISCONNECTED				0
#define TIMER1_TOGGLE_OC1B						1
#define TIMER1_CLEAR_OC1B_NON_INVERTING			2
#define TIMER1_SET_OC1B_INVERTING				3

/*  compare register  */
#define CMP_1A									0
#define CMP_1B									1

/* Top value */
#define SET_ON_ICR1  							0
#define SET_ON_OCR1A 							1


#define DISABLE									0
#define ENABLE									1

#define ICU_RISING_EDGE							1
#define ICU_FALLING_EDGE						0

/* Timer1 vectors */
#define TIMER1_CAPT				__vector_6
#define TIMER1_COMPA			__vector_7
#define TIMER1_COMPB			__vector_8
#define TIMER1_OVF				__vector_9
/***************************** Timer2 ****************************************************/
/* Timer/Counter Control Register – TCCR2 */
#define TCCR2		*((volatile u8*)(0x45))
/* TCCR2 bits */
#define FOC2 							7
#define WGM20 							6
#define COM21 							5
#define COM20 							4
#define WGM21 							3
#define CS22 							2
#define CS21 							1
#define CS20							0


#define TCNT2		*((volatile u8*)(0x44))
#define OCR2		*((volatile u8*)(0x43))

/* Macros for timer2 modes */
#define TIMER2_NORMAL_MODE  			0
#define	TIMER2_PHASECORRECT_MODE		1
#define	TIMER2_CTC_MODE					2
#define	TIMER2_FASTPWM_MODE				3

typedef enum
{
	TIMER2_STOP = 0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_32,
	TIMER2_SCALER_64,
	TIMER2_SCALER_128,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024
}TIMER2Scaler_t;

/* Timer2 CTC OC2 PIN */
#define TIMER2_OC2_PIN_DISCONNECTED			0
#define TIMER2_OC2_PIN_TOGGLE				1
#define TIMER2_OC2_PIN_CLR_NON_INVERTING	2
#define TIMER2_OC2_PIN_SET_INVERTING		3

/* Timer2 vectors */
#define TIMER2_OVF					__vector_5
#define TIMER2_COMP					__vector_4
#endif /* MTIMER_PRIVATE_H_ */
