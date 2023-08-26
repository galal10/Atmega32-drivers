#ifndef MGIE_INTERFACE_H_
#define MGIE_INTERFACE_H_

/*GIE Enable Function*/
#define MGIE_Vid_Enable() 		__asm__ __volatile__ ("sei" ::)

/*GIE Disable Function*/
#define MGIE_Vid_Disable()		__asm__ __volatile__ ("cli" ::)

#endif /* MGIE_INTERFACE_H_ */
