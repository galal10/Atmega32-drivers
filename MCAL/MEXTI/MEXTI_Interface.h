#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

/* Copy_EXTI_ID Parameter */
typedef enum
{
	EXTI0 = 0,
	EXTI1,
	EXTI2
}MEXTI_EXTI_ID_t;

/* Copy_SenseControl Parameter */
typedef enum
{
	LOW_LEVEL = 0,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}MEXTI_SENSE_CONTROL_t;

/* EXTI0 Initialization */
void MEXTI0_Vid_Init(void);

/* EXTI1 Initialization */
void MEXTI1_Vid_Init(void);

/* EXTI2 Initialization */
void MEXTI2_Vid_Init(void);

/* Select Sense control Register */
Error_state MEXTI_Error_state_SenseControl(MEXTI_EXTI_ID_t Copy_EXTI_ID, MEXTI_SENSE_CONTROL_t Copy_SenseControl);

/* CallBack function */
Error_state MEXTI_Error_state_SetCallBack(MEXTI_EXTI_ID_t Copy_EXTI_ID, void (*P_EXTICallBack)(void));

#endif /* MEXTI_INTERFACE_H_ */
