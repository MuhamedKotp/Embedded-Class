/*
 * UART.h
 *
 *  Created on: Nov 9, 2019
 *      Author: M.Kotp
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA16/Registers.h"



extern void UART_init(void);
extern StdReturn UART_transmitChar(uint8 data);
extern StdReturn UART_receiveChar(uint8 *data);

#endif /* MCAL_UART_UART_H_ */
