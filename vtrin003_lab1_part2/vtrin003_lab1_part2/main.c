/*
 * vtrin003_lab1_part2.c
 *
 * Created: 4/3/2019 6:20:20 PM
 * Author : User
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //setting inputs and outputs 
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char spot1 = 0x00;
	unsigned char spot2 = 0x00;
	unsigned char spot3 = 0x00;
	unsigned char spot4 = 0x00;
	unsigned char cntavail = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		spot1 = PINA & 0x01;
		spot2 = PINA & 0x02;
		spot3 = PINA & 0x04;
		spot4 = PINA & 0x08;
		
		spot2 = spot2 / 2;
		spot3 = spot3 / 4;
		spot4 = spot4 / 8;
		
		cntavail = spot1 + spot2 + spot3 + spot4;
		cntavail = 0x04 - cntavail;
		
		//we basically read in every possible spot to flag if there is a car.
		//if there is a car, that specific parking spot will set to 1. 
		//will need to shift everything down to the lowest bit possible, filling from 1st->4th
		//after shifting everything down & simplifying, 
		PORTC = cntavail;
    }
	return 0;
}

