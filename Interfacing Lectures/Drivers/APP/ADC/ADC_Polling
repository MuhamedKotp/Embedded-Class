/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Muhamed Kotp
 */

#include <util/delay.h>
#include "../Service/StdTypes.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/ADC/ADC.H"

#define F_CPU	8000000UL
#define LDR		1

f32 adcValue = 0;

int main() {
	GPIO_init();
	LCD_init();
	ADC_init();

	/*Configuration*/


	/*Initialization*/
	LCD_writeTxt("Welcome");

	_delay_ms(1000);
	LCD_writeCmd(lCD_CLEAR);

	while (1) {
		ADC_readVolt(LDR, &adcValue);
		LCD_writeNumber(adcValue);
		_delay_ms(500);
		LCD_writeCmd(lCD_CLEAR);
	}

	return 0;
}

