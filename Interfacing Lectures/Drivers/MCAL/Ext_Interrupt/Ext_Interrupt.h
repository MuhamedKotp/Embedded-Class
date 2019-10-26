/*
 * Ext_Interrupt.h
 *
 *  Created on: Oct 25, 2019
 *      Author: Muhamed Kotp
 */

#ifndef MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_

#include "../../Controller/ATMEGA16/Registers.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"


typedef enum{
	EXTINT_RISING_EDGE,
	EXTINT_FALLING_EDGE
}extInt_senseControl;

extern void extInt_init(void);

extern StdReturn extInt0_init(extInt_senseControl senseLevel);
extern StdReturn extInt0_callback(void (*func_ptr)(void));

extern StdReturn extInt1_init(extInt_senseControl senseLevel);
extern StdReturn extInt1_callback(void (*func_ptr)(void));

extern StdReturn extInt2_init(extInt_senseControl senseLevel);
extern StdReturn extInt2_callback(void (*func_ptr)(void));



#endif /* MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_ */
