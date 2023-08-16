#ifndef HCLCD_CONFIG_H_
#define HCLCD_CONFIG_H_

/* Configure RS,RW,E pins ==> (PIN0 to PIN7) */
#define RS				PIN0
#define RW				PIN1
#define E				PIN2

/* Configure Control port ==> (MDIO_PORTA, MDIO_PORTB, MDIO_PORTC, MDIO_PORTD) */
#define CONTROL_PORT	MDIO_PORTC

/* Configure Data port ==> (MDIO_PORTA, MDIO_PORTB, MDIO_PORTC, MDIO_PORTD) */
#define DATA_PORT		MDIO_PORTD
#endif /* HCLCD_CONFIG_H_ */
