/*
 ============================================================================
 Name        : OS.h
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Configuration file for the OS
 ============================================================================
 */
//To protect the file against multiple includes
#ifndef OS_OS_CFG_H_
#define OS_OS_CFG_H_

/********************************************/
/************Files include section***********/
/********************************************/


/********************************************/
/*********Data Defines section***************/
/********************************************/
//Max allowed tasks
#define MAX_TASK_NUMBER		3

//System tick
#define SYSTEM_TICK_US	500

#endif /* OS_OS_CFG_H_ */
