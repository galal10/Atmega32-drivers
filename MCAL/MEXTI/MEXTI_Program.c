/* EXTI0 Initialization */
void MEXTI0_Vid_Init(void)
{
	#if MEXTI0_SET_SENSE_CONTROL == MEXTI_LOW_LEVEL
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

	#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

}
