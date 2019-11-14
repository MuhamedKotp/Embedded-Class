/*
 ============================================================================
 Name        : SPI_cfg.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 9/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Configuration file for SPI driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

//SPI SCK Frequency
//Un-comment the desired SCK frequency
//#define	SCK_FREQ_Fosc_4		//SCK frequency Fosc/4
#define	SCK_FREQ_Fosc_16	//SCK frequency Fosc/16
//#define	SCK_FREQ_Fosc_64	//SCK frequency Fosc/64
//#define	SCK_FREQ_Fosc_128	//SCK frequency Fosc/128

//Define SPI pins number
#define SS_PIN		4
#define MOSI_PIN	5
#define MISO_PIN	6
#define SCK_PIN		7

//Define SPI pin's port
#define SS_PORT		GPIO_PORTB
#define MOSI_PORT	GPIO_PORTB
#define MISO_PORT	GPIO_PORTB
#define SCK_PORT	GPIO_PORTB


#endif /* MCAL_SPI_SPI_CFG_H_ */
