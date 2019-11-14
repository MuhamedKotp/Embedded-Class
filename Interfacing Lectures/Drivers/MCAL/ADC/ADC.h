/*
 ============================================================================
 Name        : ADC.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 1/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for ADC Driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "../../Controller/ATMEGA32/Interrupts.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"

/***************************************************************
 *********************Data types section************************
 **************************************************************/
typedef enum{
	ADC_INTERRUPT_ENABLE,
	ADC_INTERRUPT_DISABLE
}ADC_enuInterruptState;

/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//Initialize the ADC module
extern void ADC_init(void);
//Enables/Disables the interrupt for the ADC
extern StdReturn ADC_interruptEnable(ADC_enuInterruptState state);
//Set the user function to be executed on ISR
extern void ADC_callback(void (*func_ptr)(void));
//Start the ADC conversion - Will be notify of the end through ISR
extern StdReturn ADC_startConversion(uint8 channel);
//Get the value in ADC data registers
extern StdReturn ADC_getValue(uint16 *adcValue);
//Poll and read the ADC value
extern StdReturn ADC_readValue(uint8 channel, uint16 *adcValue);
//Poll and read the voltage on the ADC pin
extern StdReturn ADC_readVolt(uint8 channel, f32 *volt);


#endif /* MCAL_ADC_ADC_H_ */
