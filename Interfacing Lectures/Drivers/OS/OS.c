/*
 ============================================================================
 Name        : OS.c
 Author      : Muhamed Kotp
 Layer		 : HAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 19/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Implementation file of OS
 ============================================================================
 */
/*********************************************/
/************Files include section************/
/*********************************************/
#include "OS.h"
#include "OS_cfg.h"

/*********************************************/
/************Private data section************/
/*********************************************/
typedef struct {
	uint16 periodicity;
	void (*userFunc)(void);
} Task;

Task tasks[MAX_TASK_NUMBER];

static void scheduler(void);
static uint32 OS_systemTick = 0;

/*********************************************/
/*****Functions Implementation section********/
/*********************************************/
//Configure new task
extern void OS_taskCreate(uint8 priority, uint16 periodicity,
		void (*user_Task)(void)) {
	tasks[priority].periodicity = periodicity;
	tasks[priority].userFunc = user_Task;
}

//Initialize OS
extern void OS_init(void) {
	Timer0_init(TIMER0_MODE_CTC);
	Timer0_callback(scheduler);
}

//Start OS scheduler
extern void OS_startScheduler(void) {
	Timer0_startUs(SYSTEM_TICK_US);
}

//Stop OS scheduler
extern void OS_stopScheduler(void) {
	Timer2_stop();
}

/*********************************************/
/*****Private Functions Implementation********/
/*********************************************/
static void scheduler(void) {
	uint8 i = 0;
	OS_systemTick++;
	//Loop on all tasks
	for (i = 0; i < MAX_TASK_NUMBER; i++) {
		//Check tasks periodicities
		if (OS_systemTick % tasks[i].periodicity == 0) {
			tasks[i].userFunc();
		} else {
			//Do nothing
		}
	}
}

