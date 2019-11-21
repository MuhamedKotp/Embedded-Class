/*
 ============================================================================
 Name        : Timer0.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 8/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for timer 0 Driver
 	 	 	  -This driver uses CTC mode for time in microseconds
 	 	 	  -This driver uses OVF mode for time in milliseconds
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"
#include "../../Controller/ATMEGA32/Interrupts.h"

/***************************************************************
 *********************Data types section************************
 **************************************************************/
//Data type for selecting timer0 mode
typedef enum{
	TIMER0_MODE_OVF,	//Overflow mode
	TIMER0_MODE_CTC		//Capture compare mode
}Timer0_enuMode;

//Data type for timer0 configuration
typedef struct{
	Timer0_enuMode Timer0_mode;

}Timer0_strConfig;

//Data type for selecting interrupt Enable/Disable
typedef enum{
	Timer0_INTERRUPT_ENABLE,
	Timer0_INTERRUPT_DISABLE
}Timer0_enuInterruptState;

/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//Initialize timer0 with required configuration
extern StdReturn Timer0_init(Timer0_enuMode timer0Mode);

//Start timer0 to count (time) microseconds
//Constraints: 0 < time < 999
extern StdReturn Timer0_startUs(uint16 time);

//Start timer0 to count (time) milliseconds
//Constraints: 0 < time < 999
extern StdReturn Timer0_startMs(uint16 time);

//Stop timer counting
extern StdReturn Timer0_stop(void);
//Get timer0 counts
extern StdReturn Timer0_getTicks(uint16 *counts);
//Set user required function to be implemented on timer0 ISR
extern void Timer0_callback(void (*func_ptr)(void));


#endif /* MCAL_TIMER0_TIMER0_H_ */
