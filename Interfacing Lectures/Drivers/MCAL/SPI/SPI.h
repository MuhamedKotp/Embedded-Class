/*
 ============================================================================
 Name        : SPI.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 9/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for SPI driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"
#include "../../MCAL/GPIO/GPIO.h"

/***************************************************************
 *********************Data types section************************
 **************************************************************/
typedef enum{
	SPI_INTERRUPT_ENABLE,
	SPI_INTERRUPT_DISABLE
}SPI_enuInterruptState;

typedef enum{
	SPI_MASTER,
	SPI_SLAVE
}SPI_enuMode;

/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//Initialize the SPI module
extern void SPI_init(void);
//Select SPI mode Master/Slave
extern StdReturn SPI_modeSelect(SPI_enuMode spiMode);
//Transmit char via SPI
extern StdReturn SPI_transmitChar(uint8 data);
//Receive char via SPI
extern StdReturn SPI_receiveChar(uint8 *data);
//Enables/Disables the interrupt for the SPI
StdReturn SPI_interruptEnable(SPI_enuInterruptState state);

#endif /* MCAL_SPI_SPI_H_ */
