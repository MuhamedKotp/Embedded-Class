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
#include "ADC_cfg.h"

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
#if defined(AREF_EXTERNAL_AVCC)		//If Avcc source is selected
#define VREF	5
#elif defined(AREF_INTERNAL_VOLTAGE)	//If internal voltage is selected
#define VREF	2.56
#endif
//Max ADC value
#if defined(RESOLUTION_10_BIT)
#define ADC_MAX		1024
#elif defined(RESOLUTION_8_BIT)
#define ADC_MAX		256
#endif

/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
//Initialize the ADC module
void ADC_init(void) {
	//Select Vref
#if defined(AREF_EXTERNAL_AVCC)
	CLEAR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#elif defined(AREF_INTERNAL_VOLTAGE)
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#endif
	//Left adjust for 8 bit ADC resolution otherwise right adjust
#if defined(RESOLUTION_8_BIT)
	SET_BIT(ADMUX, ADLAR);
#endif
	//Enable ADC
	SET_BIT(ADCSRA, ADEN);
	//Select the Prescaler
#if defined(PRESCALER_2)
	SET_BIT(ADCSRA, ADPS0);
#elif defined(PRESCALER_4)
	SET_BIT(ADCSRA, ADPS1);
#elif defined(PRESCALER_8)
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
#elif defined(PRESCALER_16)
	SET_BIT(ADCSRA, ADPS2);
#elif defined(PRESCALER_32)
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS2);
#elif defined(PRESCALER_64)
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
#elif defined(PRESCALER_128)
#endif

}

//Enables/Disables the interrupt for the ADC
StdReturn ADC_setInterrupt(ADC_enuInterruptState state) {
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
#if defined(RESOLUTION_10_BIT)
	adcVal_Loc = ADCL + (ADCH << 8); //Get the values of the two ADC registers
	*adcValue = (adcVal_Loc & _10_BIT_MASK); //Mask higher bits in ADCH and read only the 10 bits for the ADC
#elif defined(RESOLUTION_8_BIT)
	*adcValue = ADCH;
#endif
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
#if defined(RESOLUTION_10_BIT)
		adcVal_Loc = ADCL + (ADCH << 8); //Get the values of the two ADC registers
		*adcValue = (adcVal_Loc & _10_BIT_MASK); //Mask higher bits in ADCH and read only the 10 bits for the ADC
#elif defined(RESOLUTION_8_BIT)
		*adcValue = ADCH;
#endif
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
		*volt = (((f32)adcVal_Loc * (f32)VREF) / (f32)ADC_MAX);
	}
	return E_OK;
}
