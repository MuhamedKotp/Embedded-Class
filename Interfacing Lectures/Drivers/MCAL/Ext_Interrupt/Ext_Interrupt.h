/*
 ============================================================================
 Name        : Ext_Interrupt.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 25/10/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for External interrupts Driver
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "../../Controller/ATMEGA16/Registers.h"
#include "../../Controller/ATMEGA32/Interrupts.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"


/***************************************************************
 *********************Data types section************************
 **************************************************************/
typedef enum{
	EXTINT_RISING_EDGE,
	EXTINT_FALLING_EDGE
}extInt_senseControl;



/***************************************************************
 *********************Prototypes section************************
 **************************************************************/

//Initialize external interrupt 0
extern StdReturn extInt0_init(extInt_senseControl senseLevel);
//Set the user function to be executed on ISR
extern StdReturn extInt0_callback(void (*func_ptr)(void));

//Initialize external interrupt 1
extern StdReturn extInt1_init(extInt_senseControl senseLevel);
//Set the user function to be executed on ISR
extern StdReturn extInt1_callback(void (*func_ptr)(void));

//Initialize external interrupt 2
extern StdReturn extInt2_init(extInt_senseControl senseLevel);
//Set the user function to be executed on ISR
extern StdReturn extInt2_callback(void (*func_ptr)(void));



#endif /* MCAL_EXT_INTERRUPT_EXT_INTERRUPT_H_ */
