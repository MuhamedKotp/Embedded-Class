/*
 ============================================================================
 Name        : GPIO.c
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16
 Version     : 1.0
 Date		 : 20/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : GPIO Driver
 ============================================================================
 */

#include "GPIO.h"
#include "../../Controller/ATMEGA16/Registers.h"
#include "../../Service/StdMacros.h"

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
void GPIO_init(void) {

}

/* Brief:	set a specific DIO pin direction
 * Details:	This API is used to set a specific DIO pin direction to INPUT - OUTPUT
 * Input:	port	-Port name
 * 			pin		-Pin number
 * 			state	-Required state (INPUT, OUTPUT)
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	GPIO module to be initialized
 */
StdReturn GPIO_setPinDirection(GPIO_port port, uint8 pin, GPIO_pinType state) {
	if (pin > MAX_PIN_NUMBER) {
		return E_NOK;
	} else {
		switch (port) {
		case GPIO_PORTA:
			switch (state) {
			case GPIO_INPUT:
				CLEAR_BIT(DDRA, pin);
				break;
			case GPIO_OUTPUT:
				SET_BIT(DDRA, pin);
				break;
			default:
				return E_NOK;
			}
			break;
		case GPIO_PORTB:
			switch (state) {
			case GPIO_INPUT:
				CLEAR_BIT(DDRB, pin);
				break;
			case GPIO_OUTPUT:
				SET_BIT(DDRB, pin);
				break;
			default:
				return E_NOK;
			}
			break;
		case GPIO_PORTC:
			switch (state) {
			case GPIO_INPUT:
				CLEAR_BIT(DDRC, pin);
				break;
			case GPIO_OUTPUT:
				SET_BIT(DDRC, pin);
				break;
			default:
				return E_NOK;
			}
			break;
		case GPIO_PORTD:
			switch (state) {
			case GPIO_INPUT:
				CLEAR_BIT(DDRD, pin);
				break;
			case GPIO_OUTPUT:
				SET_BIT(DDRD, pin);
				break;
			default:
				return E_NOK;
			}
			break;
		default:
			return E_NOK;
		}
	}

	return E_OK;
}

/* Brief:	Write a specific DIO pin
 * Details:	This API is used to write a specific pin of DIO to HIGH - LOW
 * Input:	port	-Port name
 * 			pin		-Pin number
 * 			state	-Required state (High - Low)
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set OUTPUT
 */
StdReturn GPIO_writePin(GPIO_port port, uint8 pin, GPIO_pinState state) {

	return E_OK;
}

/* Brief:	Read a specific DIO pin
 * Details:	This API is used to get a specific pin of DIO whether HIGH - LOW
 * Input:	port	-Port name
 * 			pin		-Pin number
 * Output:  *state	-Pin state whether high or low
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set INPUT
 */
StdReturn GPIO_readPin(GPIO_port port, uint8 pin, GPIO_pinState *state) {

	return E_OK;
}

/* Brief:	enable internal pull up resistor of a specific DIO pin
 * Details:	This API is used to enable the internal pull up resistor in specific pin of DIO
 * Input:	port	-Port name
 * 			pin		-Pin number
 * 			state	-Required state (enabled - Disabled)
 * Output:  No output
 * return:	StdReturn	-return the API status
 * prerequisites:	pin direction to be set INPUT
 */
StdReturn GPIO_enablePullup(GPIO_port port, uint8 pin, GPIO_pullupEnable state) {

	return E_OK;
}

