/*
 ============================================================================
 Name        : ADC_cfg.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 1/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Configuration file of ADC Driver
 ============================================================================
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/*****ADC clock prescaler*********/
//Un-select the required prescaler
//#define PRESCALER_2
//#define PRESCALER_4
//#define PRESCALER_8
//#define PRESCALER_16
//#define PRESCALER_32
#define PRESCALER_64
//#define PRESCALER_128

/*******ADC resolution***********/
//Un-select the required resolution
//#define RESOLUTION_8_BIT
#define RESOLUTION_10_BIT

/*******Aref source***********/
//Un-select the required source of Aref
//#define AREF_INTERNAL_VOLTAGE		//internal 2.56 voltage source
#define AREF_EXTERNAL_AVCC		//External Avcc


#endif /* MCAL_ADC_ADC_CFG_H_ */
