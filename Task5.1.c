/*
 * session 5_interrput.c
 *
 * Created: 16-Feb-18 11:48:46 AM
 * Author : Amr
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    DDRA =0x01;
	DDRB =0x01;
	DDRD &=~(1<<PD2);
	PORTD |=(1<<PD2);
	MCUCR |=(1<<ISC01);
	GICR |=(1<<INT0);
	sei ();


    while (1) 
    {
		PORTA ^=(1<<PA0);
		_delay_ms(500);
		
    }
return 0;
}
	ISR(INT0_vect)
	{
		PORTB ^=(1<<PB0);
		_delay_ms(500);
	}



