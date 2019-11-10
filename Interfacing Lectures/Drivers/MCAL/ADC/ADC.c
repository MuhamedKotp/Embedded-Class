/*
 * ADC.C
 *
 *  Created on: Nov 1, 2019
 *      Author: Mokhtar
 */

#include "ADC.H"
#include <avr/interrupt.h>

static void (*user_ptr)(void);

void __vector_16(void) __attribute__((signal,used));

void __vector_16(void) {
	(*user_ptr)();
}

/*
 ISR(ADC_vect){
 (*user_ptr)();
 }
 */

void ADC_callback(void (*func_ptr)(void)) {
	user_ptr = func_ptr;
}

void ADC_init(void) {
	//Select Vref
	CLEAR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
	//Right adjust
	CLEAR_BIT(ADMUX, ADLAR);
	//Enable ADC
	SET_BIT(ADCSRA, ADEN);
	//Select 64 Prescaler
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	CLEAR_BIT(ADCSRA, ADPS0);
	//Enable ADC interrupt
	SET_BIT(ADCSRA, ADIE);
}

StdReturn ADC_startConversion(uint8 channel) {
	if (channel > 7) {
		return E_NOK;
	} else {
		//Select channel
		ADMUX &= 0b11111000;
		ADMUX |= channel;
		//Start conversion
		SET_BIT(ADCSRA, ADSC);
	}
	return E_OK;
}

extern StdReturn ADC_readValue(uint8 channel, uint16 *adcValue) {
	uint16 adcVal_Loc = 0;
	if (channel > 7) {
		return E_NOK;
	} else {
		//Select channel
		ADMUX &= 0b11111000;
		ADMUX |= channel;
		//Start conversion
		SET_BIT(ADCSRA, ADSC);
		//Wait conversion to finish
		while (READ_BIT(ADCSRA, ADSC) == 1)
			;
		//return the read value
		adcVal_Loc = ADCL + (ADCH << 8);
		*adcValue = (adcVal_Loc & 0x3FF);
	}

	return E_OK;
}

StdReturn ADC_readVolt(uint8 channel, f32 *volt) {
	uint16 adcVal_Loc = 0;
	if (channel > 7) {
		return E_NOK;
	} else {
		ADC_readValue(channel, &adcVal_Loc);
		*volt = ((adcVal_Loc * 5) / 1024);
	}
	return E_OK;
}
