#include<lpc21xx.h>
#include "uart1.h"
void GSM(void);

void GSM(void)
{
UART1_STR("AT\r\n");
delay_milliseconds(1000);

UART1_STR("AT+CMGF=1\r\n");
delay_milliseconds(1000);

UART1_STR("AT+CMGS=\"+916379833789\"\r\n");
delay_milliseconds(1000);

UART1_STR("Unauthorized RFID Card Detected");
UART1_TX(0x1A);
delay_milliseconds(1000);
}







 