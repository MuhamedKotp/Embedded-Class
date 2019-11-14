/*
 ============================================================================
 Name        : SPI.c
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 9/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of SPI driver
 ============================================================================
 */
/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "SPI.h"
#include "SPI_cfg.h"

/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
//Initialize the SPI module
void SPI_init(void) {
	//Enable SPI
	SET_BIT(SPCR, SPE);
//Select SCK frequency as configured
#if defined(SCK_FREQ_Fosc_4)
//Nothing to do - Leave defaults
#elif defined(SCK_FREQ_Fosc_16)
	SET_BIT(SPCR, SPR0);	//Select SCK frequency Fosc/16
#elif defined(SCK_FREQ_Fosc_64)
	SET_BIT(SPCR, SPR1);	//Select SCK frequency Fosc/64
#elif defined(SCK_FREQ_Fosc_128)
	SET_BIT(SPCR, SPR0);	//Select SCK frequency Fosc/128
	SET_BIT(SPCR, SPR1);	//Select SCK frequency Fosc/128
#endif
}

//Select SPI mode Master/Slave
extern StdReturn SPI_modeSelect(SPI_enuMode spiMode) {
	switch (spiMode) {
	case SPI_MASTER:
		SET_BIT(SPCR, MSTR);	//Enable master mode
		GPIO_setPinDirection(MOSI_PORT, MOSI_PIN, GPIO_OUTPUT);	//Set MOSI pin to output
		GPIO_setPinDirection(SCK_PORT, SCK_PIN, GPIO_OUTPUT);	//Set SCK pin to output
		GPIO_setPinDirection(SS_PORT, SS_PIN, GPIO_OUTPUT);		//Set SS pin to output
		break;
	case SPI_SLAVE:
		CLEAR_BIT(SPCR, MSTR);	//Enable slave mode
		GPIO_setPinDirection(MISO_PORT, MISO_PIN, GPIO_OUTPUT);	//Set MISO pin to output
		break;
	default:
		return E_NOK;
	}
	return E_OK;
}

//Enables/Disables the interrupt for the SPI
StdReturn SPI_interruptEnable(SPI_enuInterruptState state) {
	switch (state) {
	case SPI_INTERRUPT_ENABLE:
		//Enable ADC interrupt
		SET_BIT(SPCR, SPIE);
		break;
	case SPI_INTERRUPT_DISABLE:
		//Disable ADC interrupt
		SET_BIT(SPCR, SPIE);
		break;
	default:
		return E_NOK;
	}
	return E_OK;
}

//Transmit char via SPI by polling
StdReturn SPI_transmitChar(uint8 data) {
	//Enable slave
	GPIO_writePin(SS_PORT, SS_PIN, GPIO_LOW);
	//Start transmission
	SPDR = data;
	//Wait transmission to finish
	while (!READ_BIT(SPSR, SPIF))
		;
	//Disable slave
	GPIO_writePin(SS_PORT, SS_PIN, GPIO_HIGH);
	return E_OK;
}

//Receive char via SPI by polling
StdReturn SPI_receiveChar(uint8 *data) {
	//Check Reception flag
	while (!READ_BIT(SPSR, SPIF))
		;
	//Return the received data
	*data = SPDR;

	return E_OK;
}
