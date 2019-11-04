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


#define SREG	(*((volatile unsigned char* const)(0x5F)))
#define GIE		7

#define GICR	(*((volatile unsigned char* const)(0x5B)))
#define INT1		7
#define INT0		6
#define INT2		5

#define MCUCR	(*((volatile unsigned char* const)(0x55)))
#define ISC11		3
#define ISC10		2
#define ISC01		1
#define ISC00		0

#define MCUCSR	(*((volatile unsigned char* const)(0x54)))
#define ISC2		6


//Registers for ADC
#define ADMUX	(*((volatile unsigned char* const)(0x27)))
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADCSRA	(*((volatile unsigned char* const)(0x26)))
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADCH	(*((volatile unsigned char* const)(0x25)))
#define ADCL	(*((volatile unsigned char* const)(0x24)))



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
