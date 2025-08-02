#ifndef __PRO_HEADER_H__
#define __PRO_HEADER_H__

#include<lpc21xx.h>
#include "types.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "rtc.h"
#include "i2c.h"
#include "delay.h"
#include<string.h>
#include<stdlib.h>
#include "uart.h"
#include "kpm.h"
#include "defines.h"
#include "ext.int.h"
#include "keypad_defines.h"

u16 password(void);
void GSM_init(void);
void activity(void);
void rtc_init(void);
u8 send_otp(u8 *,u8 *);
u8 checkpass(u8);
void motor(void);
u8 *my_itoa(u16);
void edit_pass(void);

#define I2C_EEPROM_SA  0x0050 //7Bit Slave Addr

#endif
