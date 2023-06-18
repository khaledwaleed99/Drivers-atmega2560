 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: Timer0_PWM.h
 *
 * Description: Header file for the AVR PWM-Timer0 driver
 *
 *
 *******************************************************************************/
#ifndef TIMER0_PWM_H_
#define TIMER0_PWM_H_

#include "std_types.h"

/*
* Digital Pins to generate PWM
* (PE3:PE5) (PH0:PH6) (PL3:PL5)	
*/

#define TIMER0_OCO_PORT PORTB_ID
#define TIMER0_OCO_PIN  PIN7_ID



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initialize the PWM module by:
 * 1. Trigger Timer0 with PWM Mode.
 * 2. Setup the PWM mode with Non-Inverting.
 * 3. Setup the precaler with F_CPU/8
 * 4. Setup the compare value based on the required input duty cycle
 * 5. Setup the direction for OC0 as output pin
 */
void PWM_Timer0_Start(unsigned char set_duty_cycle);



#endif
