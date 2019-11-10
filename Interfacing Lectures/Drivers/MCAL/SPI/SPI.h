/*
 * SPI.h
 *
 *  Created on: Nov 9, 2019
 *      Author: M.Kotp
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA16/Registers.h"



extern void SPI_init(void);
extern StdReturn SPI_transmitChar(uint8 data);
extern StdReturn SPI_receiveChar(uint8 *data);


#endif /* MCAL_SPI_SPI_H_ */
