/*
 * MSPI_Config.h
 *
 *  Created on: Nov 8, 2023
 *      Author: galal
 */

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

/* Data Order Options:
 * 1- SPI_DATA_ORDER_LSB
 * 2- SPI_DATA_ORDER_MSB
 */
#define SPI_DATA_ORDER			SPI_DATA_ORDER_MSB

/* Clock Polarity Options:
 * 1- SPI_CPOL_LEADING_RISING
 * 2- SPI_CPOL_LEADING_FALLING
 */
#define SPI_CLOCK_PLOARITY		SPI_CPOL_LEADING_RISING

/* Clock Phase Options:
 * 1- SPI_CPHA_LEADING_SAMPLE
 * 2- SPI_CPHA_LEADING_SETUP
 */
#define SPI_CLOCK_PHASE			SPI_CPHA_LEADING_SAMPLE

/* Double Speed Options:
 * 1- SPI_NO_DOUBLE_SPEED
 * 2- SPI_DOUBLE_SPEED
 */
#define SPI_SET_DOUBLE_SPEED 	SPI_NO_DOUBLE_SPEED

/* Clock Rate Options:
 * 1- SPI_CLK_RATE_4
 * 2- SPI_CLK_RATE_16
 * 3- SPI_CLK_RATE_64
 * 4- SPI_CLK_RATE_128
 */
#define SPI_CLK_RATE			SPI_CLK_RATE_4

/* SPI Interrupt Options:
 * 1- ENABLE
 * 2- DISABLE
 */
#define SPI_INTERRUPT			DISABLE

#endif /* MSPI_CONFIG_H_ */
