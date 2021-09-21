/*
 * UART.h
 *
 * Created: 11/12/2019 11:27:16 AM
 *  Author: AVE-LAP-025
 */ 

/*****************************************************************************************/
/*	               This file is the header file of the UART                              */
/*****************************************************************************************/

#ifndef UART_H_
#define UART_H_
#include "UART_Lcfg.h"

uint8 UART_Init(UART_Cfg_S*uart_cfg);
uint8 UART_Send(uint8 Data);
uint8 UART_Receive(uint8*Read_Data);

void TxSetCallBack(void (*ptr)(void));
void RxSetCallBack(void (*ptr)(void));

uint8 getUdrValue(void);

#endif /* UART_H_ */