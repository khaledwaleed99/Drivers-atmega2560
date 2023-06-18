 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 *
 *******************************************************************************/

#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
#include "MemMap.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		
		if(port_num == PORTA_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA_REG,pin_num);
			}
		}
		else if(port_num == PORTB_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB_REG,pin_num);
			}
		}
		else if(port_num == PORTC_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC_REG,pin_num);
			}
		}
		else if(port_num == PORTD_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD_REG,pin_num);
			}
		}
		else if(port_num == PORTE_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRE_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRE_REG,pin_num);
			}
		}
		else if(port_num == PORTF_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRF_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRF_REG,pin_num);
			}
		}
		else if(port_num == PORTG_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRG_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRG_REG,pin_num);
			}
		}
		else if(port_num == PORTH_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRH_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRH_REG,pin_num);
			}
		}
		else if(port_num == PORTJ_ID)
		{	
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRJ_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRJ_REG,pin_num);
			}
		}
		else if(port_num == PORTK_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRK_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRK_REG,pin_num);
			}
		}
		else if(port_num == PORTL_ID)
		{
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRL_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRL_REG,pin_num);
			}
		}
		else
		{
			/*Do Nothing*/
		}			
		
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		
		if(port_num == PORTA_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA_REG,pin_num);
			}
		}
			
		else if(port_num == PORTB_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB_REG,pin_num);
			}
		}
		
		else if(port_num == PORTC_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC_REG,pin_num);
			}
		}
		else if(port_num == PORTD_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD_REG,pin_num);
			}
		}
		else if(port_num == PORTE_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTE_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTE_REG,pin_num);
			}
		}
		else if(port_num == PORTF_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTF_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTF_REG,pin_num);
			}
		}
		else if(port_num == PORTG_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTG_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTG_REG,pin_num);
			}
		}	
		else if(port_num == PORTH_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTH_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTH_REG,pin_num);
			}
		}	
		else if(port_num == PORTJ_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTJ_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTL_REG,pin_num);
			}
		}	
		else if(port_num == PORTK_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTK_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTK_REG,pin_num);
			}
		}	
		else if( port_num == PORTL_ID)
		{
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTL_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTL_REG,pin_num);
			}
		}
		else
		{
			/*Do Nothing*/
		}
		
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		
		if( port_num == PORTA_ID)
		{
			if(BIT_IS_SET(PINA_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTB_ID)
		{
			if(BIT_IS_SET(PINB_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTC_ID)
		{
			if(BIT_IS_SET(PINC_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTD_ID)
		{
			if(BIT_IS_SET(PIND_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTE_ID)
		{
			if(BIT_IS_SET(PINE_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTF_ID)
		{
			if(BIT_IS_SET(PINF_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTG_ID)
		{
			if(BIT_IS_SET(PING_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTH_ID)
		{
			if(BIT_IS_SET(PINH_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTJ_ID)
		{
			if(BIT_IS_SET(PINJ_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTK_ID)
		{
			if(BIT_IS_SET(PINK_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
		else if(port_num == PORTL_ID)
		{
			if(BIT_IS_SET(PINL_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
		}
	}
	

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		if(port_num == PORTA_ID)
		{
			DDRA_REG = direction;
		}
		else if(port_num == PORTB_ID)
		{
			DDRB_REG = direction;
		}
		else if(port_num == PORTC_ID)
		{
			DDRC_REG = direction;
		}
		else if(port_num == PORTD_ID)
		{
			DDRD_REG = direction;
		}
		else if(port_num == PORTE_ID)
		{
			DDRE_REG = direction;
		}
		else if(port_num == PORTF_ID)
		{
			DDRF_REG = direction;
		}
		else if(port_num==PORTG_ID)
		{
			DDRG_REG = direction;
		}
		else if(port_num == PORTH_ID)
		{
			DDRH_REG = direction;
		}
		else if(port_num == PORTJ_ID)
		{
			DDRJ_REG = direction;
		}
		else if(port_num == PORTK_ID)
		{
			DDRK_REG = direction;
		}
		else if(port_num == PORTL_ID)
		{
			DDRL_REG = direction;
		}
		else
		{
			/*Do nothing*/
		}
		
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		if(port_num == PORTA_ID)
		{
			PORTA_REG = value;
		}
		else if(port_num == PORTB_ID)
		{
			PORTB_REG = value;
		}
		else if(port_num == PORTC_ID)
		{
			PORTC_REG = value;
		}
		else if(port_num == PORTD_ID)
		{
			PORTD_REG = value;
		}
		else if(port_num == PORTE_ID)
		{
			PORTE_REG = value;
		}
		else if(port_num == PORTF_ID)
		{
			PORTF_REG = value;
		}
		else if(port_num == PORTG_ID)
		{
			PORTG_REG = value;
		}
		else if(port_num == PORTH_ID)
		{
			PORTH_REG = value;
		}
		else if(port_num == PORTJ_ID)
		{
			PORTJ_REG = value;
		}
		else if(port_num == PORTK_ID)
		{
			PORTK_REG = value;
		}
		else if(port_num == PORTL_ID)
		{
			PORTL_REG = value;
		}
		else
		{
			/*Do nothing*/
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		
		if(port_num == PORTA_ID)
		{
			value = PINA_REG;
		}
		else if(port_num == PORTB_ID)
		{
			value = PINB_REG;
		}
		else if(port_num == PORTC_ID)
		{
			value = PINC_REG;
		}
		else if(port_num == PORTD_ID)
		{
			value = PIND_REG;
		}
		else if(port_num == PORTE_ID)
		{
			value = PINE_REG;
		}
		else if(port_num == PORTF_ID)
		{
			value = PINF_REG;
		}
		else if(port_num == PORTG_ID)
		{
			value = PING_REG;
		}
		else if(port_num == PORTH_ID)
		{
			value = PINH_REG;
		}
		else if(port_num == PORTJ_ID)
		{
			value = PINJ_REG;
		}
		else if(port_num == PORTK_ID)
		{
			value = PINK_REG;
		}
		else if(port_num == PORTL_ID)
		{
			value = PINL_REG;
		}
		else 
		{
			/*Do nothing*/
		}
				
	}
	

	return value;
}
