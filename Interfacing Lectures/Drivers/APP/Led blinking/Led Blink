/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Egypt LapTop
 */

#include <util/delay.h>
#include "../Controller/ATMEGA16/Registers.h"
#include "../Service/StdMacros.h"
#include "../Service/StdTypes.h"


int main() {
	/*Configuration*/
	SET_BIT(DDRC, 3);

	/*Initialization*/
	CLEAR_BIT(PORTC, 3);

	while (1) {
		SET_BIT(PORTC, 3);
		_delay_ms(1000);
		CLEAR_BIT(PORTC, 3);
		_delay_ms(1000);
	}

	return 0;
}
