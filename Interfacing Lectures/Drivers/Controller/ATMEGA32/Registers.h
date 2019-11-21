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

//External interrupt registers
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
#define REFS1	7		//ADC select reference
#define REFS0	6		//ADC select reference
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADCSRA	(*((volatile unsigned char* const)(0x26)))
#define ADEN	7		//Enable ADC
#define ADSC	6
#define ADATE	5
#define ADIF	4		//ADC interrupt flag
#define ADIE	3		//ADC interrupt enable
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADCH	(*((volatile unsigned char* const)(0x25)))		//ADC data register high
#define ADCL	(*((volatile unsigned char* const)(0x24)))		//ADC data register low


/*****************Timers generic registers***********************/
//Timer/Counter Interrupt Mask Register
#define TIMSK	(*((volatile unsigned char* const)(0x59)))
#define OCIE2	7		//Timer/Counter2 Output Compare Match Interrupt Enable
#define TOIE2	6		//Timer/Counter2 Overflow Interrupt Enable
#define TICIE1	5		//Timer/Counter1, Input Capture Interrupt Enable
#define OCIE1A	4		//Timer/Counter1 Output Compare A Match Interrupt Enable
#define OCIE1B	3		//Timer/Counter1 Output Compare B Match Interrupt Enable
#define TOIE1	2		//Timer/Counter1 Overflow Interrupt Enable
#define OCIE0	1		//Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE0	0		//Timer/Counter0 Overflow Interrupt Enable

//Timer/Counter Interrupt Flag Register
#define TIFR	(*((volatile unsigned char* const)(0x58)))
#define OCF2	7		//Output Compare Flag 2
#define TOV2	6		//Timer/Counter2 Overflow Flag
#define ICF1	5		//Timer/Counter1, Input Capture Flag
#define OCF1A	4		//Output Compare A Flag 1
#define OCF1B	3		//Output Compare B Flag 1
#define TOV1	2		//Timer/Counter1 Overflow Flag
#define OCF0	1		//Output Compare Flag 0
#define TOV0	0		//Timer/Counter0 Overflow Flag

/*****************Timer 0 registers***********************/
//Timer/Counter2 Control Register
#define TCCR0	(*((volatile unsigned char* const)(0x53)))
#define FOC0	7		//Force Output Compare
#define WGM00	6		//Waveform Generation Mode
#define COM01	5		//Compare Match Output Mode
#define COM00	4		//Compare Match Output Mode
#define WGM01	3		//Waveform Generation Mode
#define CS02	2		//Clock Select
#define CS01	1		//Clock Select
#define CS00	0		//Clock Select

//Timer/Counter0 Register
#define TCNT0	(*((volatile unsigned char* const)(0x52)))
//Output Compare 2 Register
#define OCR0	(*((volatile unsigned char* const)(0x5C)))

/*****************Timer 2 registers***********************/
//Timer/Counter2 Control Register
#define TCCR2	(*((volatile unsigned char* const)(0x45)))
#define FOC2	7		//Force Output Compare
#define WGM20	6		//Waveform Generation Mode
#define COM21	5		//Compare Match Output Mode
#define COM20	4		//Compare Match Output Mode
#define WGM21	3		//Waveform Generation Mode
#define CS22	2		//Clock Select
#define CS21	1		//Clock Select
#define CS20	0		//Clock Select

//Asynchronous Status Register – ASSR
#define ASSR	(*((volatile unsigned char* const)(0x42)))
#define AS2		3		//Asynchronous Timer/Counter2
#define TCN2UB	2		//Timer/Counter2 Update Busy
#define OCR2UB	1		//Output Compare Register2 Update Busy
#define TCR2UB	0		//Timer/Counter Control Register2 Update Busy


//Timer/Counter2 Register
#define TCNT2	(*((volatile unsigned char* const)(0x44)))
//Output Compare 2 Register
#define OCR2	(*((volatile unsigned char* const)(0x43)))


/*****************UART registers***********************/
//UART data register
#define UDR	(*((volatile unsigned char* const)(0x2C)))

#define UCSRA	(*((volatile unsigned char* const)(0x2B)))
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2x		1		//Double speed mode
#define MPCM	0

#define UCSRB	(*((volatile unsigned char* const)(0x2A)))
#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4		//Enable UART receive
#define TXEN	3		//Enable UART transmit
#define UCSZ2	2
#define RXB8	1		//Receive data bit 9
#define TXB8	0		//Transmit data bit 9

#define UCSRC	(*((volatile unsigned char* const)(0x40)))
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0

#define UBRRH	(*((volatile unsigned char* const)(0x40)))
#define UBRRL	(*((volatile unsigned char* const)(0x29)))


/*********************SPI Registers**********************/
//SPI Control register
#define SPCR	(*((volatile unsigned char* const)(0x2D)))
#define SPIE	7		//SPI interrupt enable
#define SPE		6		//SPI enable
#define DORD	5		//Data order LSB/MSB first
#define MSTR	4		//Master/Slave select
#define CPOL	3		//Clock polarity
#define CPHA	2		//Clock phase
#define SPR1	1		//Clock rate select (Prescaler select)
#define SPR0	0		//Clock rate select (Prescaler select)

//SPI status register
#define SPSR	(*((volatile unsigned char* const)(0x2E)))
#define SPIF	7		//SPI interrupt flag
#define WCOL	6		//Write collision flag
#define SPI2X	0		//SPI double speed mode

//SPI data register
#define SPDR	(*((volatile unsigned char* const)(0x2F)))

/****************************************************/
//Special Function I/O Register
#define SFIOR	(*((volatile unsigned char* const)(0x50)))
#define PUD		2		//Pull up disable bit in SFIOR

/******************DIO registers***********************/
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
