#include "HCLCD_Interface.h"
#include "HCLCD_Private.h"
#include "HCLCD_Config.h"
#include <util/delay.h>

static void HCLCD_Vid_Kick()
{
	/* Send Enable */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_LOW);
	_delay_ms(2);
	MDIO_Error_state_SetPinValue(CONTROL_PORT, E, PIN_HIGH);
}

void HCLCD_Vid_Write_Command_8Bits(u8 Copy_u8_Command)
{
	/* select Command register ==> RS = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_LOW);
	/* select Write mode ==> RW = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RW, PIN_LOW);
	/* send command on port data */
	MDIO_Error_state_SetPortValue(DATA_PORT, Copy_u8_Command);
	/* Enable method */
	HCLCD_Vid_Kick();
}

void HCLCD_Vid_Write_Command_4Bits(u8 Copy_u8_Command)
{
	/* select Command register ==> RS = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_LOW);
	/* select Write mode ==> RW = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RW, PIN_LOW);

	if( (Copy_u8_Command == FUNCTION_SET_4BITS_2LINES) || (Copy_u8_Command== FUNCTION_SET_4BITS_1LINES) )
	{
		/* According to data sheet that send the MSB 2 times of Function set 4 bit mode command */
		MDIO_Error_state_SetNibbleValues(DATA_PORT, MODE_4BIT_PINS, ((Copy_u8_Command & 0xF0 ) >> DATA_SHIFT) );
		HCLCD_Vid_Kick();
	}

	/* send 4MSB command on port data */
	MDIO_Error_state_SetNibbleValues(DATA_PORT, MODE_4BIT_PINS, ((Copy_u8_Command & 0xF0 ) >> DATA_SHIFT) );
	/* Enable method */
	HCLCD_Vid_Kick();
	/* send 4LSB command on port data */
	MDIO_Error_state_SetNibbleValues(DATA_PORT, MODE_4BIT_PINS, (Copy_u8_Command & 0x0F) );
	/* Enable method */
	HCLCD_Vid_Kick();
}

void HCLCD_Vid_8Bits_Init(void)
{
	/* LCD Data and Control port initialization */
	MDIO_Error_state_SetPortDirection(DATA_PORT, PORT_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, RS, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, RW, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, E, PIN_OUTPUT);
	/* Wait for more than 30ms */
	_delay_ms(30);
	/* send function set command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_FUNCTION_SET);
	/* wait 39 µs */
	_delay_ms(1);
	/* Display ON/OFF command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_DISPLAY_ON_OFF);
	/* wait 39 µs */
	_delay_ms(1);
	/* Display Clear command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_DISPLAY_CLEAR);
	/* Wait for more than 1.53ms */
	_delay_ms(2);
	/* Entry mode Command */
	HCLCD_Vid_Write_Command_8Bits(HCLCD_ENTRY_MODE);
}

void HCLCD_Vid_4Bits_Init(void)
{
	/* LCD MSB Data and Control port initialization */
	MDIO_Error_state_SetNibbleDirection(DATA_PORT, MODE_4BIT_PINS, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, RS, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, RW, PIN_OUTPUT);
	MDIO_Error_state_SetPinDirection(CONTROL_PORT, E, PIN_OUTPUT);
	/* Wait for more than 30ms */
	_delay_ms(30);
	/* send function set command */
	HCLCD_Vid_Write_Command_4Bits(HCLCD_FUNCTION_SET);
	/* wait 39 µs */
	_delay_ms(1);
	/* Display ON/OFF command */
	HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_ON_OFF);
	/* wait 39 µs */
	_delay_ms(1);
	/* Display Clear command */
	HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);
	/* Wait for more than 1.53ms */
	_delay_ms(2);
	/* Entry mode Command */
	HCLCD_Vid_Write_Command_4Bits(HCLCD_ENTRY_MODE);
}

void HCLCD_Vid_Write_Char_8Bits(u8 Copy_u8_Data)
{
	/* select Data register ==> RS = 1 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_HIGH);
	/* select Write mode ==> RW = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RW, PIN_LOW);
	/* send Data on port data */
	MDIO_Error_state_SetPortValue(DATA_PORT, Copy_u8_Data);
		/* Enable method */
	HCLCD_Vid_Kick();
}

void HCLCD_Vid_Write_Char_4Bits(u8 Copy_u8_Data)
{
	/* select Data register ==> RS = 1 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RS, PIN_HIGH);
	/* select Write mode ==> RW = 0 */
	MDIO_Error_state_SetPinValue(CONTROL_PORT, RW, PIN_LOW);
	/* send 4MSB Data on port data */
	MDIO_Error_state_SetNibbleValues(DATA_PORT, MODE_4BIT_PINS, ((Copy_u8_Data & 0xF0) >> DATA_SHIFT) );
	/* Enable method */
	HCLCD_Vid_Kick();
	/* send 4LSB Data on port data */
	MDIO_Error_state_SetNibbleValues(DATA_PORT, MODE_4BIT_PINS, (Copy_u8_Data & 0x0F) );
	/* Enable method */
	HCLCD_Vid_Kick();
}

