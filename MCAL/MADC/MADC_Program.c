/*
 * MADC_Program.c
 *
 *  Created on: Dec 23, 2023
 *      Author: galal
 */

#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MADC_Private.h"
#include "MADC_Config.h"

/* ADC Initialization */
void MADC_Vid_Init(void)
{
	/* Cleared voltage reference bits */
	ADMUX &= ADC_VREF_MASK;
	/* Select V-Ref */
	ADMUX |= ADC_REF_VOLT << REFS0;

	/* Set PreScaler */
	ADCSRA &= ADC_SCALE_MASK;
	ADCSRA |= ADC_PRESCALER;

	/* Select Left or Right Adjust */
#if ADC_ADJUST == ADC_LEFT_ADJSUT
	SET_BIT(ADMUX, ADLAR);

#elif ADC_ADJUST == ADC_RIGHT_ADJSUT
	CLR_BIT(ADMUX, ADLAR);

#else
	#error "ADC adjust options is not valid"

#endif

	/* Enable ADC */
	SET_BIT(ADCSRA, ADEN);
}
/* ADC Start Conversion ==> Polling, Return ADC value */
u16 MADC_u16_StartConversion(u8 Copy_u8_Channel)
{
	/* Select Channel */
	ADMUX &= ADC_CHANNEL_MASK;
	ADMUX |= Copy_u8_Channel;

	/* Enable Start Conversion */
	SET_BIT(ADCSRA, ADSC);

	/* Wait until ADIF is set */
	while(GET_BIT(ADCSRA, ADIF) == 0);

	/* Read the Register value */
	return ADCD;
}
