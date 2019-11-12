/*
 ============================================================================
 Name        : Keypad.c
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code for 4*4 Keypad Driver
 ============================================================================
 */

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "Keypad_cfg.h"
#include "Keypad.h"

/***************************************************************
 *****************Private data definition***********************
 **************************************************************/
//Define the keypad buttons
static const uint8 keypadButtons[4][4] = {
		{'1', '2', '3', '+'},
		{'4', '5', '6', '-'},
		{'7', '8', '9', '/'},
		{'*', '0', '#', 'E'}
};


/***************************************************************
 *********************Functions Implementation******************
 **************************************************************/
//Initialize the keypad driver - initialize the keypad pins
void Keypad_init(void) {
	//Set Columns pins to output
	GPIO_setPinDirection(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_OUTPUT);
	GPIO_setPinDirection(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_OUTPUT);
	//Set rows pins to input
	GPIO_setPinDirection(ROW_1_PORT_REG, ROW_1_PIN_NUM, GPIO_INPUT);
	GPIO_setPinDirection(ROW_2_PORT_REG, ROW_2_PIN_NUM, GPIO_INPUT);
	GPIO_setPinDirection(ROW_3_PORT_REG, ROW_3_PIN_NUM, GPIO_INPUT);
	GPIO_setPinDirection(ROW_4_PORT_REG, ROW_4_PIN_NUM, GPIO_INPUT);
	//Enable the internal pull-up resistor for the input pins
	GPIO_enablePullup(ROW_1_PORT_REG, ROW_1_PIN_NUM, GPIO_PULLUP_ENABLE);
	GPIO_enablePullup(ROW_2_PORT_REG, ROW_2_PIN_NUM, GPIO_PULLUP_ENABLE);
	GPIO_enablePullup(ROW_3_PORT_REG, ROW_3_PIN_NUM, GPIO_PULLUP_ENABLE);
	GPIO_enablePullup(ROW_4_PORT_REG, ROW_4_PIN_NUM, GPIO_PULLUP_ENABLE);
	//Initialize the row pins to HIGH
	GPIO_writePin(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_HIGH);
	GPIO_writePin(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_HIGH);
	GPIO_writePin(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_HIGH);
	GPIO_writePin(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_HIGH);
}

//Get the pressed key
StdReturn Keypad_getKey(uint8 *key) {
	uint8 col = 1;	//Iterator for the columns
	uint8 row = 1;	//Iterator for rows
	GPIO_pinState buttonState = GPIO_HIGH;	//To get the button's reading

	for (col = 1; col <= 4; col++) {
		//Reset all columns to unselected
		GPIO_writePin(COL_1_PORT_REG, COL_1_PIN_NUM, GPIO_HIGH);
		GPIO_writePin(COL_2_PORT_REG, COL_2_PIN_NUM, GPIO_HIGH);
		GPIO_writePin(COL_3_PORT_REG, COL_3_PIN_NUM, GPIO_HIGH);
		GPIO_writePin(COL_4_PORT_REG, COL_4_PIN_NUM, GPIO_HIGH);
		//Select the next column
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
		//Get all the rows readings
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
			//Check whether there is a pressed button
			if(buttonState == GPIO_LOW){
				break;
			}

		}
		//Check if pressed button is found
		if(row <= 4){
			break;
		}

	}
	//Map the button reading to a button value
	if(col <= 4){
		*key = keypadButtons[row-1][col-1];
	}
	else{
		*key = KEYPAD_NO_BUTTON_PRESSED;
	}

	return E_OK;
}

