/******************************************************************************
 *
 * Module: BCM Module
 *
 * File Name: Bcm.c
 *
 * Description: Source file for BCM module
 *
 * Author: Diana Atef George
 *
 *******************************************************************************/

/****************************************
 *                includes              *
 ****************************************/

#include "Registers.h"
#include "UART.h"
#include "UART_Lcfg.h"
#include "Bcm.h"
#include "Std_Types.h"

/****************************************
*             Structure                 *
*****************************************/

typedef struct
{
	uint8 BufferId;
	uint8*address;
	uint8 checkSum;
	uint8 lock;
	uint8 position;
	uint16 length;
}gBCM_ConfigType_t;

gBCM_ConfigType_t BcmArray;
gBCM_ConfigType_t BcmArrayReceive;

/****************************************
*             Global Variable          *
*****************************************/

uint8 gsendHeader = ZERO;
uint8 gDispatchFlag = ZERO;
uint8 gStart = ZERO;
uint8 greceive = ZERO;
volatile uint8 RxBuffer[10];
uint8 RxBufferIndex = ZERO;
uint8 gStatus;
volatile uint8 counter = ZERO;
uint8 RxCounter = ZERO;
uint8 Rx_Count = ZERO;
uint8 gTxFlag=gTxFlagNOk;
volatile uint8 rxindex = ZERO;

/************************************************************************/
/*			 	       Bcm functions' Implementation	                */
/************************************************************************/

/************************************************************************************
* Function Name: Bcm_TxFinished
*
* Parameters (in):
* 	name        : void
*
* Parameters (in/out): void
*
* Parameters (out): None
*
* Return value: None
*
* Description: function to call back when transmission is finished 
*
************************************************************************************/

/*to transmit again*/
void Bcm_TxFinished(void)
{
	gTxFlag = gTxFlagOk;

}

/************************************************************************************
* Function Name: Bcm_RxFinished
*
* Parameters (in):
* 	name        : void
*
* Parameters (in/out): void
*
* Parameters (out): None
*
* Return value: None
*
* Description: function to call back when Receiving data occurs 
************************************************************************************/

void Bcm_RxFinished(void)
{
			
	counter++;
	RxBuffer[rxindex] = getUdrValue();
	rxindex++;

}

/************************************************************************************
* Function Name: BCM_Init
*
* Parameters (in):
* 	name        : void
*
* Parameters (in/out): void
*
* Parameters (out): None
*
* Return value: EnmBCMError_t
*
* Description: function to init Bcm
************************************************************************************/

EnmBCMError_t BCM_Init (void)
{
	TxSetCallBack(Bcm_TxFinished);
	RxSetCallBack(Bcm_RxFinished);
	UART_Init(&uart_cfg);
	return BCM_OK;
}

/************************************************************************************
* Function Name: BCM_Send
*
* Parameters (in):
* 	name        : ptr
* 	type        : uint8*
* 	Description	: ptr to buffer address in main 
*
* 	name        : length
* 	type        : uint8
* 	Description	: length of array which is to be sent
*
* Parameters (in/out): void
*
* Parameters (out): None
*
* Return value: EnmBCMError_t
*
* Description: function to initialize buffer structure
************************************************************************************/

/*to send request*/
EnmBCMError_t BCM_Send(uint8*ptr,uint8 length)
{
	
	BcmArray.BufferId = ZERO;
	BcmArray.length = length;
	BcmArray.address = ptr;
	BcmArray.checkSum = ZERO;
	BcmArray.lock = LOCK;
	BcmArray.position = ZERO;
	
	return BCM_OK;
}

/************************************************************************************
* Function Name: BCM_TxDispatch
*
* Parameters (in):
* 	name        : void
*
* Parameters (in/out): None
*
* Parameters (out): None
*
* Return value: None
*
* Description: BCM tx Dispatcher
*
***************************************************************************/

