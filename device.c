#include "pro_header.h"

#define OP1  4 // P0.4
#define OP2  5 // P0.5
#define EN1_2  6 //P0.6
#define EN3_4  7 // P0.7

void motor(void)
{    
    	WRITENIBBLE(IODIR0,OP1,15);
	SETBIT(IOPIN0,EN1_2);
	cmdLCD(0x01);
	strLCD("MOTOR STARTING....");
	delay_ms(500);
	SETBIT(IOPIN0,OP2);
	CLRBIT(IOPIN0,OP1);
	delay_ms(50);
	CLRBIT(IOPIN0,OP1);
	CLRBIT(IOPIN0,OP2);
	cmdLCD(0x01);
	strLCD("MOTOR RUNNING");
	delay_ms(1000);
	cmdLCD(0X01);
	strLCD("MOTOR STOPPING..");
	delay_ms(1000);
	SETBIT(IOPIN0,OP1);
	CLRBIT(IOPIN0,OP2);
	delay_ms(50);
	CLRBIT(IOPIN0,OP1);
	CLRBIT(IOPIN0,OP2);
	cmdLCD(0x01);
	strLCD("MOTOR STOPPED");
	delay_ms(500);
}
