/*
 ============================================================================
 Name        : StdMacros.h
 Author      : Muhamed Kotp
 Layer		 : Service layer
 Target		 : Generic
 Version     : 1.0
 Date		 : 20/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Standard macros to ease handling with registers
  	  	  	   It defines macros to
  	  	  	   -set specific bit in a register
  	  	  	   -Clear a specific bit in a register
  	  	  	   -read specific bit in a register
  	  	  	   -set register value
  	  	  	   -read register value
 ============================================================================
 */

#ifndef SERVICE_STDMACROS_H_
#define SERVICE_STDMACROS_H_


//This macro used to set a specific bit in a register
#define SET_BIT(reg, bit)	(reg |= (1<<bit))

//This macro used to clear a specific bit in a register
#define CLEAR_BIT(reg, bit)	(reg &= ~(1<<bit))

//This macro used to read a specific bit from a register
//It returns 1 if bit is 1 AND returns 0 if bit is 0
#define READ_BIT(reg, bit)	((reg & (1<<bit))?1:0)


#endif /* SERVICE_STDMACROS_H_ */
