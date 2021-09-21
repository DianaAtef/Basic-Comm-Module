/******************************************************************************
 *
 * Module: BCM Module
 *
 * File Name: Bcm.h
 *
 * Description: Header file for BCM module
 *
 * Author: Diana Atef George
 *
 *******************************************************************************/


#ifndef BCM_H_
#define BCM_H_

#include "Std_Types.h"

typedef  uint8 EnmBCMError_t;

#define LOCK   0
#define UNLOCK 1

enum
{
	BCM_OK, BCM_NOK
};

enum
{
	gTxFlagOk,gTxFlagNOk
};
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

EnmBCMError_t BCM_Init (void);


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

EnmBCMError_t BCM_Send(uint8*ptr,uint8 length);

/************************************************************************************
* Function Name: BCM_RxDispatch
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

EnmBCMError_t BCM_RxDispatch(void);


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

void BCM_TxDispatch(void);

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

EnmBCMError_t BCM_Setup_Receive(uint8 id,uint8* address,uint8 length);



#endif /* BCM_H_ */