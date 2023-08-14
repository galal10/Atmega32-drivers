#ifndef LBITS_H_
#define LBITS_H_

#define SET_BIT(PORT, PIN)		PORT |=  (1<<PIN)
#define CLR_BIT(PORT, PIN)		PORT &= ~(1<<PIN)
#define GET_BIT(PORT, PIN)		(PORT >> PIN) & 1
#define TOGGLE_BIT(PORT, PIN)	PORT ^=  (1<<PIN) 

#endif /* LBITS_H_ */