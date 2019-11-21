/*
 ============================================================================
 Name        : Keypad_cfg.c
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Configuration keypad buttons
 ============================================================================
 */
#include "../../Service/StdTypes.h"

//Define the keypad buttons
const uint8 keypadButtons[4][4] = {
		{'1', '2', '3', '+'},
		{'4', '5', '6', '-'},
		{'7', '8', '9', '/'},
		{'*', '0', '#', 'E'}
};
