 
#include "UART.h"
#define BAUDRATE 9600  

/*******************************************UART0**************************************************************/ 
void UART0_init(void)
 {
	/*baud ratio*/
	uint16_t ubrr = (F_CPU / (16 * BAUDRATE)) - 1;
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr; //9600 clock MHz
	/*  8 bit data asynchronous no parity  2 stop bit*/
	SET_BIT(UCSR0C,USBS0);         //set 0 THIS LINE FOR 1 STOP BIT (clear bit)
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);          //sets size (number of data bits in the frame)
	//SET_BIT(UCS0C,UPM0);        //sets up parity mode
	/*Enable*/
	SET_BIT(UCSR0B,RXEN0);
	SET_BIT(UCSR0B,TXEN0);
 }

   
void UART0_Send(uint8 data)
 {   
	  while(!READ_Bit(UCSR0A,UDRE0));
	  UDR0=data;  
 }
   
uint8 UART0_ReceiveData(void)
 {
	while(!READ_Bit(UCSR0A,RXC0));
	  return UDR0;
 }

void UART0_sendString(const uint8 *Str)
{
	uint8 i=0;
	while(Str[i] != '\0')
	{
		UART0_Send(Str[i]);
		i++;
	}
}
 
 void UART0_receiveString(uint8 *Str)
 {
	 uint8 i=0;
	 
	 Str[i]=UART0_ReceiveData();
	 
	 while(Str[i] != '#')
	 {
		i++;
		Str[i]=UART0_ReceiveData(); 
	 }
	 Str[i]='\0';
 }




uint8 UART0_ReceivePerodic(uint8*pdata)
 {
   if(READ_Bit(UCSR0A,RXC0))
	  {
		  *pdata=UDR0;
		  return 1;
	  }
   return 0;
 }
 

void UART0_SendNoBlock(uint8 data)
 {
	 UDR0=data;
 }

uint8 UART0_ReceiveNoBlock(void)
 {
	 return UDR0;
 }


void UART0_RX_InterruptEnable(void)
 {
	 SET_BIT(UCSR0B,RXCIE0);
 }

void UART0_RX_InterruptDisable(void)
 {
	 CLEAR_BIT(UCSR0B,RXCIE0);
 }

void UART0_TX_InterruptEnable(void)
 {
	 SET_BIT(UCSR0B,TXCIE0);
 }

