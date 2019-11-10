/*
 * UART.c
 *
 *  Created on: Nov 9, 2019
 *      Author: M.Kotp
 */


#include "UART.h"


void UART_init(void){
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);

	SET_BIT(UCSRC, URSEL);
	SET_BIT(UCSRC, UPM1);

	UBRRL = 51;

	SET_BIT(UCSRB, RXCIE);
}

StdReturn UART_transmitChar(uint8 data){

	while(!READ_BIT(UCSRA, UDRE));
	UDR = data;

	return E_OK;
}

StdReturn UART_receiveChar(uint8 *data){
	while(!READ_BIT(UCSRA, RXC));
	*data = UDR;

	return E_OK;
}
