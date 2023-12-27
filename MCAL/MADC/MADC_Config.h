/*
 * MADC_Config.h
 *
 *  Created on: Dec 23, 2023
 *      Author: galal
 */

#ifndef MADC_CONFIG_H_
#define MADC_CONFIG_H_


/* ADC voltage reference Options:
 * 1- Vref_turned_off
 * 2- AVCC_REF_VOLT
 * 3- _2and_Half_V_REF_VOLT
 */
#define ADC_REF_VOLT		AVCC_REF_VOLT


/* ADC PreScaler Options:
 * 1- ADC_2_PRESCALER
 * 2- ADC_4_PRESCALER
 * 3- ADC_8_PRESCALER
 * 4- ADC_16_PRESCALER
 * 5- ADC_32_PRESCALER
 * 6- ADC_64_PRESCALER
 * 7- ADC_128_PRESCALER
 */
#define ADC_PRESCALER		ADC_64_PRESCALER

/* ADC Adjust Options:
 * 1- ADC_LEFT_ADJSUT
 * 2- ADC_RIGHT_ADJSUT
 */
#define ADC_ADJUST			ADC_RIGHT_ADJSUT

#endif /* MADC_CONFIG_H_ */
