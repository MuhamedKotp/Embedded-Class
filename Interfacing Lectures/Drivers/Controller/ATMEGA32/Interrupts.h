/*
 ============================================================================
 Name        : interrupts.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 12/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for interrupt's vector definition
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef CONTROLLER_ATMEGA32_INTERRUPTS_H_
#define CONTROLLER_ATMEGA32_INTERRUPTS_H_

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "Registers.h"


/********************************EXT INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)

//Interrupt Vectors of external interrupts
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_18

//Interrupt Vector of ADC
#define ADC_vect			__vector_16

//Interrupt Vectors of timer 0
#define TIMER0_COMP_vect	__vector_10
#define TIMER0_OVF_vect		__vector_11

//Interrupt Vectors of timer 1
#define TIMER1_COMPA_vect	__vector_6
#define TIMER1_COMPB_vect	__vector_7
#define TIMER1_OVF_vect		__vector_8

//Interrupt Vectors of timer 2
#define TIMER2_COMP_vect	__vector_3
#define TIMER2_OVF_vect		__vector_4


//Macro for enable global interrupt
#define ENABLE_GLOBAL_INTERRUPT()		(SREG |=  (1<<GIE))
//Macro for enable global interrupt
#define DISABLE_GLOBAL_INTERRUPT()		(SREG &= ~(1<<GIE))


#endif /* CONTROLLER_ATMEGA32_INTERRUPTS_H_ */
