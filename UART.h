/*
 * UART.h
 *
 * Created: 03/14/23 12:28:01 AM
 *  Author: Seif
 */ 


#ifndef UART_H_
#define UART_H_
 #include "MemMap.h"
 #include "common_macros.h"
 #include "std_types.h"
 #include <avr/io.h>
/*********************************UART0*************************************/
void UART0_init(void);
void UART0_Send(uint8 data);//busy wait
uint8 UART0_ReceiveData(void);//busy wait
uint8 UART0_ReceivePerodic(uint8*pdata);
void UART0_sendString(const uint8 *Str);
void UART0_receiveString(uint8 *Str);

void UART0_RX_InterruptEnable(void);
void UART0_RX_InterruptDisable(void);

void UART0_TX_InterruptEnable(void);
void UART0_TX_InterruptDisable(void);

void UART0_SendNoBlock(uint8 data);
uint8 UART0_ReceiveNoBlock(void);
/////////////////////////////////////////////////////////////////////////////

/*********************************UART1*************************************/
void UART1_init(void);
void UART1_Send(uint8 data);//busy wait
uint8 UART1_ReceiveData(void);//busy wait
uint8 UART1_ReceivePerodic(uint8*pdata);

void UART1_RX_InterruptEnable(void);
void UART1_RX_InterruptDisable(void);

void UART1_TX_InterruptEnable(void);
void UART1_TX_InterruptDisable(void);

void UART1_SendNoBlock(uint8 data);
uint8 UART1_ReceiveNoBlock(void);
/////////////////////////////////////////////////////////////////////////////

/*********************************UART2*************************************/
void UART2_init(void);
void UART2_Send(uint8 data);//busy wait
uint8 UART2_ReceiveData(void);//busy wait
uint8 UART2_ReceivePerodic(uint8*pdata);

void UART2_RX_InterruptEnable(void);
void UART2_RX_InterruptDisable(void);

void UART2_TX_InterruptEnable(void);
void UART2_TX_InterruptDisable(void);

void UART2_SendNoBlock(uint8 data);
uint8 UART2_ReceiveNoBlock(void);
/////////////////////////////////////////////////////////////////////////////

/*********************************UART3*************************************/
void UART3_init(void);
void UART3_Send(uint8 data);//busy wait
uint8 UART3_ReceiveData(void);//busy wait
uint8 UART3_ReceivePerodic(uint8*pdata);

void UART3_RX_InterruptEnable(void);
void UART3_RX_InterruptDisable(void);

void UART3_TX_InterruptEnable(void);
void UART3_TX_InterruptDisable(void);

void UART3_SendNoBlock(uint8 data);
uint8 UART3_ReceiveNoBlock(void);
/////////////////////////////////////////////////////////////////////////////

#endif /* UART_H_ */