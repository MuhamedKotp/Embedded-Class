/*
 ============================================================================
 Name        : Timer0.c
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 8/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of timer 0 Driver
 ============================================================================
 */
/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "Timer0.h"
#include "Timer0_cfg.h"

/***************************************************************
 *********************Private data section**********************
 **************************************************************/
//Local pointer to function to be used in timer ISR
static void (*user_ptr)(void);
static uint8 overflowCounter = 0;
static uint8 overflowCountsRequired = 0;

#define TIMER0_MAX_COUNTS	0xFF
#define MS_TO_US		1000
#define MAX_ALLOWED_TIME	999
#define PRESCALER_1024	1024
#define PRESCALER_256	256
#define PRESCALER_64	64
#define PRESCALER_8		8
#define PRESCALER_1		1

/***************************************************************
 *************Private functions prototypes**********************
 **************************************************************/
//Function to configure the prescaler and the OCR value
static StdReturn setPrescaler_OCR(uint16 time);

/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
//ISR of CTC mode
ISR(TIMER0_COMP_vect) {
	(*user_ptr)();	//Execute the user function
}
//ISR of overflow mode
ISR(TIMER0_OVF_vect) {
	overflowCounter++;
	if (overflowCounter >= overflowCountsRequired) {
		(*user_ptr)();	//Execute the user function
		overflowCounter = 0;
	}
}

//Set user required function to be implemented on timer0 ISR
extern void Timer0_callback(void (*func_ptr)(void)) {
	user_ptr = func_ptr;
}

//Initialize timer0 with required configuration
extern StdReturn Timer0_init(Timer0_enuMode timer0Mode) {
	switch (timer0Mode) {
	case TIMER0_MODE_CTC:
		//Set mode to CTC
		SET_BIT(TCCR0, WGM01);
		CLEAR_BIT(TCCR0, WGM00);
		break;
	case TIMER0_MODE_OVF:
		//Set mode to overflow
		CLEAR_BIT(TCCR0, WGM01);
		CLEAR_BIT(TCCR0, WGM00);
		break;
	default:
		return E_NOK;
	}

	return E_OK;
}

//Get timer0 counts
extern StdReturn Timer0_getTicks(uint16 *counts) {
	*counts = TCNT0 + (overflowCounter * TIMER0_MAX_COUNTS);
	return E_OK;
}

//Start timer0 to count (time) microseconds
//Constraints: 0 < time < 999
extern StdReturn Timer0_startUs(uint16 time) {
	StdReturn return_Loc = E_NOK;
	if (time <= MAX_ALLOWED_TIME) {
		//Configure prescaler and OCR value
		return_Loc = setPrescaler_OCR(time);
		//Enable CTC interrupt
		SET_BIT(TIMSK, OCIE0);
	} else {
		//Do nothing - returning E_NOK
	}
	return return_Loc;
}

extern StdReturn Timer0_startMs(uint16 time) {
	StdReturn return_Loc = E_NOK;
	uint32 maxTime_Loc = 0;
	uint32 time_Loc = 0;
	uint16 timePrescaled_Loc = 0;
	uint16 countsNum_Loc = 0;

	//Check input validity
	if (time <= MAX_ALLOWED_TIME) {
		//Convert time into microseconds
		time_Loc = time * MS_TO_US;
		//Calculate maximum time that timer0 can provide using configured values
		maxTime_Loc = (uint32) ((f32) (1 / F_CRYSTAL_MHZ) * (f32) PRESCALER_1024
				* (f32) TIMER0_MAX_COUNTS);
		//If the required time exceeds the max allowed time then calculate number of overflows needed
		countsNum_Loc = (uint16) (time_Loc / maxTime_Loc);
		//Calculate the fraction needed after overflows
		timePrescaled_Loc = (uint16) (time_Loc
				- ((uint32) countsNum_Loc * maxTime_Loc));
		//Configure the prescaler and OVF values
		return_Loc = setPrescaler_OCR(timePrescaled_Loc);

		//Enable OVF interrupt
		SET_BIT(TIMSK, TOIE0);
	} else {
		//Do nothing - returning E_NOK
	}
	return return_Loc;
}

extern StdReturn Timer0_stop(void) {
	//Disable CTC interrupt
	CLEAR_BIT(TIMSK, OCIE0);
	//Disable overflow interrupt
	CLEAR_BIT(TIMSK, TOIE0);
	//Set prescaler to timer off
	CLEAR_BIT(TCCR0, CS00);
	CLEAR_BIT(TCCR0, CS01);
	CLEAR_BIT(TCCR0, CS02);
	return E_OK;
}

/************************************************************/
/*************Local Functions Implementation*****************/
/************************************************************/
static StdReturn setPrescaler_OCR(uint16 time) {
	uint16 prescaler_Loc = 0;
	uint8 OcrValue_Loc = 0;
	uint16 timeRatio_Loc = 0;

	timeRatio_Loc = time * (uint16) F_CRYSTAL_MHZ;
	//Calculate the prescaler
	prescaler_Loc = (uint16) (timeRatio_Loc / TIMER0_MAX_COUNTS);
	//Set the prescaler
	if (prescaler_Loc == 0) {	//No prescaler needed
		SET_BIT(TCCR0, CS00);	//Set No prescaler
		prescaler_Loc = PRESCALER_1;
	} else if (prescaler_Loc > 0 && prescaler_Loc < 8) {
		SET_BIT(TCCR0, CS01);	//Set prescaler = 8
		prescaler_Loc = PRESCALER_8;
	} else if (prescaler_Loc >= 8 && prescaler_Loc < 64) {
		SET_BIT(TCCR0, CS00);	//Set prescaler = 64
		SET_BIT(TCCR0, CS01);	//Set prescaler = 64
		prescaler_Loc = PRESCALER_64;
	} else if (prescaler_Loc >= 64 && prescaler_Loc < 256) {
		SET_BIT(TCCR0, CS02);	//Set prescaler = 256
		prescaler_Loc = PRESCALER_256;
	} else if (prescaler_Loc >= 256 && prescaler_Loc <= 1024) {
		SET_BIT(TCCR0, CS00);	//Set prescaler = 1024
		SET_BIT(TCCR0, CS02);	//Set prescaler = 1024
		prescaler_Loc = PRESCALER_1024;
	} else {
		return E_NOK;
	}

	//Calculate the compare value
	OcrValue_Loc = (uint8) (timeRatio_Loc / prescaler_Loc) - 1;
	//Set OCR register
	OCR0 = OcrValue_Loc;

	return E_OK;
}
