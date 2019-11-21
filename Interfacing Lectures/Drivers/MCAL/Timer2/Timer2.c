/*
 ============================================================================
 Name        : Timer2.c
 Author      : Muhamed Kotp
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 8/11/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of timer 2 Driver
 ============================================================================
 */
/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "Timer2.h"
#include "Timer2_cfg.h"

/***************************************************************
 *********************Private data section**********************
 **************************************************************/
//Local pointer to function to be used in timer ISR
static void (*user_ptr)(void);
static uint8 overflowCounter = 0;
static uint8 overflowCountsRequired = 0;

#define TIMER_MAX_COUNTS	0xFF
#define MS_TO_US			1000
#define MAX_ALLOWED_TIME	999
#define PRESCALER_1024	1024
#define PRESCALER_256	256
#define PRESCALER_128	128
#define PRESCALER_64	64
#define PRESCALER_32	32
#define PRESCALER_8		8
#define PRESCALER_1		1
#define PRESCALER_NO	0

/***************************************************************
 *************Private functions prototypes**********************
 **************************************************************/
//Function to configure the prescaler and the OCR value
static StdReturn setPrescaler_OCR(uint16 time);

/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
//ISR of CTC mode
ISR(TIMER2_COMP_vect) {
	(*user_ptr)();	//Execute the user function
}
//ISR of overflow mode
ISR(TIMER2_OVF_vect) {
	overflowCounter++;
	if (overflowCounter >= overflowCountsRequired) {
		(*user_ptr)();	//Execute the user function
		overflowCounter = 0;
	}
}

//Set user required function to be implemented on timer0 ISR
extern void Timer2_callback(void (*func_ptr)(void)) {
	user_ptr = func_ptr;
}

//Initialize timer0 with required configuration
extern StdReturn Timer2_init(Timer2_enuMode timer2Mode) {
	switch (timer2Mode) {
	case TIMER2_MODE_CTC:
		//Set mode to CTC
		SET_BIT(TCCR2, WGM21);
		CLEAR_BIT(TCCR2, WGM20);
		break;
	case TIMER2_MODE_OVF:
		//Set mode to overflow
		CLEAR_BIT(TCCR2, WGM21);
		CLEAR_BIT(TCCR2, WGM20);
		break;
	default:
		return E_NOK;
	}

	return E_OK;
}

//Get timer2 counts
extern StdReturn Timer2_getTicks(uint16 *counts) {
	*counts = TCNT2 + (overflowCounter * TIMER_MAX_COUNTS);
	return E_OK;
}

//Start timer2 to count (time) microseconds
//Constraints: 0 < time < 999
extern StdReturn Timer2_startUs(uint16 time) {
	StdReturn return_Loc = E_NOK;
	if (time <= MAX_ALLOWED_TIME) {
		//Configure prescaler and OCR value
		return_Loc = setPrescaler_OCR(time);
		//Enable CTC interrupt
		SET_BIT(TIMSK, OCIE2);
	} else {
		//Do nothing - returning E_NOK
	}
	return return_Loc;
}

extern StdReturn Timer2_startMs(uint16 time) {
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
				* (f32) TIMER_MAX_COUNTS);
		//If the required time exceeds the max allowed time then calculate number of overflows needed
		countsNum_Loc = (uint16) (time_Loc / maxTime_Loc);
		//Calculate the fraction needed after overflows
		timePrescaled_Loc = (uint16) (time_Loc
				- ((uint32) countsNum_Loc * maxTime_Loc));
		//Configure the prescaler and OVF values
		return_Loc = setPrescaler_OCR(timePrescaled_Loc);

		//Enable OVF interrupt
		SET_BIT(TIMSK, TOIE2);
	} else {
		//Do nothing - returning E_NOK
	}
	return return_Loc;
}

extern StdReturn Timer2_stop(void) {
	//Disable CTC interrupt
	CLEAR_BIT(TIMSK, OCIE2);
	//Disable overflow interrupt
	CLEAR_BIT(TIMSK, TOIE2);
	//Set prescaler to timer off
	CLEAR_BIT(TCCR2, CS20);
	CLEAR_BIT(TCCR2, CS21);
	CLEAR_BIT(TCCR2, CS22);
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
	prescaler_Loc = (uint16) (timeRatio_Loc / TIMER_MAX_COUNTS);
	//Set the prescaler
	if (prescaler_Loc == PRESCALER_NO) {	//No prescaler needed
		SET_BIT(TCCR2, CS20);	//Set No prescaler
		prescaler_Loc = PRESCALER_1;
	} else if (prescaler_Loc > PRESCALER_NO && prescaler_Loc < PRESCALER_8) {
		SET_BIT(TCCR2, CS21);	//Set prescaler = 8
		prescaler_Loc = PRESCALER_8;
	} else if (prescaler_Loc >= PRESCALER_8 && prescaler_Loc < PRESCALER_32) {
		SET_BIT(TCCR2, CS20);	//Set prescaler = 32
		SET_BIT(TCCR2, CS21);	//Set prescaler = 32
		prescaler_Loc = PRESCALER_32;
	} else if (prescaler_Loc >= PRESCALER_32 && prescaler_Loc < PRESCALER_64) {
		SET_BIT(TCCR2, CS22);	//Set prescaler = 64
		prescaler_Loc = PRESCALER_64;
	} else if (prescaler_Loc >= PRESCALER_64 && prescaler_Loc <= PRESCALER_128) {
		SET_BIT(TCCR2, CS20);	//Set prescaler = 128
		SET_BIT(TCCR2, CS22);	//Set prescaler = 128
		prescaler_Loc = PRESCALER_128;
	}else if (prescaler_Loc >= PRESCALER_128 && prescaler_Loc <= PRESCALER_256) {
		SET_BIT(TCCR2, CS21);	//Set prescaler = 256
		SET_BIT(TCCR2, CS22);	//Set prescaler = 256
		prescaler_Loc = PRESCALER_256;
	}else if (prescaler_Loc >= PRESCALER_256 && prescaler_Loc <= PRESCALER_1024) {
		SET_BIT(TCCR2, CS20);	//Set prescaler = 1024
		SET_BIT(TCCR2, CS21);	//Set prescaler = 1024
		SET_BIT(TCCR2, CS22);	//Set prescaler = 1024
		prescaler_Loc = PRESCALER_1024;
	}
	else {
		return E_NOK;
	}

	//Calculate the compare value
	OcrValue_Loc = (uint8) (timeRatio_Loc / prescaler_Loc) - 1;
	//Set OCR register
	OCR2 = OcrValue_Loc;

	return E_OK;
}
