/*
 ============================================================================
 Name        : Keypad_cfg.h
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Configuration file for Keypad Driver
 	 	 	   -Configure the keypad pins
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

/********************************/
/*****Keypad connected ports*****/
/********************************/
#define COL_1_PORT_REG  GPIO_PORTD
#define COL_2_PORT_REG	GPIO_PORTD
#define COL_3_PORT_REG	GPIO_PORTD
#define COL_4_PORT_REG	GPIO_PORTD
#define ROW_1_PORT_REG	GPIO_PORTD
#define ROW_2_PORT_REG	GPIO_PORTD
#define ROW_3_PORT_REG	GPIO_PORTD
#define ROW_4_PORT_REG	GPIO_PORTD


/********************************/
/*****Keypad connected pins*****/
/********************************/
#define COL_1_PIN_NUM	0
#define COL_2_PIN_NUM	1
#define COL_3_PIN_NUM	2
#define COL_4_PIN_NUM	3
#define ROW_1_PIN_NUM	4
#define ROW_2_PIN_NUM	5
#define ROW_3_PIN_NUM	6
#define ROW_4_PIN_NUM	7


#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
