/*
 * MTIM_Interface.h
 *
 *  Created on: Aug 25, 2023
 *      Author: galal
 */

#ifndef MTIMERS_INTERFACE_H_
#define MTIMERS_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"

/* Copy_u8_TimerID options */
typedef enum
{
	TIMER0 = 0,
	TIMER1,
	TIMER2
}TimerID_t;

/* Copy_u8_InterruptType options: */
typedef enum
{
	TIMER0_OVF_INT = 0,
	TIMER0_CTC_INT,
	TIMER1_OVF_INT = 0,
	TIMER1_CTC1A_INT,
	TIMER1_CTC1B_INT,
	TIMER1_ICU_INT,
	TIMER2_OVF_INT = 0,
	TIMER2_CTC_INT
}InterruptType_t;

typedef enum
{
	ICU_FALLING = 0,
	ICU_RISING
}ICU_Trigger_t;

/* Timer0 Initialization */
void MTIMER0_Vid_Init(void);
/* Timer1 Initialization */
void MTIMER1_Vid_Init(void);
/* Timer2 Initialization */
void MTIMER2_Vid_Init(void);

void MTIMERS_Vid_StopTimer(u8 Copy_u8_TimerID);
/* Set Preload Function */
void MTIMERS_Vid_SetPreLoad(u8 Copy_u8_TimerID, u16 Copy_u16_Preload);
/* Set CTC value Function */
void MTIMERS_Vid_SetCTCValue(u8 Copy_u8_TimerID, u16 Copy_u16_CTCValue);

void MTIMER1_Vid_SetTopValue(u16 Copy_u16_TopValue);

void MTIMER1_Vid_SetICUTrigger(ICU_Trigger_t ICU_trigger);

u16 MTIMER1_u16_GetCaptureUnitValue(void);

void MTIMERS_Vid_EnableInterrupt(u8 Copy_u8_TimerID, u8 Copy_u8_InterruptType);

void MTIMERS_Vid_DisableInterrupt(u8 Copy_u8_TimerID, u8 Copy_u8_InterruptType);
/* callBack functions */
void MTIMERS_Vid_SetCallBack(u8 Copy_u8_TimerID, u8 Copy_u8_InterruptType, void (*Copy_Vid_CallBack)(void));

#endif /* MTIMERS_INTERFACE_H_ */
