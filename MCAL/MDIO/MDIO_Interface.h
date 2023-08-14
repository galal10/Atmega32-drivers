#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITS.h"

/* Copy_u8_PortNumber Options */
#define MDIO_PORTA	0
#define MDIO_PORTB	1
#define MDIO_PORTC	2
#define MDIO_PORTD	3

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
Error_state MDIO_Error_state_SetNibbleDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection);

/* Set Nibble Values Function */
Error_state MDIO_Error_state_SetNibbleValues(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinValues);

#endif /* MDIO_INTERFACE_H_ */