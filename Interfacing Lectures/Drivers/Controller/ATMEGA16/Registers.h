/*
 ============================================================================
 Name        : Registers.h
 Author      : Muhamed Kotp
 Version     : 1.0
 Date		 : 20/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : ATMEGA16 registers definition
 ============================================================================
 */

#ifndef CONTROLLER_REGISTERS_H_
#define CONTROLLER_REGISTERS_H_


//Special Function I/O Register
#define SFIOR	(*((volatile unsigned char* const)(0x50)))
#define PUD		2		//Pull up disable bit in SFIOR

//GPIO Port A registers
#define PORTA	(*((volatile unsigned char* const)(0x3B)))
#define DDRA	(*((volatile unsigned char* const)(0x3A)))
#define PINA	(*((volatile unsigned char* const)(0x39)))

//GPIO Port B registers
#define PORTB	(*((volatile unsigned char* const)(0x38)))
#define DDRB	(*((volatile unsigned char* const)(0x37)))
#define PINB	(*((volatile unsigned char* const)(0x36)))

//GPIO Port C registers
#define PORTC	(*((volatile unsigned char* const)(0x35)))
#define DDRC	(*((volatile unsigned char* const)(0x34)))
#define PINC	(*((volatile unsigned char* const)(0x33)))

//GPIO Port D registers
#define PORTD	(*((volatile unsigned char* const)(0x32)))
#define DDRD	(*((volatile unsigned char* const)(0x31)))
#define PIND	(*((volatile unsigned char* const)(0x30)))



#endif /* CONTROLLER_REGISTERS_H_ */
