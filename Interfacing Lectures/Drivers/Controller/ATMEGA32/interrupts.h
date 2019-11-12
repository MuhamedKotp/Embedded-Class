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

#ifndef CONTROLLER_ATMEGA32_INTERRUPTS_H_
#define CONTROLLER_ATMEGA32_INTERRUPTS_H_


/********************************EXT INT ISR**********************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)


#define ADC_vect			__vector_16
#define TIMER0_COMP_vect	__vector_10
#define TIMER0_OVF_vect		__vector_11


#endif /* CONTROLLER_ATMEGA32_INTERRUPTS_H_ */