void HCLCD_Vid_Write_String_8Bits(u8 *PCopy_u8_String)
{
	u8 Loc_u8_count = 0;
	while(*PCopy_u8_String)
	{
		HCLCD_Vid_Write_Char_8Bits(*PCopy_u8_String++);
		Loc_u8_count++;

		if(Loc_u8_count == LINE1_OFFSET16) /* end offset of line 1 */
		{
			HCLCD_Vid_SetPosition_8Bits(HCLCD_LINE2, POSITION_0);
		}
		else if(Loc_u8_count == LINE2_OFFSET32) /* end offset of line 2 */
		{
			HCLCD_Vid_Write_Command_8Bits(HCLCD_DISPLAY_CLEAR);
			HCLCD_Vid_SetPosition_8Bits(HCLCD_LINE1, POSITION_0);
			Loc_u8_count = 0;
		}
	}
}

void HCLCD_Vid_Write_String_4Bits(u8 *PCopy_u8_String)
{
	u8 Loc_u8_count = 0;
	while(*PCopy_u8_String)
	{
		HCLCD_Vid_Write_Char_4Bits(*PCopy_u8_String++);
		Loc_u8_count++;

		if(Loc_u8_count == LINE1_OFFSET16) /* end offset of line 1 */
		{
			HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE2, POSITION_0);
		}
		else if(Loc_u8_count == LINE2_OFFSET32) /* end offset of line 2 */
		{
			HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);
			HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE1, POSITION_0);
			Loc_u8_count = 0;
		}
	}
}

void HCLCD_Vid_Write_Number_8Bits(u32 Copy_u32_Number)
{
	u8 ARR_Digits[10];
	u8 LOC_Count = 0;

	if(Copy_u32_Number)
	{
		while(Copy_u32_Number)
		{
			ARR_Digits[LOC_Count] = Copy_u32_Number%10;
			Copy_u32_Number /= 10;
			LOC_Count++;
		}
		for(s8 i = LOC_Count-1; i >= 0; i--)
		{
			HCLCD_Vid_Write_Char_8Bits(ARR_Digits[i]+'0');
		}
	}

	else
	{
		HCLCD_Vid_Write_Char_8Bits('0');
	}
}

void HCLCD_Vid_Write_Number_4Bits(u32 Copy_u32_Number)
{
	u8 ARR_Digits[10];
	u8 LOC_Count = 0;

	if(Copy_u32_Number)
	{
		while(Copy_u32_Number)
		{
			ARR_Digits[LOC_Count] = Copy_u32_Number%10;
			Copy_u32_Number /= 10;
			LOC_Count++;
		}
		for(s8 i = LOC_Count-1; i >= 0; i--)
		{
			HCLCD_Vid_Write_Char_4Bits(ARR_Digits[i]+'0');
		}
	}

	else
	{
		HCLCD_Vid_Write_Char_4Bits('0');
	}
}

void HCLCD_Vid_SetPosition_8Bits(u8 Copy_u8_LineNumber, u8 Copy_u8_PositionNumber)
{
	if(	(Copy_u8_LineNumber == HCLCD_LINE1) && ( (Copy_u8_PositionNumber >= 0) && ( Copy_u8_PositionNumber < 16) ) )
	{
		HCLCD_Vid_Write_Command_8Bits(LCD_BEGIN_AT_FIRST_ROW+Copy_u8_PositionNumber);
	}

	else if( (Copy_u8_LineNumber == HCLCD_LINE2) && ( (Copy_u8_PositionNumber >= 0) && (Copy_u8_PositionNumber < 16) ) )
	{
		HCLCD_Vid_Write_Command_8Bits(LCD_BEGIN_AT_SECOND_ROW+Copy_u8_PositionNumber);
	}

	else
	{
		/* Do Nothing */
	}
}

void HCLCD_Vid_SetPosition_4Bits(u8 Copy_u8_LineNumber, u8 Copy_u8_PositionNumber)
{
	if(	(Copy_u8_LineNumber == HCLCD_LINE1) && ( (Copy_u8_PositionNumber >= 0) && ( Copy_u8_PositionNumber < 16) ) )
	{
		HCLCD_Vid_Write_Command_4Bits(LCD_BEGIN_AT_FIRST_ROW+Copy_u8_PositionNumber);
	}

	else if( (Copy_u8_LineNumber == HCLCD_LINE2) && ( (Copy_u8_PositionNumber >= 0) && (Copy_u8_PositionNumber < 16) ) )
	{
		HCLCD_Vid_Write_Command_4Bits(LCD_BEGIN_AT_SECOND_ROW+Copy_u8_PositionNumber);
	}

	else
	{
		/* Do Nothing */
	}
}
