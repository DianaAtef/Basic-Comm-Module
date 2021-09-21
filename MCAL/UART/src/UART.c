/*
 * UART.c
 *
 * Created: 11/12/2019 12:00:34 PM
 *  Author: AVE-LAP-025
 */ 
#include "UART.h"
#include "UART_Lcfg.h"
#include "Registers.h"
#include "interrupt.h"

volatile uint8 g_DataTransmit;
volatile uint8 g_DataReceive;
volatile uint8 g_flag=0;
volatile uint8 g_Txflag=0;


void(*TxCall)(void)=NULL;
void(*RxCall)(void)=NULL;

void TxSetCallBack(void (*ptr)(void))
{
	TxCall=ptr;
}

void RxSetCallBack(void (*ptr)(void))
{
	RxCall=ptr;
}
/*********************** ISR for sending data by interrupt ********************** */
/*
ISR(USART_UDRE_vect)
{
	UDR=g_DataTransmit;
	TxCall();
}
*/

ISR(USART_TXC_vect)
{
	g_Txflag++;
}


ISR(USART_RXC_vect)
{
	RxCall();

}

uint8 g_interrupt;


/********************************************************************************************/
/*				 		            Initializing UART                                       */
/*******************************************************************************************/

uint8 UART_Init(UART_Cfg_S*uart_cfg)
{
	uint16 BaudRate = uart_cfg->CPU_Clock/((16.0*uart_cfg->BaudRate))-1;
	uint8 UCSRC_Holder=(1<<URSEL);

	/*********************** check if interrupt is required to be set********************** */
	g_interrupt=uart_cfg->ReceiveInterrupt;

	if(uart_cfg->ReceiveInterrupt == INTERRUPT)
	{
		
		SET_BIT(UCSRB,RXCIE);
		SET_BIT(UCSRB,TXCIE);
		//SET_BIT(UCSRB,UDRIE);
	}

	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);


	/*********************************check parity*******************************************/

	switch(uart_cfg->ParityBit)
	{
		case UART_ParityBit_None:
		{
			CLR_BIT(UCSRC_Holder,UPM1);
			CLR_BIT(UCSRC_Holder,UPM0);
			break;
		}
		case UART_ParityBit_Odd:
		{
			SET_BIT(UCSRC_Holder,UPM1);
			SET_BIT(UCSRC_Holder,UPM0);
			break;
		}
		case UART_ParityBit_Even:
		{
			SET_BIT(UCSRC_Holder,UPM1);
			break;
		}
		default:
		{
			return E_NOT_OK;
			break;
		}

	}

	/**********************************check Number of stop bits**************************/
	switch(uart_cfg->StopBits)
	{
		case UART_StopBits_1:
		{
			CLR_BIT(UCSRC_Holder,USBS);
			break;
		}
		case UART_StopBits_2:
		{
			SET_BIT(UCSRC_Holder,USBS);
			break;
		}
		default:
		{
			return E_NOT_OK;
			break;
		}
	}
	/**********************************check Number of data bits**************************/
	switch(uart_cfg->DataBits)
	{
		case UART_DataBits_5:
		{
			CLR_BIT(UCSRC_Holder,UCSZ0);
			CLR_BIT(UCSRC_Holder,UCSZ1);
			break;
		}
		case UART_DataBits_6:
		{
			SET_BIT(UCSRC_Holder,UCSZ0);
			break;
		}
		case UART_DataBits_7:
		{
			SET_BIT(UCSRC_Holder,UCSZ1);
			break;
		}
		case UART_DataBits_8:
		{
			SET_BIT(UCSRC_Holder,UCSZ0);
			SET_BIT(UCSRC_Holder,UCSZ1);
			break;
		}
		default:
		{
			return E_NOT_OK;
			break;
		}
	}
	UCSRC=UCSRC_Holder;
	/********************************** Set BaudRate in Register **************************/
	UBRRL = BaudRate;
	UBRRH = BaudRate >> 8;
	

	return E_OK;
	}

/********************************************************************************************/
/*				 		             UART Send function                                     */
/*******************************************************************************************/

uint8 UART_Send(uint8 Data)
{
	
	
/********************************** Add data to Register *********************************/

	if(g_interrupt==POLLING)
	{
		while(READ_BIT(UCSRA,UDRE)==0);
		UDR = Data;
		return E_OK;
	}
	else
	{
			//g_DataTransmit = Data;
			UDR = Data;
			return E_OK;
	
	}
	return E_NOT_OK;
}

/********************************************************************************************/
/*				 		             UART Receive function                                 */
/*******************************************************************************************/

uint8 UART_Receive(uint8*Read_Data)
{
	if(g_interrupt==POLLING	)
	{
		while(READ_BIT(UCSRA,RXC)==0);

		*Read_Data= UDR;
		return E_OK;
	}
	else
	{

		if(g_flag>0)
		{
			*Read_Data=g_DataReceive;
			g_flag=0;
			return E_OK;
		}

	}
	return E_NOT_OK;
}
uint8 getUdrValue(void)
{
	
	return UDR;
}