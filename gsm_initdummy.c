#include "pro_header.h"

extern char buff[100],i,ch;
u8 *gsmat[]={"AT\r\n","ATE0\r\n","AT+CMGF=1\r\n","AT+CMGS="};

u8 *gsmresp[]={"OK","ERROR"};
u16 otp;

//void my_itoa(u32 otp,u8*a);

void GSM_init(void)
{	
	u32 j=0;
	cmdLCD(0x80);
	strLCD("GSM init....");
	for(j=0;j<3;j++)
	{
		i=0;memset(buff,'\0',100);
		UART0_Str((char *)gsmat[j]);
		while(i<2);
		delay_ms(500);
		//buff[i] = '\0';
		if(strstr(buff,(const char *)gsmresp[0]))
		{		
			cmdLCD(0xC0);
			strLCD((s8 *)gsmresp[0]);
			delay_ms(500);
			cmdLCD(0xC0);
			strLCD("  ");
		}
		else
		{
			cmdLCD(0xC0);
			strLCD((s8 *)gsmresp[1]);
			delay_ms(500);
			cmdLCD(0xC0);
			strLCD("     ");
		}
	}
}

u8 send_otp(u8 *num,u8 *msg)
{
	u8 str[]="OTP IS: ";
	u8 j=0;
	cmdLCD(0x01);
	delay_ms(500);
	cmdLCD(0x01);
	for(i=8;i<12;i++)
	{
		str[i]=msg[j];
		j++;
	}
	str[i]='\0';
	strLCD("Sending otp....");
	i=0;memset(buff,'\0',100);
	//cmdLCD(0xc0);
	//strLCD((s8 *)str);
	UART0_Str((char *)gsmat[3]);
	UART0_Tx('"');
	UART0_Str((char *)num);
	UART0_Tx('"');
	UART0_Str("\r\n");
	//while(strchr(buff,'>')==0);
	delay_ms(2000);
	i=0;
	UART0_Str((char *)str);
	//UART0_Str("HELLO");
	UART0_Tx(0x1A);
	delay_ms(5000);
	while(i<3);
	buff[i]='\0';
	//cmdLCD(0x01);
	//strLCD((s8 *)buff);
	delay_ms(1000);
	if(strstr(buff,"OK"))
	{
		cmdLCD(0x01);
		strLCD("OTP Sent..");
		delay_ms(500);
		return 1;
	}
	else
	{
		cmdLCD(0x01);
		strLCD("OTP SENT failed..");
		delay_ms(500);
	}
	return 0;
}
