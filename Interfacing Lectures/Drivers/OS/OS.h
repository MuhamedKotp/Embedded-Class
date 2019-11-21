/*
 ============================================================================
 Name        : OS.h
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for the OS
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef OS_OS_H_
#define OS_OS_H_

/*********************************/
/*****Files include section*******/
/*********************************/
#include "../Service/StdTypes.h"
#include "../MCAL/Timer0/Timer0.h"

/********************************************/
/*********Data types Defines section*********/
/********************************************/


/***************************************************************
 *********************Prototypes section************************
 **************************************************************/
//Initialize OS
extern void OS_init(void);
//Configure new task
extern void OS_taskCreate(uint8 priority, uint16 periodicity, void (*user_Task)(void));
//Start OS scheduler
extern void OS_startScheduler(void);
//Stop OS scheduler
extern void OS_stopScheduler(void);


#endif /* OS_OS_H_ */
