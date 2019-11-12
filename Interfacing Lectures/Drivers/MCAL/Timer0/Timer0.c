/*
 * Timer0.c
 *
 *  Created on: Nov 8, 2019
 *      Author: M.Kotp
 */

#include "Timer0.h"

static void (*user_ptr)(void);

static void (* CallBackPtr)(void);

/*
ISR(TIMER0_COMP_vect){
	(*user_ptr)();
}
*/

void __vector_10(void) __attribute__((signal,used));

void __vector_10(void)
{
	(*user_ptr)();
}

/*
void __vector_10(void) __attribute__((signal,used));

void __vector_10(void)
{
	(*CallBackPtr)();
}
*/


extern void Timer0_callback(void (*func_ptr)(void)){
	user_ptr = func_ptr;
}
void TIMER0_voidSetCallBack(void (* FuncPtrCpy) (void))
{
	CallBackPtr = FuncPtrCpy;
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
