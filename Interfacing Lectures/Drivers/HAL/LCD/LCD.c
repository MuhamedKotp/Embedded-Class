/*
 ============================================================================
 Name        : LCD.c
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of LCD driver
 ============================================================================
 */

/*********************************/
/*****Files include section*******/
/*********************************/
#include "LCD.h"
#include "LCD_cfg.h"


/************************************/
/****Private functions prototypes****/
/************************************/
static void writeByte(uint8 data);
static void intToString(uint16 number, uint8 *txt);


/*********************************/
/****Functions implementation*****/
/*********************************/
//configure LCD pins
void LCD_init(void) {
	GPIO_setPinDirection(RS_PORT_REG, RS_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(E_PORT_REG, E_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D7_PORT_REG, D7_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D6_PORT_REG, D6_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D5_PORT_REG, D5_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D4_PORT_REG, D4_PIN, GPIO_OUTPUT);
#ifdef _8_BIT_MODE
	GPIO_setPinDirection(D3_PORT_REG, D3_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D2_PORT_REG, D2_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D1_PORT_REG, D1_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D0_PORT_REG, D0_PIN, GPIO_OUTPUT);
#endif
	LCD_writeCmd(LCD_GO_HOME);
	LCD_writeCmd(LCD_4_BIT_MODE);
	LCD_writeCmd(lCD_CLEAR);
	LCD_writeCmd(LCD_CURSOR_OFF);

	_delay_ms(10);
}

//Function to  send command to LCD
StdReturn LCD_writeCmd(uint8 cmd) {
	GPIO_writePin(RS_PORT_REG, RS_PIN, GPIO_LOW);
	writeByte(cmd);
	return E_OK;
}

//Function to  write single character on the LCD
StdReturn LCD_writeChar(uint8 data) {
	GPIO_writePin(RS_PORT_REG, RS_PIN, GPIO_HIGH);
	writeByte(data);
	return E_OK;
}

//Function to  write text on the LCD
StdReturn LCD_writeTxt(uint8 *text) {
	uint32 i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		LCD_writeChar(text[i]);
	}

	return E_OK;
}

//Function to  write number on the LCD
StdReturn LCD_writeNumber(uint16 num) {
	char txt[50] = { 0 };

	intToString(num, txt);
	LCD_writeTxt(txt);

	return E_OK;
}

/*****************************************/
/***Private functions implementation******/
/*****************************************/
/* Brief:	Sends a byte to the LCD
 * Scope:	Private
 * Input:	data 	-> Type uint8	-> The byte to be sent to the LCD
 * Output:  no output
 * return:	void
 * prerequisites:	No prerequisites
 */
static void writeByte(uint8 data) {
#ifdef	_4_BIT_MODE
	//Send first nibble
	if (READ_BIT(data, 7) == 1) {
		GPIO_writePin(D7_PORT_REG, D7_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D7_PORT_REG, D7_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 6) == 1) {
		GPIO_writePin(D6_PORT_REG, D6_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D5_PORT_REG, D6_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 5) == 1) {
		GPIO_writePin(D5_PORT_REG, D5_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D5_PORT_REG, D5_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 4) == 1) {
		GPIO_writePin(D4_PORT_REG, D4_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D4_PORT_REG, D4_PIN, GPIO_LOW);
	}
	//Send enable pulse
	GPIO_writePin(E_PORT_REG, E_PIN, GPIO_HIGH);
	_delay_ms(1);
	GPIO_writePin(E_PORT_REG, E_PIN, GPIO_LOW);
	_delay_ms(1);

	//Send second nibble
	if (READ_BIT(data, 3) == 1) {
		GPIO_writePin(D7_PORT_REG, D7_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D7_PORT_REG, D7_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 2) == 1) {
		GPIO_writePin(D6_PORT_REG, D6_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D6_PORT_REG, D6_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 1) == 1) {
		GPIO_writePin(D5_PORT_REG, D5_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D5_PORT_REG, D5_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 0) == 1) {
		GPIO_writePin(D4_PORT_REG, D4_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D4_PORT_REG, D4_PIN, GPIO_LOW);
	}

	//Send enable pulse
	GPIO_writePin(E_PORT_REG, E_PIN, GPIO_HIGH);
	_delay_ms(1);
	GPIO_writePin(E_PORT_REG, E_PIN, GPIO_LOW);
	_delay_ms(1);
#elif
	if (READ_BIT(data, 7) == 1) {
		GPIO_writePin(D7_PORT_REG, D7_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D7_PORT_REG, D7_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 6) == 1) {
		GPIO_writePin(D6_PORT_REG, D6_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D5_PORT_REG, D6_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 5) == 1) {
		GPIO_writePin(D5_PORT_REG, D5_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D5_PORT_REG, D5_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 4) == 1) {
		GPIO_writePin(D4_PORT_REG, D4_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D4_PORT_REG, D4_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 3) == 1) {
		GPIO_writePin(D3_PORT_REG, D3_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D3_PORT_REG, D3_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 2) == 1) {
		GPIO_writePin(D2_PORT_REG, D2_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D2_PORT_REG, D2_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 1) == 1) {
		GPIO_writePin(D1_PORT_REG, D1_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D1_PORT_REG, D1_PIN, GPIO_LOW);
	}

	if (READ_BIT(data, 0) == 1) {
		GPIO_writePin(D0_PORT_REG, D0_PIN, GPIO_HIGH);
	} else {
		GPIO_writePin(D0_PORT_REG, D0_PIN, GPIO_LOW);
	}

	//Send enable pulse
	GPIO_writePin(E_PORT_REG, E_PIN, GPIO_HIGH);
	_delay_ms(1);
	GPIO_writePin(E_PORT_REG, E_PIN, GPIO_LOW);
	_delay_ms(1);
#endif

}

/* Brief:	Convert integer number into string
 * Details:	This function converts integer number into string
 * 			-Max integer number = 999999
 * Scope:	Private
 * Input:	number 	-> Type uint16	-> The integer number to be converted
 * Output:  *txt	-> Type uint8*	-> The converted text
 * return:	void
 * prerequisites:	No prerequisites
 */
static void intToString(uint16 number, uint8 *txt) {
	uint32 i = 0;
	uint8 j = 0;

	for (i = 100000, j = 0; i >= 10; i /= 10) {
		if ((number / i) == 0) {

		} else {
			txt[j] = (number / i) + 48;
			number = number % i;
			j++;
		}
	}
	//Save the ascii of the number
	txt[j] = number + 48;
	//Terminate the string with NULL
	j++;
	txt[j] = '\0';
}
