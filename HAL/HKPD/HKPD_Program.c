void HKPD_Vid_init(void)
{
	/* set Row pins as an input */
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN0, PIN_INPUT);
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN1, PIN_INPUT);
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN2, PIN_INPUT);
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN3, PIN_INPUT);

	/* set column pins as an output */
	MDIO_Error_state_SetPinDirection(COL_PORT, COL_PIN0, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(COL_PORT, COL_PIN1, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(COL_PORT, COL_PIN2, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(COL_PORT, COL_PIN3, PIN_OUTPUT);

	/* Activate pull up resistor for row pins */
	MDIO_Error_state_SetPinValue(ROW_PORT, ROW_PIN0, PIN_HIGH);
	MDIO_Error_state_SetPinValue(ROW_PORT, ROW_PIN1, PIN_HIGH);
	MDIO_Error_state_SetPinValue(ROW_PORT, ROW_PIN2, PIN_HIGH);
	MDIO_Error_state_SetPinValue(ROW_PORT, ROW_PIN3, PIN_HIGH);

	/* init columns pins by ones */
	MDIO_Error_state_SetPinValue(COL_PORT, COL_PIN0, PIN_HIGH);
	MDIO_Error_state_SetPinValue(COL_PORT, COL_PIN1, PIN_HIGH);
	MDIO_Error_state_SetPinValue(COL_PORT, COL_PIN2, PIN_HIGH);
	MDIO_Error_state_SetPinValue(COL_PORT, COL_PIN3, PIN_HIGH);
}

/* KPD Get pressed */
u8 HKPD_u8_GetKeyPressed(void)
{
	u8 LOC_u8_RowCount;
	u8 LOC_u8_ColCount;
	/* initialize the switch status to NOT PRESSED */
	u8 LOC_u8_RrturnValue = NOT_PRESSED;
	u8 LOC_u8_PinState ;

	/* looping on columns of the keypad */
	for( LOC_u8_ColCount = COL_INIT; LOC_u8_ColCount < COL_END; LOC_u8_ColCount++ )
	{
		/* select Column */
		MDIO_Error_state_SetPinValue(COL_PORT, LOC_u8_ColCount, PIN_LOW);
		/* loop to read all row pins */
		for( LOC_u8_RowCount = ROW_INIT; LOC_u8_RowCount < ROW_END; LOC_u8_RowCount++ )
		{
			/* check the status of switch */
			MDIO_Error_state_GetPinValue(ROW_PORT, LOC_u8_RowCount, &LOC_u8_PinState);
			if( LOC_u8_PinState == PIN_LOW )
			{
				/* get the value of the current pressed switch */
				LOC_u8_RrturnValue = KPD_u8_SwitchVal[LOC_u8_ColCount-COL_INIT][LOC_u8_RowCount-ROW_INIT];
}
