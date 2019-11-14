/*
 ============================================================================
 Name        : Timer0.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 8/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for timer 0 Driver
 ============================================================================
 */
#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"
#include "../../Controller/ATMEGA32/Interrupts.h"


extern void Timer0_init(void);
extern void Timer0_callback(void (*func_ptr)(void));


#endif /* MCAL_TIMER0_TIMER0_H_ */
