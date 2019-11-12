/*
 * SPI.c
 *
 *  Created on: Nov 9, 2019
 *      Author: M.Kotp
 */
#include "SPI.h"


extern void SPI_init(void){
	SET_BIT(SPCR, SPIE);
	SET_BIT(SPCR, SPE);
	SET_BIT(SPCR, MSTR);
	SET_BIT(SPCR, SPR0);
}

extern StdReturn SPI_transmitChar(uint8 data){

	return E_OK;
}

extern StdReturn SPI_receiveChar(uint8 *data){

	return E_OK;
}
