#include"types.h"
#include<lpc21xx.h>
#include"defines.h"
#include"lcd.h"
#include"lcd_defines.h"
#include"delay.h"
void Init_LCD()
{
	WRITEBYTE(IODIR1,LCD_DATA,0XFF);
	SETBIT(IODIR0,LCD_RS);
	SETBIT(IODIR0,LCD_EN);
	//SETBIT(IODIR0,LCD_RW);
	delay_ms(15);
	cmdLCD(0x30);
	delay_ms(5);
	cmdLCD(0x30);
	delay_us(100);
	cmdLCD(0x30);
	cmdLCD(MODE_8BIT_2LINE);
	cmdLCD(DISP_ON_CUR_BLK);
	cmdLCD(CLRLCD);
	cmdLCD(SFT_CUR_RGT);
}


void writeLCD(u8 dat)
{
	//SCLRBIT(IOCLR0,LCD_RW);
	WRITEBYTE(IOPIN1,LCD_DATA,dat);
	SSETBIT(IOSET0,LCD_EN);
	delay_us(1);
	SCLRBIT(IOCLR0,LCD_EN);
	delay_ms(2);
}

void cmdLCD(u8 cmd)
{
	SCLRBIT(IOCLR0,LCD_RS);
	writeLCD(cmd);
}

void charLCD(u8 ascii)
{
	SSETBIT(IOSET0,LCD_RS);
	writeLCD(ascii);
}

void strLCD(s8 *p)
{
	while(*p)
	{
		charLCD(*p++);
	}
}

void u32LCD(u32 n)
{
	u8 a[10];
	s32 i=0;
	if(n==0)
	{
		charLCD('0');
	}
	else
	{
		while(n>0)
		{
			a[i++]=(n%10)+48;
			n/=10;
		}
		for(--i;i>=0;i--)
		{
			charLCD(a[i]);
		}
	}
}

void s32LCD(s32 n)
{
	if(n==0)
		charLCD('0');
	else if(n<0)
	{
		charLCD('-');
		n=-n;
		u32LCD(n);
	}
}

void f32LCD(f32 f,u8 ndp)
{
	u32 i,j;
	if(f<0.0)
	{
		charLCD('-');
		f=-f;
	}
	i=f;
	u32LCD(i);
	charLCD('.');
	for(j=0;j<ndp;j++)
	{
		f=(f-i)*10;
		i=f;
		charLCD(i+48);
	}
}

void binLCD(u32 n)
{
	s8 bit=15;
	while(bit>=0)
	{
		charLCD(((n>>bit)&1)+48);
		bit--;
	}
}

void hexLCD(u32 n)
{
	s32 i=0,nibble;
	u8 a[8];
	if(n==0)
		charLCD('0');
	else
	{
		while(n)
		{
			nibble=n%16;
			nibble=(nibble>9)?((nibble-10)+'A'):(nibble+48);
			a[i++]=nibble;
			n/=16;
		}
		for(--i;i>=0;i--)
		{
			charLCD(a[i]);
		}
	}	
}

void octLCD(u32 n)
{
	u8 a[15];
	s32 i=0,x;
	if(n==0)
		charLCD('0');
	else
	{
		while(n)
		{
			x=n%8;
			a[i++]=x+48;
			n/=8;
		}
		for(--i;i>=0;i--)
		charLCD(a[i]);
	}
}
