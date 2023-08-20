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
#endif /* MEXTI_PRIVATE_H_ */
