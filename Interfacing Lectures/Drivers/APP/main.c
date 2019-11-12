/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Muhamed Kotp
 */

#include <util/delay.h>
#include "../Service/StdTypes.h"
#include "../Service/StdMacros.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/ADC/ADC.h"
#include "../Controller/ATMEGA32/Registers.h"

#define F_CPU	8000000UL
#define LDR		0

uint16 adcval = 0;
f32 adcValue = 0;

void updateADC(void) {
	ADC_getValue(&adcval);
	adcValue = ((adcval * 5) / 1024);
}

int main() {
	GPIO_init();
	LCD_init();
	ADC_init();
	ADC_callback(updateADC);
	ADC_interruptEnable(ADC_INTERRUPT_ENABLE);
	SET_BIT(SREG, GIE);
	/*Configuration*/

	/*Initialization*/
	LCD_writeTxt("Welcome");

	_delay_ms(1000);
	LCD_writeCmd(lCD_CLEAR);

	while (1) {
		//ADC_readVolt(LDR, &adcValue);
		ADC_startConversion(LDR);
		LCD_writeNumber(adcValue);
		_delay_ms(1000);
		LCD_writeCmd(lCD_CLEAR);
	}

	return 0;
}