void BCM_TxDispatch(void)
{

	if(gsendHeader == ZERO)
	{
		
		if(gTxFlag == gTxFlagOk&& gDispatchFlag == ZERO )
		{
			gDispatchFlag=ONE;
			gTxFlag=gTxFlagNOk;
			UART_Send(BcmArray.BufferId);
		}	
		
		else if(gTxFlag == gTxFlagOk && gDispatchFlag == ONE)
		{
			gDispatchFlag = ZERO;
			gTxFlag = gTxFlagNOk;
			UART_Send(BcmArray.length);
			gsendHeader = ONE;
		}
	}
	
	else if(gsendHeader == ONE)
	{
		if(gTxFlag == gTxFlagOk && gDispatchFlag == ZERO && BcmArray.position<BcmArray.length)
		{
			gTxFlag=gTxFlagNOk;
			UART_Send(*(BcmArray.address));
			BcmArray.checkSum +=*(BcmArray.address);
			BcmArray.position += ONE;
			BcmArray.address++;
			
		}
		
		else if(gTxFlag==gTxFlagOk && BcmArray.position == BcmArray.length)
		{
			BcmArray.position++;
			UART_Send(BcmArray.checkSum);
			gTxFlag = gTxFlagNOk;
		}
		
		else if (gTxFlag == gTxFlagOk && BcmArray.position > BcmArray.length)
		{
			
			BcmArray.lock=UNLOCK;
			SREG &= ~(1<<7);
		}
		

	}
	
}

/************************************************************************************
* Function Name: BCM_Setup_Receive
*
* Parameters (in):
* 	name        : id
* 	type        : uint8
* 	Description	: buffer id 
*
* 	name        : address
* 	type        : uint8*
* 	Description	: ptr to buffer address
*
* 	name        : length
* 	type        : uint8
* 	Description	: length of receive buffer
*
* Parameters (in/out): None
*
* Parameters (out): None
*
* Return value: EnmBCMError_t
*
* Description: to configure receive buffer structure
*
***************************************************************************/

EnmBCMError_t BCM_Setup_Receive(uint8 id, uint8* address,uint8 length)
{
	BcmArrayReceive.BufferId = id;
	BcmArrayReceive.address = address;
	BcmArrayReceive.length = length;
	return BCM_OK;

}

/************************************************************************************
* Function Name: BCM_rxDispatch
*
* Parameters (in):
* 	name        : void
*
* Parameters (in/out): None
*
* Parameters (out): None
*
* Return value: None
*
* Description: BCM rx Dispatcher
*
***************************************************************************/
EnmBCMError_t BCM_RxDispatch()
{
	uint8 lError = BCM_OK;
		
	#if 1

	if(RxCounter < counter)
	{
		
		
		RxCounter++;
		
		if(RxCounter==1)
		{
			
			BcmArrayReceive.lock=LOCK;
			
		}
		else if(RxCounter>0 && RxCounter <= counter)
		{
			if(RxCounter == 2)
			{
				
				if(RxBuffer[RxCounter-1] == BcmArrayReceive.BufferId)
				{
					
					*(BcmArrayReceive.address) = BcmArrayReceive.BufferId;
					UART_Send(*(BcmArrayReceive.address));
					BcmArrayReceive.address++;
				}
				else if(RxBuffer[RxCounter-1] != BcmArrayReceive.BufferId)
				{
					lError = BCM_NOK;
				}
			}
			else if(RxCounter == 3)
			{
				if(RxBuffer[RxCounter-1] <= BcmArrayReceive.length)
				{
					*(BcmArrayReceive.address) = BcmArrayReceive.length;
					
					UART_Send(*(BcmArrayReceive.address));
					BcmArrayReceive.address ++;
					
				}
				else if(RxBuffer[RxCounter] > BcmArrayReceive.length)
				{
					lError = BCM_NOK;
				}
			}
			else if( Rx_Count < BcmArrayReceive.length )
			{
				
				*(BcmArrayReceive.address) = RxBuffer[RxCounter-1];
				BcmArrayReceive.address++;
				Rx_Count ++;
				 BcmArrayReceive.checkSum += RxBuffer[(RxCounter-1)];
				
			}
			else if(Rx_Count == (BcmArrayReceive.length))
			{ 
				if(RxBuffer[RxCounter-1] ==  BcmArrayReceive.checkSum)
				{
					
					*(BcmArrayReceive.address) = RxBuffer[RxCounter-1];
					PORTB_DATA |= 0X10;
					BcmArrayReceive.lock = UNLOCK;
					SREG &= ~(1<<7);
					lError = BCM_OK;
				}
				else if(RxBuffer[RxCounter] != BcmArrayReceive.checkSum)
				{		
					lError = BCM_NOK;
				}
				
			}
		}
	}
	
	return lError;
	#endif
}
				