 /******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: Timer0.c
 *
 * Description: Source file for the atmega2560 Timer0  driver
 *
 *
 *******************************************************************************/
#include "Timer0.h"

/* Description :
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter = 0 so 0 --> 255 (256ms per overflow)
 */
void Timer0_Delay(void)
{
	
	TCNT0 = 0; //Set Timer0 initial value to 0
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	
	TCCR0B = (1<<FOC0A) | (1<<CS00) | (1<<CS02);
	while(!(TIFR0 & (1<<TOV0))); // Wait until the Timer0 Overflow occurs (wait until TOV0 = 1)
	
	TIFR0 |= (1<<TOV0); // Clear TOV0 bit by set its value
	TCCR0B = 0; // Stop Timer0 by clear the Clock bits (CS00, CS01 and CS02)
}

void Timer0_Init_Normal_Mode(void)
{
	
	/*ISR(TIMER0_OVF_vect)
	*
	* While using the interrupt bit 7 in the SREG must be enabled in the main function
	*/
	TCNT0 = 0; //Set Timer0 initial value to 0
	TIMSK0 |= (1<<TOIE0); //Enable the timer0 interrupt
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	
	TCCR0B = (1<<FOC0A) | (1<<CS00) | (1<<CS02);
}

/* Description:
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so we just need 250 counts to get 250ms every compare match.
 * put initial timer counter=0 and output compare register=249 0 --> 250 (250ms per compare match)
 * so we need timer to make 2 compare matches to get a 0.5 second
 */

void Timer0_Init_CTC_Mode(unsigned char tick)
{
	
	/*There is a two different compare either CompareA or CompareB
	* Here I'm using the CompareA
	*/
	//ISR(TIMER0_COMPA_vect)
	TCNT0 = 0; //Set Timer0 initial value to 0
	OCR0A = tick; //Set the number of compare matches
	TIMSK0 |= (1<<OCIE0A); //Enable Timer0 Compare Interrupt
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0A = (1<<WGM01);
	TCCR0B = (1<<FOC0A)|(1<<CS00) | (1<<CS02);
	
}



