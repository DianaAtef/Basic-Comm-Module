/*
 * Registers.h
 *
 * Created: 11/9/2019 7:31:51 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Std_Types.h"

/*
 * General Registers
 */
#define MCUCR		(*((reg_type)0x55))
#define MCUCSR		(*((reg_type)0x54))
#define GICR		(*((reg_type)0x5B))
#define GIFR		(*((reg_type)0x5A))

/*
 * PORT registers
 */

#define PORTA_DATA 	(*((reg_type)0x3B))
#define PORTA_DIR  	(*((reg_type)0x3A))
#define PORTA_PIN	(*((reg_type)0x39))

#define PORTB_DATA 	(*((reg_type)0x38))
#define PORTB_DIR  	(*((reg_type)0x37))
#define PORTB_PIN	(*((reg_type)0x36))

#define PORTC_DATA 	(*((reg_type)0x35))
#define PORTC_DIR  	(*((reg_type)0x34))
#define PORTC_PIN	(*((reg_type)0x33))


#define PORTD_DATA 	(*((reg_type)0x32))
#define PORTD_DIR  	(*((reg_type)0x31))
#define PORTD_PIN	(*((reg_type)0x30))


/*
 * General Timer registers
 */
#define TIMSK		(*((reg_type) 0x59))
#define TIFR		(*((reg_type) 0x58))
#define SREG        (*((reg_type) 0x5F))

/*
 * Timer 0 Registers
 */

#define TCCR0		(*((reg_type) 0x53))
#define TCNT0		(*((reg_type) 0x52))
#define OCR0		(*((reg_type) 0x5C))


/*
 * Timer 1 Registers
 */

#define TCCR1A		(*((reg_type) 0x4F))
#define TCCR1B		(*((reg_type) 0x4E))
#define TCCR1		(*((volatile uint16 *) 0x4E))
#define TCNT1H		(*((reg_type) 0x4D))
#define TCNT1L		(*((reg_type) 0x4C))
#define TCNT1		(*((volatile uint16 *) 0x4C))
#define OCR1AH		(*((reg_type) 0x4B))
#define OCR1AL		(*((reg_type) 0x4A))
#define OCR1A		(*((volatile uint16 *) 0x4A))
#define OCR1BH		(*((reg_type) 0x49))
#define OCR1BL		(*((reg_type) 0x48))
#define OCR1B		(*((volatile uint16 *) 0x48))
#define ICR1H		(*((reg_type) 0x47))
#define ICR1L		(*((reg_type) 0x46))
#define ICR1		(*((volatile uint16 *) 0x46))



/*
 * Timer 2 Registers
 */

#define TCCR2		(*((reg_type) 0x45))
#define TCNT2		(*((reg_type) 0x44))
#define OCR2		(*((reg_type) 0x43))

/*
 * UART Registers
 */
#define UDR	        (*((reg_type) 0x2C))
#define UCSRA       (*((reg_type) 0x2B))
#define UCSRB       (*((reg_type) 0x2A))
#define UCSRC       (*((reg_type) 0x40))
#define UBRRL	    (*((reg_type) 0x29))
#define UBRRH       (*((reg_type) 0x40))
#define UBRR        (*((volatile uint16 *) 0x29))

/************************************************************************/
/*				 Enum for defining Timer registers                      */
/************************************************************************/

enum TCCR0_E
{
	CS00,CS01,CS02,WGM01,COM00,COM01,WGM00,FOC0
};

enum TIFR_E
{
	TOV0,OCF0,T0V1,OCF1B,OCF1A,ICF1,TOV2,OCF2
};

enum TIMSK_E
{
	TOIE0,OCIE0,TOIE1,OCIE1B,OCIE1A,TICIE1,TOIE2,OCIE2
};

enum TCCR1A_E
{
	WGM10,WGM11,FOC1B,FOC1A,COM1B0,COM1B1,COM1A0,COM1A1
};

enum TCCR1B_E
{
	CS10,CS11,CS12,WGM12,WGM13,ICES1=6,ICNC1=7
};

enum TCCR2_E
{
	CS20,CS21,CS22,WGM21,COM20,COM21,WGM20,FOC2
};

#define I 7

enum UCSRA_E
{
	MPCM,U2X,PE,DOR,FE,UDRE,TXC,RXC
};

enum UCSRB_E
{
	TXB8,RXB8,UCSZ2,TXEN,RXEN,UDRIE,TXCIE,RXCIE
};

enum UCSRC_E
{
	UCPOL,UCSZ0,UCSZ1,USBS,UPM0,UPM1,UMSEL,URSEL
};


#endif /* REGISTERS_H_ */