#include "SPI.h"

#define DD_MISO    PB3

#define DD_MOSI    PB2

#define DD_SCK     PB1

#define DD_SS      PB0

#define DDR_SPI    DDRB

void SPI_Init(SPIMode_type mode)
{
	if (mode==MASTER)
	{
		// Set MOSI and SCK output, all others input
		DDR_SPI |= (1<<DD_MOSI)|(1<<DD_SCK) |(1<<DD_SS);
		//enable master
		SET_BIT(SPCR,MSTR);
		//set clock rate f/16
		SPCR |= (1<<SPR0);     
		/*    spr1                 spr0
		        0                    0                         f/4
				0                    1                         f/16
				1                    0                         f/64
				1                    1                         f/128
		*/
	}
	else
	{
		 // Set MISO output, all others input
		 DDR_SPI |= (1<<DD_MISO);
		CLEAR_BIT(SPCR,MSTR);
	}
	
	// SPI ENABLE
	SET_BIT(SPCR,SPE);
	
}


uint8 SPI_SendReceive(uint8 data)
{
	SPDR=data;
	//while(!(SPSR & (1<<SPIF)));
	while(!READ_Bit(SPSR,SPIF));
	return SPDR;
}


uint8 SPI_ReceivePerodic(uint8*pdata)
{
	if (READ_Bit(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}

void SPI_SendNoBlock(uint8 data)
{
	SPDR=data;
}
uint8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}

void SPI_InterruptEnable(void)
{
	SET_BIT(SPCR,SPIE);
}