void UART0_TX_InterruptDisable(void)
 {
	 CLEAR_BIT(UCSR0B,TXCIE0);
 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 /*******************************************UART1**************************************************************/
 void UART1_init(void)
 {
	 /*baud ratio*/
	 uint16_t ubrr = (F_CPU / (16 * BAUDRATE)) - 1;
	 UBRR1H = (uint8_t)(ubrr >> 8);
	 UBRR1L = (uint8_t)ubrr; //9600 clock MHz
	 /*  8 bit data asynchronous no parity  2 stop bit*/
	 SET_BIT(UCSR1C,USBS1);         //set 0 THIS LINE FOR 1 STOP BIT (clear bit)
	 UCSR1C |= (1 << UCSZ11) | (1 << UCSZ10);          //sets size (number of data bits in the frame)
	 //SET_BIT(UCS0C,UPM0);        //sets up parity mode
	 /*Enable*/
	 SET_BIT(UCSR1B,RXEN1);
	 SET_BIT(UCSR1B,TXEN1);
 }

 
 void UART1_Send(uint8 data)
 {
	 while(!READ_Bit(UCSR1A,UDRE1));
	 UDR1=data;
 }
 
 uint8 UART1_ReceiveData(void)
 {
	 while(!READ_Bit(UCSR1A,RXC1));
	 return UDR1;
 }


 uint8 UART1_ReceivePerodic(uint8*pdata)
 {
	 if(READ_Bit(UCSR1A,RXC1))
	 {
		 *pdata=UDR1;
		 return 1;
	 }
	 return 0;
 }
 

 void UART1_SendNoBlock(uint8 data)
 {
	 UDR1=data;
 }

 uint8 UART1_ReceiveNoBlock(void)
 {
	 return UDR1;
 }


 void UART1_RX_InterruptEnable(void)
 {
	 SET_BIT(UCSR1B,RXCIE1);
 }

 void UART1_RX_InterruptDisable(void)
 {
	 CLEAR_BIT(UCSR1B,RXCIE1);
 }

 void UART1_TX_InterruptEnable(void)
 {
	 SET_BIT(UCSR1B,TXCIE1);
 }

 void UART1_TX_InterruptDisable(void)
 {
	 CLEAR_BIT(UCSR1B,TXCIE1);
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*******************************************UART2**************************************************************/
void UART2_init(void)
{
	/*baud ratio*/
	uint16_t ubrr = (F_CPU / (16 * BAUDRATE)) - 1;
	UBRR2H = (uint8_t)(ubrr >> 8);
	UBRR2L = (uint8_t)ubrr; //9600 clock MHz
	/*  8 bit data asynchronous no parity  2 stop bit*/
	SET_BIT(UCSR2C,USBS2);         //set 0 THIS LINE FOR 1 STOP BIT (clear bit)
	UCSR2C |= (1 << UCSZ21) | (1 << UCSZ20);          //sets size (number of data bits in the frame)
	//SET_BIT(UCS0C,UPM0);        //sets up parity mode
	/*Enable*/
	SET_BIT(UCSR2B,RXEN2);
	SET_BIT(UCSR2B,TXEN2);
}


void UART2_Send(uint8 data)
{
	while(!READ_Bit(UCSR2A,UDRE2));
	UDR2=data;
}

uint8 UART2_ReceiveData(void)
{
	while(!READ_Bit(UCSR2A,RXC2));
	return UDR2;
}


uint8 UART2_ReceivePerodic(uint8*pdata)
{
	if(READ_Bit(UCSR2A,RXC2))
	{
		*pdata=UDR2;
		return 1;
	}
	return 0;
}


void UART2_SendNoBlock(uint8 data)
{
	UDR2=data;
}

uint8 UART2_ReceiveNoBlock(void)
{
	return UDR2;
}


void UART2_RX_InterruptEnable(void)
{
	SET_BIT(UCSR2B,RXCIE2);
}

void UART2_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSR2B,RXCIE2);
}

void UART2_TX_InterruptEnable(void)
{
	SET_BIT(UCSR2B,TXCIE2);
}

void UART2_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSR2B,TXCIE2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

/*******************************************UART3**************************************************************/
void UART3_init(void)
{
	/*baud ratio*/
	uint16_t ubrr = (F_CPU / (16 * BAUDRATE)) - 1;
	UBRR3H = (uint8_t)(ubrr >> 8);
	UBRR3L = (uint8_t)ubrr; //9600 clock MHz
	/*  8 bit data asynchronous no parity  2 stop bit*/
	SET_BIT(UCSR3C,USBS3);         //set 0 THIS LINE FOR 1 STOP BIT (clear bit)
	UCSR3C |= (1 << UCSZ31) | (1 << UCSZ30);          //sets size (number of data bits in the frame)
	//SET_BIT(UCS0C,UPM0);        //sets up parity mode
	/*Enable*/
	SET_BIT(UCSR3B,RXEN3);
	SET_BIT(UCSR3B,TXEN3);
}


void UART3_Send(uint8 data)
{
	while(!READ_Bit(UCSR3A,UDRE3));
	UDR3=data;
}

uint8 UART3_ReceiveData(void)
{
	while(!READ_Bit(UCSR3A,RXC3));
	return UDR3;
}


uint8 UART3_ReceivePerodic(uint8*pdata)
{
	if(READ_Bit(UCSR3A,RXC3))
	{
		*pdata=UDR3;
		return 1;
	}
	return 0;
}


void UART3_SendNoBlock(uint8 data)
{
	UDR3=data;
}

uint8 UART3_ReceiveNoBlock(void)
{
	return UDR3;
}


void UART3_RX_InterruptEnable(void)
{
	SET_BIT(UCSR3B,RXCIE3);
}

void UART3_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSR3B,RXCIE3);
}

void UART3_TX_InterruptEnable(void)
{
	SET_BIT(UCSR3B,TXCIE3);
}

void UART3_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSR3B,TXCIE3);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////