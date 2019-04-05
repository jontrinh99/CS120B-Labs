/*
 * vtrin003_lab1_part4.c
 *
 * Created: 4/4/2019 6:44:33 PM
 * Author : User
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0cFF; PORTD = 0x00;
	
	unsigned short chairA = 0x00;
	unsigned short chairB = 0x00;
	unsigned short chairC = 0x00;
	unsigned short maskBit = 0x00;
	unsigned short totalVal = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		chairA = PINA;
		chairB = PINB;
		chairB = PINC;
		maskBit = 0xFE;
		
		if((chairA + chairB + chairC) > 0x7F){
			PORTD = maskBit | 0x01;
		}
		if((chairA - chairC) > 0x50){
			PORTD = (PIND & 0xFD) | 0x02;
		}
    }
	return 0;
}

