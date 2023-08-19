void HKPD_Vid_init(void)
{
	/* set Row pins as an input */
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN0, PIN_INPUT);
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN1, PIN_INPUT);
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN2, PIN_INPUT);
	MDIO_Error_state_SetPinDirection(ROW_PORT, ROW_PIN3, PIN_INPUT);

}

u8 HKPD_u8_GetKeyPressed(void)
{
}
