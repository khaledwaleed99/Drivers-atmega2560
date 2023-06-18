/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: Timer0_PWM.c
 *
 * Description: Source file for the AVR PWM-Timer0 driver
 *
 * Author: Mohamed Saad
 *
 *******************************************************************************/

#include <avr/io.h>
#include "Timer0_PWM.h"




/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Initialize the PWM module by:
 * 1. Trigger Timer0 with PWM Mode.
 * 2. Setup the PWM mode with Non-Inverting.
 * 3. Setup the compare value based on the required input duty cycle
 * 4. Setup the direction for OC0 as output pin
 */
void PWM_Timer0_Start(unsigned char set_duty_cycle)
{
	
	//Fast PWM (WGM01 & WGM00)
	//Clear OC0A on Compare Match when up-counting.(COM0A1)
	TCCR0A |= (1<<WGM01)|(1<<COM0A1)|(1<<WGM00);
	//No Prescaler
	TCCR0B |= (1 << CS02) ; //Modify the prescaler CS02=1 clk/64
	OCR0A = set_duty_cycle;
	
	GPIO_setupPinDirection(TIMER0_OCO_PORT,TIMER0_OCO_PIN,PIN_OUTPUT);
	//DDRB |= (1<<7);
}