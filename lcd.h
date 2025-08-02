#ifndef __LCD_H__
#define __LCD_H__

#include "pro_header.h"

void Init_LCD(void);
void cmdLCD(u8);
void writeLCD(u8);
void charLCD(u8);
void strLCD(s8 *);
void u32LCD(u32);
void s32LCD(s32);
void f32LCD(f32,u8);
void binLCD(u32);
void hexLCD(u32);
void octLCD(u32);

#endif
