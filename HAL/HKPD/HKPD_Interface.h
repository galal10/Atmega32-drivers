#ifndef HKPD_INTERFACE_H_
#define HKPD_INTERFACE_H_


#define NOT_PRESSED		255

/* KPD init */
void HKPD_Vid_init(void);

/* KPD Get pressed */
u8 HKPD_u8_GetKeyPressed(void);

#endif /* HKPD_INTERFACE_H_ */
