#include "MDIO_Interface.h"
#include "MDIO_Private.h"

Error_state MDIO_Error_state_SetPinDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( (Copy_u8_PinNumber >= 0) && (Copy_u8_PinNumber < 8) )
	{	
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					SET_BIT(DDRA, Copy_u8_PinNumber);
				}
			
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					CLR_BIT(DDRA, Copy_u8_PinNumber);
				}
			
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			case MDIO_PORTB:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					SET_BIT(DDRB, Copy_u8_PinNumber);
				}
			
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					CLR_BIT(DDRB, Copy_u8_PinNumber);
				}
			
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			case MDIO_PORTC:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					SET_BIT(DDRC, Copy_u8_PinNumber);
				}
			
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					CLR_BIT(DDRC, Copy_u8_PinNumber);
				}
			
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTD:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					SET_BIT(DDRD, Copy_u8_PinNumber);
				}
			
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					CLR_BIT(DDRD, Copy_u8_PinNumber);
				}
			
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			default :
				LOC_Error_state_ReturnState = NOK;
				break;
		}
	}
	
	else
	{
		LOC_Error_state_ReturnState = NOK;
	}
	
	return LOC_Error_state_ReturnState;

}

Error_state MDIO_Error_state_SetPortDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PortDirection)
{
	Error_state LOC_Error_state_ReturnState = OK;

	return LOC_Error_state_ReturnState;
}