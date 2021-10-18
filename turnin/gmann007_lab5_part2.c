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

enum States { Start, Init, Wait, Dec, Inc, Reset } state;
unsigned char count = 0x00;

void Tick() {
	switch (state) {
	case Start: {
		state = Init;
		break;
	}

	case Init:
		if ((~PINA & 0x03) == 0x01) {
			state = Inc; break;
		}
		else if ((PINA & 0x03) == 0x02) {
			state = Dec; break;
		}
		else if ((PINA & 0x03) == 0x03) {
			state = Reset; break;
		}
		else {
			state = Init; break;
		}
		break;
	case Wait:
		if (((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) {
			state = Wait; break;
		}
		else if ((PINA & 0x03) == 0x03) {
			state = Reset; break;
		}
		else {
			state = Init; break;
		}

	case Inc:
		state = Wait;
		break;

	case Dec:
		state = Wait;
		break;


	case Reset:
		if (((PINA & 0x03) == 0x01) && ((PINA & 0x03) == 0x02)) {
			state = Reset; break;
		}
		else if ((PINA & 0x03) == 0x00) {
			state = Init; break;
		}

	default:
		break;
	}
	switch (state) {
	case Start: {
		PORTC = 0x00;
		count = 0x00;
		
	}
			break;
			  
	case Wait:
	case Init:
		break;

	case Inc: {
		if (PORTC >= 0x09) {
			count = 0x09; PORTC = count; break;
		}
		else {
			++count; PORTC = count; break;
		}
	}
			break;

	case Dec: {
		if (PORTC <= 0x00) {
			count = 0x00;PORTC = 0x00; break;
		}
		else {
			--count; PORTC = count; break;
		}
	}
			break;



	case Reset: {
		PORTC = 0x00; count = 0x00; break;
	}
	}
}
int main(void) {
	/* Insert DDR and PORT initializations */
	/* Insert your solution below */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	state = Start;
	while (1) {
		Tick();
	}
	
}
