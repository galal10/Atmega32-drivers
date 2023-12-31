#ifndef HCLCD_PRIVATE_H_
#define HCLCD_PRIVATE_H_

#define FUNCTION_SET_8BITS_2LINES			0x38
#define FUNCTION_SET_8BITS_1LINES			0x34
#define FUNCTION_SET_4BITS_2LINES			0x28
#define FUNCTION_SET_4BITS_1LINES			0x24

#define DISPLAY_ON_CURSOR_ON_BLINKING_ON	0x0F
#define DISPLAY_ON_CURSOR_ON_BLINKING_OFF	0x0E
#define DISPLAY_ON_CURSOR_OFF				0x0C
#define DISPLAY_OFF							0x08

#define ENTRY_MODE_INCREASE_WITH_SHIFT		0x07	/* Shift Left */
#define ENTRY_MODE_INCREASE					0x06
#define ENTRY_MODE_DECREASE_WITH_SHIFT		0x05	/* Shrift Right */
#define ENTRY_MODE_DECREASE					0x04

#define LCD_BEGIN_AT_FIRST_ROW 				0x80	/* 128 */
#define LCD_BEGIN_AT_SECOND_ROW 			0xC0	/* 192 */

#define LINE1_OFFSET16						16
#define LINE2_OFFSET32						32

#define POSITION_0							0

#define DATA_SHIFT							4

#endif /* HCLCD_PRIVATE_H_ */
