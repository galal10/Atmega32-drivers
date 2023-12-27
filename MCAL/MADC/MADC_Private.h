/*
 * MADC_Private.h
 *
 *  Created on: Dec 23, 2023
 *      Author: galal
 */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

/* ADC Multiplexer Selection Register */
#define ADMUX			*((volatile u8*)0x27)
/* ADMUX Bits */
#define REFS1 			7
#define REFS0 			6
#define ADLAR 			5
#define MUX4 			4
#define MUX3 			3
#define MUX2 			2
#define MUX1 			1
#define MUX0			0

/* ADC Control and Status Register A */
#define ADCSRA			*((volatile u8*)0x26)
/* ADCSRA Bits */
#define ADEN 			7
#define ADSC 			6
#define ADATE 			5
#define ADIF 			4
#define ADIE 			3
#define ADPS2 			2
#define ADPS1 			1
#define ADPS0			0

/* The ADC Data Register */
#define ADCD			*((volatile u16*)0x24)

/* Special FunctionIO Register */
#define SFIOR			*((volatile u8*)0x50)
/* SFIOR Bits */
#define ADTS2 			7
#define ADTS1 			6
#define ADTS0			5


#define ADC_SCALE_MASK			0xF8

#define ADC_VREF_MASK			0x3F
/* ADC voltage reference Macros */
#define Vref_turned_off			0
#define AVCC_REF_VOLT			1
#define _2and_Half_V_REF_VOLT	3


/* ADC PreScaler Macros */
#define ADC_2_PRESCALER			1
#define ADC_4_PRESCALER			2
#define ADC_8_PRESCALER			3
#define ADC_16_PRESCALER		4
#define ADC_32_PRESCALER		5
#define ADC_64_PRESCALER		6
#define ADC_128_PRESCALER		7


/* ADC Adjust Macros */
#define ADC_LEFT_ADJSUT			1
#define ADC_RIGHT_ADJSUT		2


#define ADC_CHANNEL_MASK		0xE0

#endif /* MADC_PRIVATE_H_ */
