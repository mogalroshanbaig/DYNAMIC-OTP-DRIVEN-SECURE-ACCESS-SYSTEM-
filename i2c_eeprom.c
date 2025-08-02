                                    /* i2c_eeprom.c */
#include <LPC21xx.h>
#include "types.h"
#include "i2c.h"
#include "delay.h"
void i2c_eeprom_page_write(u8 slaveAddr,u16 wBuffStartAddr,u8 *p,u8 nBytes)
{
  u8 i;
  i2c_start();	
  i2c_write(slaveAddr<<1);  
	i2c_write(wBuffStartAddr>>8);
		i2c_write(wBuffStartAddr);  
	for(i=0;i<nBytes;i++)
	{
	   i2c_write(p[i]);       
	}
	i2c_stop();
	delay_ms(10);
}			 

void i2c_eeprom_seq_read(u8 slaveAddr,u16 rBuffStartAddr,u8 *p,u8 nBytes)
{
	u8 i;
	i2c_start();	
    i2c_write(slaveAddr<<1);
	i2c_write(rBuffStartAddr>>8); 
	i2c_write(rBuffStartAddr); 
	i2c_restart();	
	i2c_write(slaveAddr<<1|1);
	for(i=0;i<nBytes;i++)
	{
    p[i]=i2c_masterack();	
	}
	p[i++]=i2c_read();
	p[i]='\0';
	i2c_nack();
	i2c_stop();
}

