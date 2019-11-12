/*
 * Timer0.h
 *
 *  Created on: Nov 8, 2019
 *      Author: M.Kotp
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
//#include <avr/interrupt.h>
#include "../../Controller/ATMEGA32/Registers.h"

extern void Timer0_init(void);
extern void Timer0_callback(void (*func_ptr)(void));
void TIMER0_voidSetCallBack(void (* FuncPtrCpy) (void));


#endif /* MCAL_TIMER0_TIMER0_H_ */
