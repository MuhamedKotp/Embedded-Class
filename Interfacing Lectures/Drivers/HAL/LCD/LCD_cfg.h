/*
 ============================================================================
 Name        : LCD_cfg.h
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Configuration file for the LCD driver
 	 	 	   -Configure the LCD working mode (4bit - 8bit)
 	 	 	   -Configure the LDC pins connections
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/***************************/
/*****Pins connection*******/
/***************************/
#define RS_PIN	7		//RS pin
#define E_PIN	6		//Enable pin
#define D7_PIN	5		//D7 pin
#define D6_PIN	4		//D6 pin
#define D5_PIN	3		//D5 pin
#define D4_PIN	2		//D4 pin
//For 8bit mode un-comment these and modify the pin numbers to the right ones
//#define D3_PIN	5
//#define D2_PIN	4
//#define D1_PIN	3
//#define D0_PIN	2


/***************************/
/*****Port connection*******/
/***************************/
#define RS_PORT_REG  GPIO_PORTC
#define E_PORT_REG   GPIO_PORTC
#define D7_PORT_REG  GPIO_PORTC
#define D6_PORT_REG  GPIO_PORTC
#define D5_PORT_REG  GPIO_PORTC
#define D4_PORT_REG  GPIO_PORTC
//For 8bit mode un-comment these and modify the ports to the right ones
//#define D3_PORT_REG  GPIO_PORTC
//#define D2_PORT_REG  GPIO_PORTC
//#define D1_PORT_REG  GPIO_PORTC
//#define D0_PORT_REG  GPIO_PORTC


/***************************/
/********LCD Mode***********/
/***************************/
//Define only one from the following modes
//Comment the unused mode
#define _4_BIT_MODE			//LCD is 4 bit mode
//#define _8_BIT_MODE		//LCD is 8 bit mode


#endif /* HAL_LCD_LCD_CFG_H_ */
