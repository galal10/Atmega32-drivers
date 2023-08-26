#ifndef MGIE_INTERFACE_H_
#define MGIE_INTERFACE_H_

# define sei()  __asm__ __volatile__ ("sei" ::)

# define cli()  __asm__ __volatile__ ("cli" ::)

/*GIE Enable Function*/
#define MGIE_Vid_Enable() 		sei()

/*GIE Disable Function*/
#define MGIE_Vid_Disable()		cli()

#endif /* MGIE_INTERFACE_H_ */
