/*
 * vtrin003_lab1_part1.c
 *
 * Created: 4/3/2019 4:17:44 PM
 * Author : User
 */ 
#include <avr/io.h>
int main(void){
	
	DDRA = 0x00; PORTA = 0xFF; //A will always be input, set it to 1
	DDRB = 0xFF; PORTB = 0x00; //B will always be output, set it to 0
	
	unsigned char tempPA1 = 0x00; //temp value to hold from the truth table, pin at bit 1
	unsigned char tempPA0 = 0x00; //temp value to hold from the truth table, pin at bit 0
	
	while(1){
		tempPA0 = PINA & 0x01; //basically reading in PINA to set the bit to 1
		tempPA1 = PINA & 0x02; //reading in PINA to set bit at spot 1 to 1
		
		if((tempPA0 == 0x01) && (tempPA1 == 0x00)){
			PORTB = 0x01; //if bit0 = 1 an theres no bit at bit1, output a 1
		}
		
		else{
			PORTB = 0x00; //else output a 0
		}
		
	}
	
	return 0;
}




