/*
 * std_types.h
 *
 * Created: 11/9/2019 7:28:46 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define SYS_TICK_MS (5)


/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/


#define NULL	((void *)0)

typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long int sint32;
typedef signed long long sint64;
typedef volatile uint8* const reg_type;
typedef uint8 bool;

/*
 * General Types
 */
typedef bool STATUS;
#define E_OK		(STATUS) 1
#define E_NOT_OK	(STATUS) 0

/************************************************************************/
/*				 		defining boolean values                         */
/************************************************************************/
#define FALSE 	0	// defines boolean false
#define TRUE 	1	// defines boolean true


/************************************************************************/
/*						 LOW/HIGH defines                               */
/************************************************************************/
#define LOW  0		// defines LOW value for a bit
#define HIGH 0xFF	// defines HIGH value for a bit


/************************************************************************/
/*				 Bits' Manipulation Macros	                            */
/************************************************************************/
#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLR_BIT(reg,bit)	reg&=~(1<<bit)
#define READ_BIT(reg,bit)	(reg&(1<<bit))
#define TOGGLE_BIT(reg,bit)	reg^=(1<<bit)

#define ZERO  0
#define ONE   1
#define TWO   2
#define THREE 3
#define FOUR  4
#define FIVE  5

#endif /* STD_TYPES_H_ */