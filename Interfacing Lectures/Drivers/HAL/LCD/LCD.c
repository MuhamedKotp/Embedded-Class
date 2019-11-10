/*
 * LCD.c
 *
 *  Created on: Oct 19, 2019
 *      Author: Kotp
 */
#include "LCD.h"
#include "LCD_cfg.h"

static void writeByte(uint8 data);
static void intToString(uint16 number, uint8 *txt);

//configure LCD pins
void LCD_init(void) {
	GPIO_setPinDirection(RS_PORT_REG, RS_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(E_PORT_REG, E_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D7_PORT_REG, D7_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D6_PORT_REG, D6_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D5_PORT_REG, D5_PIN, GPIO_OUTPUT);
	GPIO_setPinDirection(D4_PORT_REG, D4_PIN, GPIO_OUTPUT);

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

////////////////////////////////////////
static void writeByte(uint8 data) {
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
}

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
	txt[j] = number + 48;
	j++;
	txt[j] = '\0';
}
