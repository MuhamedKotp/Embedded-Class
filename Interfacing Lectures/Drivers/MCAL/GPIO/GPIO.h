/*
 ============================================================================
 Name        : GPIO.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16
 Version     : 1.0
 Date		 : 20/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for GPIO Driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_


/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "../../Service/StdTypes.h"



/***************************************************************
 *********************Data types section************************
 **************************************************************/
//Max pin number in the port
#define MAX_PIN_NUMBER		7

//Data type for ports names
typedef enum{
	GPIO_PORTA,		//Port A
	GPIO_PORTB,		//Port B
	GPIO_PORTC,		//Port C
	GPIO_PORTD		//Port D
}GPIO_port;

//Data type for pin direction
typedef enum{
	GPIO_INPUT,		//Input pin
	GPIO_OUTPUT		//Output pin
}GPIO_pinType;

//Data type for pin state
typedef enum{
	GPIO_LOW,		//Pin Low
	GPIO_HIGH		//Pin High
}GPIO_pinState;

//Data type for pull-up resistor state in a specific pin
typedef enum{
	GPIO_PULLUP_DISABLE,	//Pull-up resistor disable
	GPIO_PULLUP_ENABLE		//Pull-up resisitor enable
}GPIO_pullupEnable;

/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
/* Brief:	Initialize the GPIO driver
 * Details:	This API initialize the GPIO driver module by initializing all
 * 			registers with default values.
 * 			All Direction registers are input in high impedance state
 * 			All data registers are zeros.
 * Input:	void
 * Output:  void
 * return:	void
 * prerequisites:	No prerequisites
 */
void GPIO_init(void);

/* Brief:	set a specific DIO pin direction
 * Details:	This API is used to set a specific DIO pin direction to INPUT - OUTPUT
 * Input:	port	-Port name
 * 			pin		-Pin number
 * 			state	-Required state (INPUT, OUTPUT)
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	GPIO module to be initialized
 */
StdReturn GPIO_setPinDirection(GPIO_port port, uint8 pin, GPIO_pinType state);

/* Brief:	Write a specific DIO pin
 * Details:	This API is used to write a specific pin of DIO to HIGH - LOW
 * Input:	port	-Port name
 * 			pin		-Pin number
 * 			state	-Required state (High - Low)
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set OUTPUT
 */
StdReturn GPIO_writePin(GPIO_port port, uint8 pin, GPIO_pinState state);

/* Brief:	Toggle a specific DIO pin
 * Details:	This API is used to toggle pin status of DIO (HIGH -> LOW or LOW -> HIGH)
 * Input:	port	-Port name
 * 			pin		-Pin number
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set output
 */
StdReturn GPIO_togglePin(GPIO_port port, uint8 pin);

/* Brief:	Read a specific DIO pin
 * Details:	This API is used to get a specific pin of DIO whether HIGH - LOW
 * Input:	port	-Port name
 * 			pin		-Pin number
 * Output:  *state	-Pin state whether high or low
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set INPUT
 */
StdReturn GPIO_readPin(GPIO_port port, uint8 pin, GPIO_pinState *state);

/* Brief:	enable internal pull up resistor of a specific DIO pin
 * Details:	This API is used to enable the internal pull up resistor in specific pin of DIO
 * Input:	port	-Port name
 * 			pin		-Pin number
 * 			state	-Required state (enabled - Disabled)
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set INPUT
 */
StdReturn GPIO_enablePullup(GPIO_port port, uint8 pin, GPIO_pullupEnable state);


#endif /* MCAL_GPIO_GPIO_H_ */
