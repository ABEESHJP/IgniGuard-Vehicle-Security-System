#include<lpc21xx.h>	
#ifndef UART1_H
#define UART1_H						 

void UART1_INIT(void);
void UART1_TX(unsigned char);
unsigned char UART1_RX(void);
void UART1_STR(unsigned char *);

void UART1_INIT(void)
{
PINSEL0 = 0x050005;
U1LCR = 0x83;
U1DLL = 97;
U1DLM = 0;
U1LCR = 0x03;
}

void UART1_TX(unsigned char txByte)
{
while(((U1LSR >> 5)&1)==0);
U1THR = txByte;
}

unsigned char UART1_RX(void)
{
while((U1LSR & 1)==0);
return U1RBR;
}

void UART1_STR(unsigned char*s)
{
while(*s)
{
UART1_TX(*s++);
}
}
#endif


