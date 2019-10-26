/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Muhamed Kotp
 */

#include <avr/interrupt.h>
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/Ext_Interrupt/Ext_Interrupt.h"

#define F_CPU	8000000UL

#define LED_PIN		7


void toggle(void){
	GPIO_togglePin(GPIO_PORTB, LED_PIN);
}




int main() {
	GPIO_init();
	extInt_init();

	/*Configuration*/
	GPIO_setPinDirection(GPIO_PORTB, LED_PIN, GPIO_OUTPUT);
	extInt0_init(EXTINT_RISING_EDGE);
	extInt0_callback(toggle);


	/*Initialization*/
	GPIO_writePin(GPIO_PORTB, LED_PIN, GPIO_LOW);


	while (1) {

	}

	return 0;
}
