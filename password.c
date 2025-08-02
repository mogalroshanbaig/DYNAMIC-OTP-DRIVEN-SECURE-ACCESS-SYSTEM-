#include "pro_header.h"

extern  u16 user_Password,int_conv,otp;
extern u8 i,e_flag,eeprom_password[5];
u8 s[5];
/*void password(u8 digits)
{
	u8 ch;
	u8 index=0;
	cmdLCD(GOTO_LINE2_POS0);
	while(1)
	{		
		ch = keyscan();
		if(ch=='*')
		{
			if(index==0)
			continue;
			index--;
                        cmdLCD(GOTO_LINE2_POS0+index);
                        charLCD(' ');
                        cmdLCD(GOTO_LINE2_POS0+index);
		}
		else if((ch=='>')||(index==digits))
		{
			user_Password[index++]='\0';
			break;
		}
		else if(ch=='c'||ch=='r')
		{
		start:   cmdLCD(0X01);
		   strLCD("enter ur password");
		   cmdLCD(0XC0);
		   index=0;
		   continue;
		}
		else if(ch=='l')
		{
		cmdLCD(0X01);
		strLCD("already launched");
		delay_ms(1000);
		cmdLCD(0x01);
    	strLCD("enter ur password");
		cmdLCD(0xc0);
		for(ch=0;ch<index;ch++)
		{
		charLCD('*');
		}
		}
		else if(ch=='e')
		{
		while(ch!='r'&&ch!='l')
		{
		ch=keyscan();
		}
		  goto start;
		}
		else
		{
			user_Password[index++]=ch;
                        //charLCD('*');
						charLCD(ch);
                        
		}
		delay_ms(100);	
	}
}*/


u8 a[5];
u16 password(void)
{
	u16 num=0,k=0;
	u8 ch;
	cmdLCD(0xc0);
	while(1)
	{
		ch=keyscan();
		delay_ms(100);
		while(colscan()==0);
		if((ch>='0') && (ch<='9'))
		{
			a[k]=ch;
			cmdLCD(0xc0+k);
			charLCD(ch);
			delay_ms(20);
			cmdLCD(0xc0+k);
			charLCD('*');
			k++;
		}
		else if(ch=='D')
			break;
		else if(ch=='C')
		{
			cmdLCD(0xc0+k);
			charLCD(' ');
		}
		else if(ch=='A')
		{
			k++;
			cmdLCD(0xc0+k);
		}
		else if(ch=='B')
		{	
			k--;
			cmdLCD(0xc0+k);
		}
	}
	num=atoi((const char*)a);
	return num;
}

u8 checkpass(u8 n)
{
	if(n==0)
	{
		cmdLCD(0x01);
		strLCD("Enter User Pasword:");
	}
	else if(n==1)
	{
		cmdLCD(0x01);
		strLCD("Enter User OTP:");
		int_conv=0;
		int_conv=otp;
	}
	else if(n==2)
	{
		cmdLCD(0x01);
		strLCD("Enter OLD PASS:");
	}
	else if(n==3)
	{
		cmdLCD(0x01);
		strLCD("Enter New PASS:");
		user_Password=password();
		int_conv=user_Password;
		user_Password=0;
		cmdLCD(0x01);
		strLCD("Enter CNFRM PASS:");
	}
	user_Password=0;
	user_Password=password();
	cmdLCD(0x01);
	strLCD("Validating");
	for(i=0;i<9;i++)
	{
		charLCD('.');
		delay_ms(50);
	}
	i=0;
	if(user_Password==int_conv)
	{
		cmdLCD(0x01);
		strLCD("VALID");
		delay_ms(1000);
		return 1;
	}
	else
	{
		cmdLCD(0x01);
		strLCD("INVALID");
		delay_ms(1000);
	}
	return 0;
}

u8 *my_itoa(u16 a)
{
	s8 j=4;
	s[j]='\0';
	while(a)
	{
		s[--j]=(a%10)+48;
		a/=10;
	}
	return s;
}
