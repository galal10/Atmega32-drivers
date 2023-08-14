#include "MDIO_Interface.h"
#include "MDIO_Private.h"

Error_state MDIO_Error_state_SetPinDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( (Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7) )
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
	
	if( (Copy_u8_PortDirection == PORT_INPUT) || (Copy_u8_PortDirection == PORT_OUTPUT) )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				DDRA = Copy_u8_PortDirection;
				break;

			case MDIO_PORTB:
				DDRB = Copy_u8_PortDirection;
				break;
				
			case MDIO_PORTC:
				DDRC = Copy_u8_PortDirection;
				break;
				
			case MDIO_PORTD:
				DDRD = Copy_u8_PortDirection;
				break;
				
			default:
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

Error_state MDIO_Error_state_SetPinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinValue)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( (Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7) )
	{
	
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				if( Copy_u8_PinValue == PIN_HIGH )
				{
					SET_BIT(PORTA, Copy_u8_PinNumber);
				}
				else if( Copy_u8_PinValue == PIN_LOW )
				{
					CLR_BIT(PORTA, Copy_u8_PinNumber);
				}
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			case MDIO_PORTB:
				if( Copy_u8_PinValue == PIN_HIGH )
				{
					SET_BIT(PORTB, Copy_u8_PinNumber);
				}
				else if( Copy_u8_PinValue == PIN_LOW )
				{
					CLR_BIT(PORTB, Copy_u8_PinNumber);
				}
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			case MDIO_PORTC:
				if( Copy_u8_PinValue == PIN_HIGH )
				{
					SET_BIT(PORTC, Copy_u8_PinNumber);
				}
				else if( Copy_u8_PinValue == PIN_LOW )
				{
					CLR_BIT(PORTC, Copy_u8_PinNumber);
				}
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			case MDIO_PORTD:
				if( Copy_u8_PinValue == PIN_HIGH )
				{
					SET_BIT(PORTD, Copy_u8_PinNumber);
				}
				else if( Copy_u8_PinValue == PIN_LOW )
				{
					CLR_BIT(PORTD, Copy_u8_PinNumber);
				}
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
				
			default:
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

Error_state MDIO_Error_state_SetPortValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PortValue)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( (Copy_u8_PortValue >= 0) && (Copy_u8_PortValue <= 255) )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				PORTA = Copy_u8_PortValue;
				break;

			case MDIO_PORTB:
				PORTB = Copy_u8_PortValue;
				break;

			case MDIO_PORTC:
				PORTC = Copy_u8_PortValue;
				break;

			case MDIO_PORTD:
				PORTD = Copy_u8_PortValue;
				break;			
				
			default:
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

Error_state MDIO_Error_state_GetPinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 *P_u8_PinValue)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( ((Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7)) && (P_u8_PinValue != NULL) )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				*P_u8_PinValue = GET_BIT(PINA, Copy_u8_PinNumber);
				break;
			
			case MDIO_PORTB:
				*P_u8_PinValue = GET_BIT(PINB, Copy_u8_PinNumber);
				break;

			case MDIO_PORTC:
				*P_u8_PinValue = GET_BIT(PINC, Copy_u8_PinNumber);
				break;

			case MDIO_PORTD:
				*P_u8_PinValue = GET_BIT(PIND, Copy_u8_PinNumber);
				break;

			default:
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

Error_state MDIO_Error_state_TogglePinValue(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( (Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7) )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				TOGGLE_BIT(PORTA, Copy_u8_PinNumber);
				break;
				
			case MDIO_PORTB:
				TOGGLE_BIT(PORTB, Copy_u8_PinNumber);
				break;

			case MDIO_PORTC:
				TOGGLE_BIT(PORTC, Copy_u8_PinNumber);
				break;

			case MDIO_PORTD:
				TOGGLE_BIT(PORTD, Copy_u8_PinNumber);
				break;

			default:
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

Error_state MDIO_Error_state_ActivatePullUpResistor(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( (Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7) )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				SET_BIT(PORTA, Copy_u8_PinNumber);
				break;
			
			case MDIO_PORTB:
				SET_BIT(PORTB, Copy_u8_PinNumber);
				break;

			case MDIO_PORTC:
				SET_BIT(PORTC, Copy_u8_PinNumber);
				break;
				
			case MDIO_PORTD:
				SET_BIT(PORTD, Copy_u8_PinNumber);
				break;
				
			default:
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

Error_state MDIO_Error_state_SetNibbleDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinPos, u8 Copy_u8_PinDirection)
{
	Error_state LOC_Error_state_ReturnState = OK;
	
	if( Copy_u8_PinPos == PIN_LSB )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRA = ( (DDRA & 0xF0) | (0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRA = ( (DDRA & 0xF0) | (0x00) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTB:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRB = ( (DDRB & 0xF0) | (0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRB = ( (DDRB & 0xF0) | (0x00) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTC:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRC = ( (DDRC & 0xF0) | (0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRC = ( (DDRC & 0xF0) | (0x00) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTD:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRD = ( (DDRD & 0xF0) | (0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRD = ( (DDRD & 0xF0) | (0x00) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
			
			default:
				LOC_Error_state_ReturnState = NOK;
				break;
		}
	}

	else if( Copy_u8_PinPos == PIN_MSB )
	{
		switch( Copy_u8_PortNumber )
		{
			case MDIO_PORTA:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRA = ( (0xF0) | ( DDRA & 0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRA = ( (0x00) | ( DDRA & 0x0F) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTB:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRB = ( (0xF0) | ( DDRB & 0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRB = ( (0x00) | ( DDRB & 0x0F) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTC:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRC = ( (0xF0) | ( DDRC & 0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRC = ( (0x00) | ( DDRC & 0x0F) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;

			case MDIO_PORTD:
				if( Copy_u8_PinDirection == PIN_OUTPUT )
				{
					DDRD = ( (0xF0) | ( DDRD & 0x0F) );
				}
				
				else if( Copy_u8_PinDirection == PIN_INPUT )
				{
					DDRD = ( (0x00) | ( DDRD & 0x0F) );
				}
				
				else
				{
					LOC_Error_state_ReturnState = NOK;
				}
				break;
			
			default:
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

Error_state MDIO_Error_state_SetNibbleValues(u8 Copy_u8_PortNumber, u8 Copy_u8_PinPos, u8 Copy_u8_PinValues)
{
	Error_state LOC_Error_state_ReturnState = OK;

	if( Copy_u8_PinPos == PIN_LSB )
	{

	}

	else if( Copy_u8_PinPos == PIN_MSB )
	{

	}

	else
	{
		LOC_Error_state_ReturnState = NOK;
	}
	
	return LOC_Error_state_ReturnState;
}