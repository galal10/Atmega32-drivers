#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITS.h"

/* Copy_u8_PinDirection Options */
#define PIN_INPUT	0
#define PIN_OUTPUT	1

/* Copy_u8_PortDirection Options */
#define PORT_INPUT	0x00
#define PORT_OUTPUT	0xFF

/* Copy_u8_PinValue Options */
#define PIN_LOW		0
#define	PIN_HIGH	1

/* Copy_u8_PinPos Options */
#define PIN_LSB		0
#define PIN_MSB		1

/* Copy_u8_PortNumber Options */
typedef enum
{
	MDIO_PORTA = 0,
	MDIO_PORTB,
	MDIO_PORTC,
	MDIO_PORTD
}MDIO_PORT;

/* Copy_u8_PinNumber Options */
typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Pin_t;


/* Set Pin Direction Function */
Error_state MDIO_Error_state_SetPinDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection);

/* Set Port Direction Function */
Error_state MDIO_Error_state_SetPortDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PortDirection);

/* Set Pin Value Function */
Error_state MDIO_Error_state_SetPinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinValue);

/* Set Port Value Function */
Error_state MDIO_Error_state_SetPortValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PortValue);

/* Get Pin Value Function */
Error_state MDIO_Error_state_GetPinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 *P_u8_PinValue);

/* Toggle Pin Value Function */
Error_state MDIO_Error_state_TogglePinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber);

/* Activate Pull up Resistor Function */
Error_state MDIO_Error_state_ActivatePullUpResistor(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber);

/* Set Nibble Direction Function */
Error_state MDIO_Error_state_SetNibbleDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinPos, u8 Copy_u8_PinDirection);

/* Set Nibble Values Function */
Error_state MDIO_Error_state_SetNibbleValues(u8 Copy_u8_PortNumber, u8 Copy_u8_PinPos, u8 Copy_u8_PinValues);

#endif /* MDIO_INTERFACE_H_ */
