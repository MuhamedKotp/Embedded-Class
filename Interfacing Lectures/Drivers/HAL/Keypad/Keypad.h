/*
 ============================================================================
 Name        : Keypad.h
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for Keypad Driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_


/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "../../Service/StdTypes.h"
#include "../../Service/StdMacros.h"
#include "../../MCAL/GPIO/GPIO.h"

/***************************************************************
 *******************Data definition section*********************
 **************************************************************/
#define KEYPAD_NO_BUTTON_PRESSED	0xFF

/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//Initialize the keypad driver - initialize the keypad pins
extern void Keypad_init(void);
//Get the pressed key
extern StdReturn Keypad_getKey (uint8 *key);


#endif /* HAL_KEYPAD_KEYPAD_H_ */
