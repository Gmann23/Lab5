/*	Author: Gurvinder Mann
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	// DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	/* Insert your solution below */
	while (1) {
		tmpA = PINA & 0x0F;

		if ((tmpA == 0x01 || tmpA == 0x02)) {
			tmpB = 0x60;
		}
		else if (tmpA == 0x03 || tmpA == 0x04) {
			tmpB = 0x70;
		}
		else if (tmpA == 0x05 || tmpA == 0x06) {
			tmpB = 0x38;
		}
		else if (tmpA == 0x07 || tmpA == 0x08 || tmpA == 0x09) {
			tmpB = 0x3C;
		}
		else if (tmpA == 0x0A || tmpA == 0x0B || tmpA == 0x0C) {
			tmpB = 0x3E;
		}
		else if (tmpA == 0x0D || tmpA == 0x0E || tmpA == 0x0F) {
			tmpB = 0x3F;
		}
		
	
		PORTC = tmpB;


	}


	return 1;
}
