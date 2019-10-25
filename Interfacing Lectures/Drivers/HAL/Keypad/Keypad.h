/*
 * Keypad.h
 *
 *  Created on: Oct 19, 2019
 *      Author: Muhamed Kotp
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../Service/StdTypes.h"
#include "../../Service/StdMacros.h"
#include "../../MCAL/GPIO/GPIO.h"



extern void Keypad_init(void);

extern StdReturn Keypad_getKey (uint8 *key);
//extern uint8 Keypad_getKey ();


#endif /* HAL_KEYPAD_KEYPAD_H_ */
