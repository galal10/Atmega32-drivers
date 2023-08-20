#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MEXTI_Config.h"
#include "MEXTI_Private.h"
#include "MEXTI_Interface.h"

/* EXTI0 Initialization */
void MEXTI0_Vid_Init(void)
{
	#if MEXTI0_SET_SENSE_CONTROL == MEXTI_LOW_LEVEL
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

	#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

	#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_FALLING_EDGE
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);

	#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_RISING_EDGE
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

	#else
		#error"Sense Control Option is not Valid"

	#endif

	/* Enable EXTI0 in GICR */
	SET_BIT(GICR, INT0);
}

/* EXTI1 Initialization */
void MEXTI1_Vid_Init(void)
{
	#if MEXTI1_SET_SENSE_CONTROL == MEXTI_LOW_LEVEL
		CLR_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);

	#elif MEXTI1_SET_SENSE_CONTROL == MEXTI_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);

	#elif MEXTI1_SET_SENSE_CONTROL == MEXTI_FALLING_EDGE
		CLR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);

	#elif MEXTI1_SET_SENSE_CONTROL == MEXTI_RISING_EDGE
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);

	#else
		#error"Sense Control Option is not Valid"

	#endif

	/* Enable EXTI1 in GICR */
	SET_BIT(GICR, INT1);
}

/* EXTI2 Initialization */
void MEXTI2_Vid_Init(void)
{
	#if MEXTI2_SET_SENSE_CONTROL == MEXTI_FALLING_EDGE
		CLR_BIT(MCUCSR, ISC2);

	#elif MEXTI2_SET_SENSE_CONTROL == MEXTI_RISING_EDGE
		SET_BIT(MCUCSR, ISC2);

	#else
		#error"Sense Control Option is not Valid"

	#endif

	/* Enable EXTI2 in GICR */
	SET_BIT(GICR, INT2);
}

/* Select Sense control Register */
Error_state MEXTI_Vid_SenseControl(u8 Copy_u8_EXTI_ID, MEXTI_SENSE_CONTROL_t Copy_SenseControl)
{
	Error_state LOC_Error_state_ReturnState = OK;
	switch(Copy_u8_EXTI_ID)
	{
	case EXTI0:
		if( (Copy_SenseControl >= LOW_LEVEL) && (Copy_SenseControl <= RISING_EDGE) )
		{
			/* 0xFC = 0b11111100 */
			MCUCR = (MCUCR & 0xFC ) | (Copy_SenseControl<<ISC00);
		}
		else
		{
			LOC_Error_state_ReturnState = NOK;
		}
		break;

	case EXTI1:
		if( (Copy_SenseControl >= LOW_LEVEL) && (Copy_SenseControl <= RISING_EDGE) )
		{
			/* 0xF3 = 0b11110011 */
			MCUCR = (MCUCR & 0xF3) | (Copy_SenseControl<<ISC10);
		}
		else
		{
			LOC_Error_state_ReturnState = NOK;
		}
		break;

	case EXTI2:
}
