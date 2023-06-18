/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for Reading and writing in the eeprom
 *
 * Author: Mohamed Saad
 *
 *******************************************************************************/ 


#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include "GPIO.h"
#include "lcd.h"
#include <stdlib.h>

#define EEPROM_ADDR 0x10
#define EEPROM2_ADDR 0x20




int main(void)
{
	
	 char str[4];
	 
	LCD_init();
	uint8_t eeprom_data = 1; // data to write to EEPROM
	uint8_t read_data;

	 // variable to hold read data from EEPROM
	
	// write data to EEPROM
	eeprom_write_byte((uint8_t*)EEPROM_ADDR, eeprom_data);
	
	// read data from EEPROM
	read_data = eeprom_read_byte((uint8_t*)EEPROM_ADDR);
  
	LCD_displayString("Reading: ");
	while (1)
	{
		eeprom_data++;
		
		eeprom_write_byte((uint8_t*)EEPROM_ADDR, eeprom_data);	
		read_data = eeprom_read_byte((uint8_t*)EEPROM_ADDR);
		
		itoa(read_data, str, 10);
		LCD_moveCursor(0,8);
		LCD_displayString(str);
		LCD_moveCursor(1,8);
		LCD_intgerToString(read_data);
		
		_delay_ms(1000);
	}
   
}

