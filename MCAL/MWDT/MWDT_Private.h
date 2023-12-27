/*
 * MWGT_Private.h
 *
 *  Created on: Dec 17, 2023
 *      Author: galal
 */

#ifndef MWDT_PRIVATE_H_
#define MWDT_PRIVATE_H_

#define WDTCR			*((volatile u8*)0x41)
#define WDP0			0
#define WDP1			1
#define WDP2			2
#define WDE				3
#define WDTOE			4



#define PreScaler_Mask			0xF8

#define WDT_16ms_5V				0
#define WDT_33ms_5V				1
#define WDT_65ms_5V				2
#define WDT_130ms_5V			3
#define WDT_260ms_5V			4
#define WDT_520ms_5V			5
#define WDT_1s_5V				6
#define WDT_2s_5V				7

#endif /* MCAL_MWDT_MWDT_PRIVATE_H_ */
