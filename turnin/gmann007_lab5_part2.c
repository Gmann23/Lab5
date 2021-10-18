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

enum States {Start,Begin, Wait,Dec, Inc, Reset, On, Off, } state;
void Tick() {
	switch(state) {
		case Start:
			state = Begin;
			break;
		case Begin:
			state = Wait;
			break;
		case Wait:
			if ((PINA == 0x03) {
                                state = Reset;
                        }
			else if ((PINA == 0x01) {
				state = On;
			}
			else if ((PINA == 0x02) {
                                state = Off;
                        }
			break;

                  case Dec:
                        if ((PINA & 0x03) == 0x02) {
                                state = Dec;
                        }
                        else {
                                state = Wait;
                        }
                        break;

                case Inc:
                        if ((PINA & 0x03) == 0x01) {
                                state = Inc;
                        }
                        else {
                                state = Wait;
                        }
                        break;




		case Reset:
			if ((PINA == 0x03) {
				state = Reset;
			}
			else {
				state = Wait;
			}
			break;
		case On:
			state = Inc;
			break;

		case Off:
			state = Dec;
			break;

		default:
			state = Start;
			break;
	}
	switch(state) {
		case Start:
			PORTC = 0x07;
			break;
		case Begin:
			PORTC = 0x07;
			break;
		case Wait:
		case Inc:
		case Dec:
			break;
		case Reset:
                        PORTC = 0x00;
                        break;

		case On:
			if (PORTC < 0x09) {
                        	PORTC = PORTC + 1;
			}
                        break;
		case Off:
			if (PORTC > 0x00) {
                        	PORTC = PORTC - 1;
			}
                        break;
		default:
			PORTC = 0x07;
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
    /* Insert your solution below */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    while (1) {
	Tick();
    }
    return 1;
}
