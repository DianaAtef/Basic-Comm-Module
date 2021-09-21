/******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description: main
 *
 * Author: Diana Atef George
 *
 *******************************************************************************/

#include "Registers.h"
#include "Bcm.h"
#include "interrupt.h"

uint8 Buffer[]={5,2,3,8,9,10,12,14};
uint8 Rxbuffer[10]={0};

int main(void)
{
	BCM_Init();	
	BCM_Setup_Receive(1,Rxbuffer,5);
    SET_BIT(SREG,I);
	PORTB_DIR=0XFF;
    while (1) 
    {	
		BCM_RxDispatch();
		
    }
}

