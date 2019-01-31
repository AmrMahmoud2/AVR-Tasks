/*
 * GccApplication1.c
 *
 * Created: 01-Dec-17 10:36:25 AM
 * Author : Amr
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000 unsigned long



int main()
{
	DDRA=0b00000001;
	while (1)
	{int x=1;
	for (int i=0; i<5; i++)
	{

		PORTA=0b00000001;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
		PORTA=0b00000010;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
		PORTA=0b00000100;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
	}
	return 0;
}


