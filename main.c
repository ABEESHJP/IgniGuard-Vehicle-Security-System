#include<lpc21xx.h>
#include<string.h>
#include"uart0.h"
#include"uart1.h"
#include"lcd_header.h"
#include"gsm.h"

#define MOTOR1 (1<<20)
#define MOTOR2 (1<<21)

unsigned char i;
unsigned char card[13];
char valid_card[] = "060002498FC2";


int main()
{
LCD_INIT();
UART0_INIT();
UART1_INIT();
//GSM_INIT();

IODIR0 |= MOTOR1 | MOTOR2;

LCD_STR("SMART VEHICLE SCAN       RFID CARD");
delay_milliseconds(3000);

while(1)
{
LCD_COMMAND(0x01);
LCD_COMMAND(0X80);

LCD_STR("SCAN RFID");

for(i=0;i<12;i++)
{
card[i] = UART0_RX();
}

card[12] = '\0';

LCD_COMMAND(0x01);

if(strcmp((char*)card,valid_card) == 0)
{
LCD_COMMAND(0X01);
LCD_COMMAND(0x80);
LCD_STR("Access Granded");

LCD_COMMAND(0xc0);
LCD_STR("Engine Started");  

IOSET0 = MOTOR1;
IOCLR0 = MOTOR2;
delay_milliseconds(3000);

}
else
{
LCD_COMMAND(0X01);
LCD_COMMAND(0x80);
LCD_STR("Access Denied");

LCD_COMMAND(0xc0);
LCD_STR("Invalid Card");

IOCLR0 = MOTOR1;
IOCLR0 = MOTOR2;

GSM();
delay_milliseconds(3000);
}
}
}



/*
int main()
{
unsigned char i;
unsigned char card[13];

LCD_INIT();
UART0_INIT();

while(1)	   
{

for(i=0;i<12;i++)
{
card[i] = UART0_RX();


}
card[12] = '\0';

LCD_COMMAND(0x01);
LCD_COMMAND(0x80);
LCD_STR(card);

UART0_STR(card);	//060002498FC2
UART0_TX('\r');
UART0_TX('\n');
}
}
 */

