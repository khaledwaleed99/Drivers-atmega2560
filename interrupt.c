/*
 * Exercise1.c
 *
 * Created: 3/3/2014 9:45:25 PM
 * Author: Mohamed Tarek
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupt.h"

/* External INT0 Interrupt Service Routine 
ISR(INT0_vect)
{
	PORTC = PORTC ^ (1<<PC0); //Toggle value of PIN 0 in PORTC (Led Toggle)
}*/

/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD0));               // Configure INT0/PD0 as input pin
	EIMSK  |= (1<<INT0);                 // Enable external interrupt pin INT0
	EICRA |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge ( (0,0) interrupt on low level , (1,0) any edge , (0,1) falling edge)
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}
void INT1_Init(void)
{
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD1));  // Configure INT1/PD1 as input pin
	PORTD |= (1<<PD1);     // Enable the internal pull up resistor at PD3 pin
	EIMSK  |= (1<<INT1);    // Enable external interrupt pin INT1
	// Trigger INT1 with the falling edge
	EICRA |= (1<<ISC11);
	EICRA &= ~(1<<ISC10);
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
}

void INT2_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT2/PD2 as input pin
	EIMSK  |= (1<<INT2);                 // Enable external interrupt pin INT0
	EICRA |= (1<<ISC20) | (1<<ISC21);   // Trigger INT0 with the raising edge ( (0,0) interrupt on low level , (1,0) any edge , (0,1) falling edge)	          
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}
void INT3_Init(void)
{
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD3));  // Configure INT3/PD3 as input pin
	PORTD |= (1<<PD3);     // Enable the internal pull up resistor at PD3 pin
	EIMSK  |= (1<<INT3);    // Enable external interrupt pin INT1
	// Trigger INT1 with the falling edge
	EICRA |= (1<<ISC31);
	EICRA &= ~(1<<ISC30);
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
}

