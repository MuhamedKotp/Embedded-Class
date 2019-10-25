/*
 * Ext_Interrupt.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Muhamed Kotp
 */

#include "Ext_Interrupt.h"
#include <avr/interrupt.h>

static void (*user_fun)(void);

ISR(INT2_vect) {
	(*user_fun)();
}

void extInt_init(void) {
	SET_BIT(SREG, 7);
	SET_BIT(GICR, 5);
}

void extInt_callback(void (*func_ptr)(void)) {
	user_fun = func_ptr;
}
