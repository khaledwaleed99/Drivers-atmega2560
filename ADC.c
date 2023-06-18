/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for Atmega2560 ADC Driver
 *
 * Author: Mohamed Saad
 *
 *******************************************************************************/

#include <avr/io.h>
#include "ADC.h"
#include "common_macros.h"
#include <avr/interrupt.h>


/*This Part of code is enabled only when I wanna use the adc interrupt*/
/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

//volatile uint16 g_adcResult = 0;

/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/

/*
// ISR(ADC_vect)
// {
// 	/ * Read ADC Data after conversion complete * /
// 	g_adcResult = ADC;
// }
*/

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*If I wanna use the adc interrupt I enable the ADCIE bit in the ADMUX & add the adc ISR

ISR(ADC_vect)
uint16 value=adc

*/
void ADC_init()
{
	ADMUX = (0 << MUX0);
	
	/*I have to connect the vcc and ARFF with power supply so the adc works*/
	ADMUX &= ~(1 << REFS0); // set reference voltage to Internal 2.56V Voltage Reference with external capacitor at AREF pin
	ADMUX &= ~(1 << REFS1); // clear REFS1 bit
	
	// set prescaler to 128 and enable ADC
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
	// If i enable the adc interrupt i have to set bit ADIE
}


uint16 ADC_readChannel(uint8 channel_num)
{
	/* Input channel number must be from 0 --> 15 */
	if(channel_num>=0 && channel_num <=7)
	{
		channel_num &= 0x07;
	}
	if(channel_num>=8 && channel_num <=15)
	{
		ADCSRB = (1<<MUX5);
		channel_num = channel_num-ADC_DIFF_NUM;
		channel_num &= 0x07;
	}
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC);/* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it  */
	return ADC; /* Read the digital value from the data register */
	
	/*If I'm using the adc interrupt this function is gonna be void as the interrupt will read the value and i have to remove from the code
		while(BIT_IS_CLEAR(ADCSRA,ADIF));
		SET_BIT(ADCSRA,ADIF);
		return ADC; 
	*/
}
