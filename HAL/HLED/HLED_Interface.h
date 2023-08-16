#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_
typedef enum
{
	LED1 = PIN0,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
	LED7,
	LED8,
}E_Led_t;

/* erroes are handled on MCAL so we can set return it void */
void HLED_Vid_Init(LED_t *Copy_Led);

void HLED_Vid_Led_on(LED_t *Copy_Led);

void HLED_Vid_Led_off(LED_t *Copy_Led);

void HLED_Vid_Led_Toggle(LED_t *Copy_Led);

#endif /* HLED_INTERFACE_H_ */
