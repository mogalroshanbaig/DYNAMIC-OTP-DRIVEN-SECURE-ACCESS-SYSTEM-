#include "pro_header.h"

u8 eeprom_password[5];
u16 user_Password,int_conv;
extern u16 otp;
int main()
{
	u8 s[5]="1111",num[]="7993152176";
	u8 min_st,sec_st,min_en,sec_en;
  	Init_kpm();
	InitUART0();
	Init_LCD();
	init_i2c();
	rtc_init();
	Enable_EINT0();
	GSM_init();
    i2c_eeprom_page_write(I2C_EEPROM_SA,0x0000,s,4);
	i2c_eeprom_seq_read(I2C_EEPROM_SA,0x0000, eeprom_password,4);
  //cmdLCD(0X01);
 // strLCD((s8 *)eeprom_password);
	//int_conv=atoi((const char *)eeprom_password);
  delay_ms(500);
	while(1)
	{
			int_conv=0;
			int_conv=atoi((const char *)eeprom_password);
		if(checkpass(0))
		{	
			cmdLCD(CLRLCD);
			strLCD("generating otp");
			delay_ms(2000);
			srand(SEC);
			otp=1000+rand()%9000;
send:	if(send_otp(num,my_itoa(otp))==0)
			{
				while(keyscan()!='A');
				goto send;
			} 
			else
			{	
				//send_otp(num);
				min_st=MIN;
				sec_st=SEC;
				user_Password=0;
				strLCD("Enter the otp");
				if(checkpass(1))
				{	
					cmdLCD(CLRLCD);
					min_en=MIN;
					sec_en=SEC;
					if( (min_en-min_st)<2)
					{
						motor();
					}
					else if((min_en-min_st)==2)
					{
					  if(sec_en<sec_st)
					  {
							motor();
					  }
					  else{
							strLCD("ran out of time");
							delay_ms(100);
						}
						   
					}
					else
					{
						strLCD("ran out of time");
						delay_ms(100);
					}
				}
			}
		}
	}
}

