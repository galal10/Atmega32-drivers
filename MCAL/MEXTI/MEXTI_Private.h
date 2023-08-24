#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

/* Control Register : MCUCR */
#define MCUCR		*((volatile u8*)(0x55))
/* MCUCR bits */
#define ISC00							0
#define ISC01							1
#define ISC10							2
#define ISC11							3


/* Control Status Register : MCUCSR */
#define MCUCSR		*((volatile u8*)(0x54))
/* MCUCSR bits */
#define ISC2							6


/* General Interrupt Control Register : GICR */
#define GICR		*((volatile u8*)(0x5B))
/* GICR bits */
#define INT0							6
#define INT1							7
#define INT2							5

/* Sense Control Macros */
#define MEXTI_LOW_LEVEL					0x00
#define MEXTI_ANY_LOGICAL_CHANGE		0x01
#define MEXTI_FALLING_EDGE				0x02
#define MEXTI_RISING_EDGE				0x03

#define ISR(vector, ...)	\
void vector(void) __attribute__((signal)) __VA_ARGS__;\
void vector(void)

#endif /* MEXTI_PRIVATE_H_ */
