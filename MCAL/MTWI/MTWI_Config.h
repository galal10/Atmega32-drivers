/*
 * MTWI_Config.h
 *
 *  Created on: Dec 1, 2023
 *      Author: galal
 */

#ifndef MTWI_CONFIG_H_
#define MTWI_CONFIG_H_

/* Frequency of CPU */
#define CPU_Freq			8000000u

/* Frequency of desired CLK of Peripheral:
 * 1- SCL_Freq_100k
 * 2- SCL_Freq_400k
 */
#define SCL_Freq			SCL_Freq_400k

/* Prescler Options:
 * 1- TWI_PRESCALER_1
 * 2- TWI_PRESCALER_4
 * 3- TWI_PRESCALER_16
 * 4- TWI_PRESCALER_64
 */
#define TWI_PRESCALER		TWI_PRESCALER_1

#endif /* MTWI_CONFIG_H_ */
