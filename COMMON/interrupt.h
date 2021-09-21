/*
 * interrupt.h
 *
 *  Created on: Oct 26, 2019
 *      Author: AVE-LAP-025
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#  define __INTR_ATTRS used, externally_visible
#define _VECTOR(N) __vector_ ## N


#define INT0_vect			     _VECTOR(1)
#define SIG_INTERRUPT0		     _VECTOR(1)


#define INT1_vect			     _VECTOR(2)
#define SIG_INTERRUPT1			 _VECTOR(2)


#define INT2_vect			     _VECTOR(3)
#define SIG_INTERRUPT2			 _VECTOR(3)


#define TIMER2_COMP_vect		 _VECTOR(4)
#define SIG_OUTPUT_COMPARE2		 _VECTOR(4)


#define TIMER2_OVF_vect			 _VECTOR(5)
#define SIG_OVERFLOW2			 _VECTOR(5)

#define TIMER1_CAPT_vect		 _VECTOR(6)
#define SIG_INPUT_CAPTURE1		 _VECTOR(6)

#define TIMER1_COMPA_vect		 _VECTOR(7)
#define SIG_OUTPUT_COMPARE1A	 _VECTOR(7)

#define TIMER1_COMPB_vect		 _VECTOR(8)
#define SIG_OUTPUT_COMPARE1B	 _VECTOR(8)

#define TIMER1_OVF_vect			 _VECTOR(9)
#define SIG_OVERFLOW1			 _VECTOR(9)


#define TIMER0_COMP_vect		_VECTOR(10)
#define SIG_OUTPUT_COMPARE0		_VECTOR(10)


#define TIMER0_OVF_vect			_VECTOR(11)
#define SIG_OVERFLOW0			_VECTOR(11)


#define SPI_STC_vect			_VECTOR(12)
#define SIG_SPI				    _VECTOR(12)


#define USART_RXC_vect			_VECTOR(13)
#define SIG_USART_RECV			_VECTOR(13)
#define SIG_UART_RECV			_VECTOR(13)

#define USART_UDRE_vect			_VECTOR(14)
#define SIG_USART_DATA			_VECTOR(14)
#define SIG_UART_DATA			_VECTOR(14)


#define USART_TXC_vect			_VECTOR(15)
#define SIG_USART_TRANS			_VECTOR(15)
#define SIG_UART_TRANS			_VECTOR(15)


#define ADC_vect			    _VECTOR(16)
#define SIG_ADC				    _VECTOR(16)


#define EE_RDY_vect			    _VECTOR(17)
#define SIG_EEPROM_READY		_VECTOR(17)


#define ANA_COMP_vect			_VECTOR(18)
#define SIG_COMPARATOR			_VECTOR(18)


#define TWI_vect			    _VECTOR(19)
#define SIG_2WIRE_SERIAL		_VECTOR(19)


#define SPM_RDY_vect			_VECTOR(20)
#define SIG_SPM_READY			_VECTOR(20)




#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)




#endif



