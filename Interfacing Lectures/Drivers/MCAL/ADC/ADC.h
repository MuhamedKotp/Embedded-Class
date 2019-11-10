/*
 * ADC.H
 *
 *  Created on: Nov 1, 2019
 *      Author: Mokhtar
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"



extern void ADC_init(void);
extern void ADC_callback(void (*func_ptr)(void));
extern StdReturn ADC_readValue(uint8 channel, uint16 *adcValue);
extern StdReturn ADC_readVolt(uint8 channel, f32 *volt);
extern StdReturn ADC_startConversion(uint8 channel);


#endif /* MCAL_ADC_ADC_H_ */
