/*
 * vtrin003_lab1_part3.c
 *
 * Created: 4/3/2019 6:59:42 PM
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
	unsigned char tempAvailSpots = 0x00;
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
		//will need to shift everything down to the lowest bit possible, filling from 
		//after shifting everything down & simplifying,
		
		//PORTC = cntavail; for exercise 2 
		if(cntavail == 0){ 
			//if its full we want to set the last bit to 1, which means we can just max out the register 
			//8 bit reg will hold 255 bits, -127 to 128. if full, set portc to 128, or 0x80
			//if its full, cntavail will be 0. dont want to change the code, though could save a few lines
			PORTC = 0x80;
		}
		else{
			spot1 = spot1;
			spot2 = spot2 * 2;
			spot3 = spot3 * 4;
			spot4 = spot4 * 8;
			
			cntavail = spot1 + spot2 + spot3 + spot4;
			tempAvailSpots = ~cntavail;
			//inverting will give you the spots that ARENT taken up
			cntavail = tempAvailSpots & 0x0F;
			//this is a safeguard to essentially ensure that we only output bits 0-3
			//we want to clear out 4-7 because we dont want to output it
			//whole point is to invert that spots that are taken up, and then output that specifically
			PORTC = cntavail;
		}
	}
	return 0;
}

