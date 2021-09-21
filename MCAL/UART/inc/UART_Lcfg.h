/*
 * UART_Cfg.h
 *
 * Created: 11/12/2019 11:30:27 AM
 *  Author: AVE-LAP-025
 */ 


#ifndef UART_LCFG_H_
#define UART_LCFG_H_

#include "std_types.h"


/*****************************************************************************************/
/*	               This file is the header file that contains configuration of UART       */  
/*******************************************************************************************/


/*
 * The following macros used to initialize the configuration struct UART_Cfg_S
 */

/******************************** Data Bits Configurations******************************/
#define UART_DataBits_5			(uint8)0
#define UART_DataBits_6			(uint8)1
#define UART_DataBits_7			(uint8)2
#define UART_DataBits_8			(uint8)3

/******************************** Parity Bit Configurations*****************************/
#define UART_ParityBit_None		(uint8)0
#define UART_ParityBit_Odd		(uint8)1
#define UART_ParityBit_Even		(uint8)2

/********************************** Stop Bits Configurations ***************************/
#define UART_StopBits_1			(uint8)0
#define UART_StopBits_2			(uint8)1

/********************************** Interrupt Bits Configurations ***************************/
#define POLLING			        (uint8)0
#define INTERRUPT			    (uint8)1


/***************************** UART Linking configuration structure *******************/

typedef struct{
	uint32 BaudRate;
	uint8 DataBits;
	uint8 ParityBit;
	uint8 StopBits;
	uint8 ReceiveInterrupt;
	uint32 CPU_Clock;
}UART_Cfg_S;

/********************************** UART Baud Rate definitions*************************/

#define BAUDRATE_9600     9600
#define BAUDRATE_14400   14400
#define BAUDRATE_19200   19200
#define BAUDRATE_28800   28800
#define BAUDRATE_38400   38400
#define BAUDRATE_57600   57600
#define BAUDRATE_76800   76800
#define BAUDRATE_115200 115200

/********************************** UART Baud Rate definitions*************************/
#define F_CPU_16M 16000000UL
#define F_CPU_8M  8000000UL
extern UART_Cfg_S uart_cfg;

#endif /* UART_LCFG_H_ */