#include<lpc21xx.h>							 

void UART0_INIT(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_STR(unsigned char *);

void UART0_INIT(void)
{
PINSEL0 = 0x050005;
U0LCR = 0x83;
U0DLL = 97;
U0DLM = 0;
U0LCR = 0x03;
}

void UART0_TX(unsigned char txByte)
{
while(((U0LSR >> 5)&1)==0);
U0THR = txByte;
}

unsigned char UART0_RX(void)
{
while((U0LSR & 1)==0);
return U0RBR;
}

void UART0_STR(unsigned char*s)
{
while(*s)
{
UART0_TX(*s++);
}
}


