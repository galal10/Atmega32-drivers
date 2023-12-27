/*
 * MADC_Interface.h
 *
 *  Created on: Dec 23, 2023
 *      Author: galal
 */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"

/* ADC Channels Options */
#define CHANNEL_0		0
#define CHANNEL_1		1
#define CHANNEL_2		2
#define CHANNEL_3		3
#define CHANNEL_4		4
#define CHANNEL_5		5
#define CHANNEL_6		6
#define CHANNEL_7		7

/* ADC Initialization */
void MADC_Vid_Init(void);
/* ADC Start Conversion ==> Polling, Return ADC value */
u16 MADC_u16_StartConversion(u8 Copy_u8_Channel);

#endif /* MADC_INTERFACE_H_ */
