#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/* Set Pin Direction Function */
Error_state MDIO_Error_state_SetPinDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection);

/* Set Port Direction Function */
Error_state MDIO_Error_state_SetPortDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PortDirection);

/* Set Pin Value Function */
Error_state MDIO_Error_state_SetPinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinValue);

/* Set Port Value Function */
Error_state MDIO_Error_state_SetPortValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PortValue);

#endif /* MDIO_INTERFACE_H_ */