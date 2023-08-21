#include "MDIO_Interface.h"
#include "MDIO_Private.h"

Error_state MDIO_Error_state_SetPinDirection(u8 Copy_u8_PortNumber, u8 Copy_u8_PinNumber, u8 Copy_u8_PinDirection)
{
	Error_state LOC_Error_state_ReturnState = OK;
	/* error handling */
	if( ((Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7)) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		if( Copy_u8_PinDirection == PIN_OUTPUT )
		{
			SET_BIT(*DDR[Copy_u8_PortNumber], Copy_u8_PinNumber);
		}

		else if( Copy_u8_PinDirection == PIN_INPUT )
		{
			CLR_BIT(*DDR[Copy_u8_PortNumber], Copy_u8_PinNumber);
		}

		else
		{
			LOC_Error_state_ReturnState = NOK;
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

	if( ((Copy_u8_PortDirection == PORT_INPUT) || (Copy_u8_PortDirection == PORT_OUTPUT)) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		*DDR[Copy_u8_PortNumber] = Copy_u8_PortDirection;
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

	if( ((Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7)) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		if( Copy_u8_PinValue == PIN_HIGH )
		{
			SET_BIT(*PORT[Copy_u8_PortNumber], Copy_u8_PinNumber);
		}
		else if( Copy_u8_PinValue == PIN_LOW )
		{
			CLR_BIT(*PORT[Copy_u8_PortNumber], Copy_u8_PinNumber);
		}
		else
		{
			LOC_Error_state_ReturnState = NOK;
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

	if( ((Copy_u8_PortValue >= 0) && (Copy_u8_PortValue <= 255)) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		*PORT[Copy_u8_PortNumber] = Copy_u8_PortValue;
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

	if( ((Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7)) && (P_u8_PinValue != NULL_PTR) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		*P_u8_PinValue = GET_BIT(*PIN[Copy_u8_PortNumber], Copy_u8_PinNumber);
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

	if( ((Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7)) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		TOGGLE_BIT(*PORT[Copy_u8_PortNumber], Copy_u8_PinNumber);
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

	if( ((Copy_u8_PinNumber >= PIN0) && (Copy_u8_PinNumber <= PIN7)) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		SET_BIT(*PORT[Copy_u8_PortNumber], Copy_u8_PinNumber);
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

	if( (Copy_u8_PinPos == PIN_LSB) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		if( Copy_u8_PinDirection == PIN_OUTPUT )
		{
			*DDR[Copy_u8_PortNumber] = ( (*DDR[Copy_u8_PortNumber] & 0xF0) | (0x0F) );
		}

		else if( Copy_u8_PinDirection == PIN_INPUT )
		{
			*DDR[Copy_u8_PortNumber] = ( (*DDR[Copy_u8_PortNumber] & 0xF0) | (0x00) );
		}

		else
		{
			LOC_Error_state_ReturnState = NOK;
		}
	}

	else if( (Copy_u8_PinPos == PIN_MSB) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{
		if( Copy_u8_PinDirection == PIN_OUTPUT )
		{
			*DDR[Copy_u8_PortNumber] = ( (0xF0) | ( *DDR[Copy_u8_PortNumber] & 0x0F) );
		}

		else if( Copy_u8_PinDirection == PIN_INPUT )
		{
			*DDR[Copy_u8_PortNumber] = ( (0x00) | ( *DDR[Copy_u8_PortNumber] & 0x0F) );
		}

		else
		{
			LOC_Error_state_ReturnState = NOK;
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

	if( (Copy_u8_PinPos == PIN_LSB) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{

		*PORT[Copy_u8_PortNumber] = ( (*PORT[Copy_u8_PortNumber] & 0xF0) | (Copy_u8_PinValues & 0x0F) );
	}

	else if( (Copy_u8_PinPos == PIN_MSB) && ((Copy_u8_PortNumber >= MDIO_PORTA) && (Copy_u8_PortNumber <= MDIO_PORTD)) )
	{

		*PORT[Copy_u8_PortNumber] = ( (Copy_u8_PinValues << 4) | (*PORT[Copy_u8_PortNumber] & 0x0F) );
	}

	else
	{
		LOC_Error_state_ReturnState = NOK;
	}

	return LOC_Error_state_ReturnState;
}
