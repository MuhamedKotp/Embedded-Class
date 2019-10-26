/*
 * Ext_Interrupt.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Muhamed Kotp
 */

#include "Ext_Interrupt.h"
#include <avr/interrupt.h>

static void (*user_func0)(void);
static void (*user_func1)(void);
static void (*user_func2)(void);


ISR( INT0_vect) {
	(*user_func0)();
}
ISR( INT1_vect) {
	(*user_func1)();
}
ISR( INT2_vect) {
	(*user_func2)();
}

void extInt_init(void) {
	//Enable global interrupt
	SET_BIT(SREG, GIE);
}

StdReturn extInt0_init(extInt_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;

	//Enable external interrupt 0 mask
	SET_BIT(GICR, INT0);

	//Configure sense control
	switch (senseLevel) {
	case EXTINT_RISING_EDGE:		//Rising edge causes interrupt
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
	case EXTINT_FALLING_EDGE:		//Falling edge causes interrupt
		SET_BIT(MCUCR, ISC01);
		CLEAR_BIT(MCUCR, ISC00);
		break;
	default:						//Wrong configuration is sent
		return_Loc = E_NOK;
		break;
	}
	//Return API status
	return return_Loc;
}

StdReturn extInt0_callback(void (*func_ptr)(void)) {
	user_func0 = func_ptr;
	return E_OK;
}


StdReturn extInt1_init(extInt_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;
	SET_BIT(GICR, INT1);
	switch (senseLevel) {
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);
		break;
	case EXTINT_FALLING_EDGE:
		SET_BIT(MCUCR, ISC11);
		CLEAR_BIT(MCUCR, ISC10);
		break;
	default:
		return_Loc = E_NOK;
		break;
	}
	return return_Loc;
}

StdReturn extInt1_callback(void (*func_ptr)(void)) {
	user_func1 = func_ptr;
	return E_OK;
}

StdReturn extInt2_init(extInt_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;
	SET_BIT(GICR, INT2);
	switch (senseLevel) {
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCSR, ISC2);
		break;
	case EXTINT_FALLING_EDGE:
		CLEAR_BIT(MCUCSR, ISC2);
		break;
	default:
		return_Loc = E_NOK;
		break;
	}
	return return_Loc;
}

StdReturn extInt2_callback(void (*func_ptr)(void)) {
	user_func2 = func_ptr;
	return E_OK;
}
