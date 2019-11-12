/*
 ============================================================================
 Name        : ADC.c
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 1/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of ADC Driver
 ============================================================================
 */

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "ADC.h"

/***************************************************************
 *********************Private data section**********************
 **************************************************************/
//Pointer to the user function to be executed on ADC ISR trigger
static void (*user_ptr)(void);
//Mask to un-select all channels
#define CHANNELS_UNSELECT_MASK		0xF8
//Mask to only read 10 bits from uint16 value
#define _10_BIT_MASK	0x3FF
//Reference voltage for the ADC
#define VREF	5
//Max ADC value
#define ADC_MAX		1024

/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
//Initialize the ADC module
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

}

//Enables/Disables the interrupt for the ADC
StdReturn ADC_interruptEnable(ADC_enuInterruptState state) {
	switch (state) {
	case ADC_INTERRUPT_ENABLE:
		//Enable ADC interrupt
		SET_BIT(ADCSRA, ADIE);
		break;
	case ADC_INTERRUPT_DISABLE:
		//Disable ADC interrupt
		CLEAR_BIT(ADCSRA, ADIE);
		break;
	default:
		return E_NOK;
	}

	return E_OK;
}

//Set the user function to be executed on ISR
void ADC_callback(void (*func_ptr)(void)) {
	user_ptr = func_ptr;
}
//ISR for the ADC
ISR(ADC_vect) {
	(*user_ptr)();
}

//Start the ADC conversion - Will be notify of the end through ISR
StdReturn ADC_startConversion(uint8 channel) {
	if (channel > 7) {
		return E_NOK;
	} else {
		//Select channel
		ADMUX &= CHANNELS_UNSELECT_MASK;
		ADMUX |= channel;
		//Start conversion
		SET_BIT(ADCSRA, ADSC);
	}
	return E_OK;
}

//Get the value in ADC data registers
extern StdReturn ADC_getValue(uint16 *adcValue) {
	uint16 adcVal_Loc = 0;
	adcVal_Loc = ADCL + (ADCH << 8);//Get the values of the two ADC registers
	*adcValue = (adcVal_Loc & _10_BIT_MASK);//Mask higher bits in ADCH and read only the 10 bits for the ADC

	return E_OK;
}

//Poll and read the ADC value
extern StdReturn ADC_readValue(uint8 channel, uint16 *adcValue) {
	uint16 adcVal_Loc = 0;
	if (channel > 7) {
		return E_NOK;
	} else {
		//Select channel
		ADMUX &= CHANNELS_UNSELECT_MASK;
		ADMUX |= channel;
		//Start conversion
		SET_BIT(ADCSRA, ADSC);
		//Wait conversion to finish
		while (READ_BIT(ADCSRA, ADSC) == 1)
			;
		//return the read value
		adcVal_Loc = ADCL + (ADCH << 8);//Get the values of the two ADC registers
		*adcValue = (adcVal_Loc & _10_BIT_MASK);//Mask higher bits in ADCH and read only the 10 bits for the ADC
	}

	return E_OK;
}

//Poll and read the voltage on the ADC pin
StdReturn ADC_readVolt(uint8 channel, f32 *volt) {
	uint16 adcVal_Loc = 0;
	if (channel > 7) {
		return E_NOK;
	} else {
		ADC_readValue(channel, &adcVal_Loc);
		*volt = ((adcVal_Loc * VREF) / ADC_MAX);
	}
	return E_OK;
}
