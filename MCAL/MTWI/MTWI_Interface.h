/*
 * MTWI_Interface.h
 *
 *  Created on: Dec 1, 2023
 *      Author: galal
 */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

/* Master Tx */
#define TWI_MT_START_SUCCESS				0x08
#define TWI_MT_REPATED_START_SUCCESS		0x10
#define TWI_MT_SLA_W_ACK					0x18
#define TWI_MT_SLA_W_NOACK					0x20
#define TWI_MT_DATA_ACK						0x28	/* I Received ACK */
#define TWI_MT_DATA_NOACK					0x30	/* I Received no ACK */
#define TWI_MT_ARBITRATION_LOST				0x38

/* Master Rx */
#define TWI_MR_START_SUCCESS				0x08
#define TWI_MR _REPATED_START_SUCCESS		0x10
#define TWI_MR_SLA_R_ACK					0x40
#define TWI_MR_SLA_R_NOACK					0x48
#define TWI_MR_DATA_ACK						0x50	/* I will send ACK */
#define TWI_MR_DATA_NOACK					0x58	/* I will send no ACK */
#define TWI_MR_ARBITRATION_LOST				0x38


void MTWI_Vid_Init(void);
void MTWI_Vid_SendByte(u8 copy_u8_data);
void MTWI_Vid_SendStart(void);
void MTWI_Vid_SendStop(void);
void MTWI_Vid_ReceiveByte_ACK(u8 *Buffer);
void MTWI_Vid_ReceiveByte_NoACK(u8 *Buffer);
u8 MTWI_u8_GetStatus(void);


#endif /* MTWI_INTERFACE_H_ */
