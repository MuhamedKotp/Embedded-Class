/*
 ============================================================================
 Name        : Timer0.c
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 8/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of timer 0 Driver
 ============================================================================
 */
/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "Timer0.h"


/***************************************************************
 *********************Private data section**********************
 **************************************************************/
static void (*user_ptr)(void);



/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
ISR(TIMER0_COMP_vect){
	(*user_ptr)();
}

extern void Timer0_callback(void (*func_ptr)(void)){
	user_ptr = func_ptr;
}

extern void Timer0_init(void) {
	//Set mode to CTC
	SET_BIT(TCCR0, WGM01);

	//Prescaler 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);

	//Set OCR Value
	OCR0 = 78;

	//Enable CTC interrupt
	SET_BIT(TIMSK, OCIE0);
}
