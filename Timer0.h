 /******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: Timer0.h
 *
 * Description: Header file for the AVR Timer0 driver
 *
 *
 *******************************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/io.h>

/* Description :
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter = 0 so 0 --> 255 (256ms per overflow)
 */

void Timer0_Delay(void);

/* Description : 
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter = 0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second 
 * This function is to enable the Timer0 Interrupt
 */
void Timer0_Init_Normal_Mode(void);

/* Description:
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so we just need 250 counts to get 250ms every compare match.
 * put initial timer counter=0 and output compare register=249 0 --> 250 (250ms per compare match)
 * so we need timer to make 2 compare matches to get a 0.5 second
 */

void Timer0_Init_CTC_Mode(unsigned char tick);



#endif /* TIMER0_H_ */
