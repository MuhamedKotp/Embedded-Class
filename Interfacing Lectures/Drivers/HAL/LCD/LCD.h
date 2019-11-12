/*
 ============================================================================
 Name        : LCD.h
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for the LCD driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

/*********************************/
/*****Files include section*******/
/*********************************/
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../MCAL/GPIO/GPIO.h"
#include <util/delay.h>

/*********************************/
/*********Defines section*********/
/*********************************/
//Define commands list
#define lCD_CLEAR			0x01		//Clear the screen
#define LCD_GO_HOME		 	0x02		//Go to 0,0 line
#define LCD_4_BIT_MODE 		0x28		//Set LCD to 4 bit mode
#define LCD_CURSOR_OFF		0x0C		//Turn off cursor


/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//configure LCD pins
void LCD_init(void);
//Function to  send command to LCD
StdReturn LCD_writeCmd(uint8 cmd);
//Function to  write single character on the LCD
StdReturn LCD_writeChar(uint8 data);
//Function to  write text on the LCD
StdReturn LCD_writeTxt(uint8 *text);
//Function to  write number on the LCD
StdReturn LCD_writeNumber(uint16 num);




#endif /* HAL_LCD_LCD_H_ */
