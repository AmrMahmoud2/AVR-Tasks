/*
 * nnnn.c
 *
 * Created: 15/02/2018 11:07:44 ã
 *  Author: Amr
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
#define KeypadDirectionRegister DDRA
#define  KeypadControl PORTA
#define KeypadVal PINA 

#define LEDDirectionRegister DDRB
#define LEDPort PORTB





void keypadScan()
{
	if(PINA == 0xf0) return;
	
	_delay_ms(50);
	
	uint8_t keypressedCode=PINA;
	DDRA ^= 0xff;
	PORTA ^= 0xff;
	asm volatile("nop");
	asm volatile("nop");
	keypressedCode |=PINA;
	
	uint8_t blinkDuration=0;
	if(keypressedCode == 0b11101110)blinkDuration=1;
	if(keypressedCode == 0b11011110)blinkDuration=2;
	if(keypressedCode == 0b10111110)blinkDuration=3;
	if(keypressedCode == 0b01111110)blinkDuration=4;
	if(keypressedCode == 0b11101101)blinkDuration=5;
	if(keypressedCode == 0b11011101)blinkDuration=6;
	if(keypressedCode == 0b10111101)blinkDuration=7;
	if(keypressedCode == 0b01111101)blinkDuration=8;
	if(keypressedCode == 0b11101011)blinkDuration=9;
	if(keypressedCode == 0b11011011)blinkDuration=10;
	if(keypressedCode == 0b10111011)blinkDuration=11;
	if(keypressedCode == 0b01111011)blinkDuration=12;
	if(keypressedCode == 0b11100111)blinkDuration=13;
	if(keypressedCode == 0b11010111)blinkDuration=14;
	if(keypressedCode == 0b10110111)blinkDuration=15;
	if(keypressedCode == 0b01110111)blinkDuration=16;
	
	if(keypressedCode < 0xff)
	{
		for(int i=0; i < blinkDuration; i++)
		{
			_delay_ms(100);
			PORTB ^= 1<<PINB0;
			_delay_ms(100);
			PORTB ^= 1<<PINB0;
		}
	}
}
int main() 
{
	
	DDRB=0b00000001;
	PORTB =0x01;
	DDRA=0x0f;//for keypad and DDRD was used instead of DDRA
	PORTA=0xf0;
	while(1)
	{
		keypadScan();
	}
	return 0;
}







