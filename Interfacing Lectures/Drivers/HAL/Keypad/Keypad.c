/*
 * Keypad.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Muhamed Kotp
 */

#include "Keypad_cfg.h"
#include "Keypad.h"
#include "../../Service/StdMacros.h"
#include "../../Controller/ATMEGA16/Registers.h"


static const uint8 keypadButtons[4][4] = {
		{'1', '2', '3', '+'},
		{'4', '5', '6', '-'},
		{'7', '8', '9', '/'},
		{'*', '0', '#', 'E'}
};


void Keypad_init(void) {
	GPIO_setPinDirection(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(ROW_1_PORT_REG, ROW_1_PIN_NUM, GPIO_INPUT);
	GPIO_setPinDirection(ROW_2_PORT_REG, ROW_2_PIN_NUM, GPIO_INPUT);
	GPIO_setPinDirection(ROW_3_PORT_REG, ROW_3_PIN_NUM, GPIO_INPUT);
	GPIO_setPinDirection(ROW_4_PORT_REG, ROW_4_PIN_NUM, GPIO_INPUT);

	GPIO_enablePullup(ROW_1_PORT_REG, ROW_1_PIN_NUM, GPIO_PULLUP_ENABLE);
	GPIO_enablePullup(ROW_2_PORT_REG, ROW_2_PIN_NUM, GPIO_PULLUP_ENABLE);
	GPIO_enablePullup(ROW_3_PORT_REG, ROW_3_PIN_NUM, GPIO_PULLUP_ENABLE);
	GPIO_enablePullup(ROW_4_PORT_REG, ROW_4_PIN_NUM, GPIO_PULLUP_ENABLE);

	GPIO_writePin(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_HIGH);
	GPIO_writePin(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_HIGH);
	GPIO_writePin(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_HIGH);
	GPIO_writePin(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_HIGH);
}

StdReturn Keypad_getKey(uint8 *key) {
//GPIO_readPin

	uint8 col = 1;
	uint8 row = 1;

	GPIO_pinState buttonState = GPIO_HIGH;

	for (col = 1; col <= 4; col++) {
		GPIO_writePin(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_HIGH);
		GPIO_writePin(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_HIGH);
		GPIO_writePin(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_HIGH);
		GPIO_writePin(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_HIGH);

		switch (col) {
		case 1:
			GPIO_writePin(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_LOW);
			break;
		case 2:
			GPIO_writePin(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_LOW);
			break;
		case 3:
			GPIO_writePin(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_LOW);
			break;
		case 4:
			GPIO_writePin(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_LOW);
			break;
		default:
			break;
		}

		for (row = 1; row <= 4; row++) {

			switch (row) {
			case 1:
				GPIO_readPin(ROW_1_PORT_REG, ROW_1_PIN_NUM, &buttonState);
				break;
			case 2:
				GPIO_readPin(ROW_2_PORT_REG, ROW_2_PIN_NUM, &buttonState);
				break;
			case 3:
				GPIO_readPin(ROW_3_PORT_REG, ROW_3_PIN_NUM, &buttonState);
				break;
			case 4:
				GPIO_readPin(ROW_4_PORT_REG, ROW_4_PIN_NUM, &buttonState);
				break;
			default:
				break;
			}

			if(buttonState == GPIO_LOW){
				break;
			}

		}

		if(row <= 4){
			break;
		}

	}

	if(col <= 4){
		*key = keypadButtons[row-1][col-1];
	}
	else{
		*key = 0xFF;
	}


	return E_OK;
}

