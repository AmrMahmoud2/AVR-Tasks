/*
 * GccApplication1.c
 *
 * Created: 24-Nov-17 2:16:42 PM
 * Author : Amr
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000 unsigned long



int main()
{
    DDRA=0b00000001;
	while (1)
	{
		PORTA=0b00000001;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
	}
	return 0;
}


