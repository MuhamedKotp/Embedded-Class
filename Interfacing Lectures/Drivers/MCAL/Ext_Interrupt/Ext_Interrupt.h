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


extern void extInt_init(void);

extern void extInt_callback(void (*func_ptr)(void));


#endif /* MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_ */
