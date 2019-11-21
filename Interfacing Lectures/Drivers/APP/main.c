/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Muhamed Kotp
 */

#include "../Service/StdTypes.h"
#include "../MCAL/Timer0/Timer0.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../Controller/ATMEGA32/Interrupts.h"


#define LED		7


void toggle(void){
	GPIO_togglePin(GPIO_PORTB, LED);
}


int main() {
	GPIO_init();
	Timer0_init(TIMER0_MODE_CTC);

	/*Configuration*/
	GPIO_setPinDirection(GPIO_PORTB, LED, GPIO_OUTPUT);
	Timer0_callback(toggle);

	/*Initialization*/
	GPIO_writePin(GPIO_PORTB, LED, GPIO_LOW);

	/*Start*/
	Timer0_startUs(10);
	ENABLE_GLOBAL_INTERRUPT();

	while (1) {

	}

	return 0;
}

