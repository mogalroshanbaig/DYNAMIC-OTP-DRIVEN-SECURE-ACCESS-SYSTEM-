#ifndef __I2C_H__
#define __I2C_H__

#include "pro_header.h"

void init_i2c(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
void i2c_write(u8);
u8 i2c_read(void);
u8 i2c_ack(void);
u8 i2c_nack(void);
u8 i2c_masterack(void);

void i2c_eeprom_page_write(u8 slaveAddr,u16 wBuffStartAddr,u8 *p,u8 nBytes);
void i2c_eeprom_seq_read(u8 slaveAddr,u16 rBuffStartAddr,u8 *p,u8 nBytes);


#endif
