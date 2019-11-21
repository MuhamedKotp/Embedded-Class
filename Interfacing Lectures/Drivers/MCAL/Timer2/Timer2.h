/*
 ============================================================================
 Name        : Timer2.h
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 8/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for timer 2 Driver
 	 	 	  -This driver uses CTC mode for time in microseconds
 	 	 	  -This driver uses OVF mode for time in milliseconds
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef MCAL_Timer2_Timer2_H_
#define MCAL_Timer2_Timer2_H_

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
//Data type for selectingtimer2 mode
typedef enum{
	TIMER2_MODE_OVF,	//Overflow mode
	TIMER2_MODE_CTC		//Capture compare mode
}Timer2_enuMode;

//Data type fortimer2 configuration
typedef struct{
	Timer2_enuMode Timer2_mode;

}Timer2_strConfig;

//Data type for selecting interrupt Enable/Disable
typedef enum{
	Timer2_INTERRUPT_ENABLE,
	Timer2_INTERRUPT_DISABLE
}Timer2_enuInterruptState;

/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//Initializetimer2 with required configuration
extern StdReturn Timer2_init(Timer2_enuMode timer2Mode);

//Starttimer2 to count (time) microseconds
//Constraints: 0 < time < 999
extern StdReturn Timer2_startUs(uint16 time);

//Starttimer2 to count (time) milliseconds
//Constraints: 0 < time < 999
extern StdReturn Timer2_startMs(uint16 time);

//Stop timer counting
extern StdReturn Timer2_stop(void);
//Gettimer2 counts
extern StdReturn Timer2_getTicks(uint16 *counts);
//Set user required function to be implemented ontimer2 ISR
extern void Timer2_callback(void (*func_ptr)(void));


#endif /* MCAL_Timer2_Timer2_H_ */
