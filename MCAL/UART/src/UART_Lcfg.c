/*
 * UART_Lcfg.c
 *
 * Created: 11/12/2019 12:01:22 PM
 *  Author: AVE-LAP-025
 */ 

#include "UART_Lcfg.h"

UART_Cfg_S uart_cfg=
{
	BAUDRATE_9600,
	UART_DataBits_8,
	UART_ParityBit_None,
	UART_StopBits_1,
	INTERRUPT,
	F_CPU_8M
};
