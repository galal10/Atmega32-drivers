#include "HLED_Interface.h"

void HLED_Vid_Init(LED_t *Copy_Led)
{
	MDIO_Error_state_SetPinDirection(Copy_Led->Copy_u8_Port, Copy_Led->Copy_u8_Pin, PIN_OUTPUT);
}

void HLED_Vid_Led_on(LED_t *Copy_Led)
{
	MDIO_Error_state_SetPinValue(Copy_Led->Copy_u8_Port, Copy_Led->Copy_u8_Pin, PIN_HIGH);
}

void HLED_Vid_Led_off(LED_t *Copy_Led)
{
	MDIO_Error_state_SetPinValue(Copy_Led->Copy_u8_Port, Copy_Led->Copy_u8_Pin, PIN_LOW);
}

void HLED_Vid_Led_Toggle(LED_t *Copy_Led)
{
	MDIO_Error_state_TogglePinValue(Copy_Led->Copy_u8_Port, Copy_Led->Copy_u8_Pin);
}
