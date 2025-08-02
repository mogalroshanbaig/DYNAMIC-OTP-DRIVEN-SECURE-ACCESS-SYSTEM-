#include "pro_header.h"

#define EINT0_sw_al 8

extern u16 user_Password;
extern u8 eeprom_password[5];
u8 e_flag=0;
#define I2C_EEPROM_SA  0x0050 

void eint0_isr(void) __irq
{
	e_flag=1;
 if(checkpass(2))
 {
	 if(checkpass(3))
	 {
		 
			i2c_eeprom_page_write(I2C_EEPROM_SA,0x0000,my_itoa(user_Password),4);
			delay_ms(1000);
			i2c_eeprom_seq_read(I2C_EEPROM_SA,0x0000,eeprom_password,4);
	 }
	 delay_ms(1000);
		EXTINT=1<<3;
		VICVectAddr=0;
 }
} 


void Enable_EINT0(void)
{

	//CFGPIN(PINSEL0,1,FUNC4);

	CFGPIN(PINSEL1,20,FUN4);

//	SETBIT(IODIR0,EINT0_sw_al);

	SETBIT(VICIntEnable,17);

	VICVectCntl1=0x20|17;

	VICVectAddr1=(unsigned)eint0_isr;

	

	//Enable EINT0 

	SSETBIT(EXTINT,3); //default

	

	//EINT0 as EDGE_TRIG

  SETBIT(EXTMODE,3);

	//EINT0 as REDGE

  //SETBIT(EXTPOLAR,0);	
}

