#ifndef __LCD_DEFINES_H__
#define __LCD_DEFINES_H__

#define CLRLCD 0X01
#define CUR_HOME 0X02
#define SFT_CUR_RGT 0X06
#define SFT_CUR_
#define DISP_OFF_CUR_OFF 0X08
#define DISP_ON_CUR_OFF 0X0C
#define DISP_ON_CUR_ON 0X0E
#define DISP_ON_CUR_BLK 0X0F
#define SFT_DISP_RGT 0X1C
#define SFT_DISP_LFT 0X18
#define MODE_8BIT_2LINE 0X38
#define MODE_4BIT_2LINE 0X28
#define CGRAM_START_ADDR 0X40
#define DDRAM_START_ADDR 0X80
#define GOTO_LINE1_POS0 0X80
#define GOTO_LINE2_POS0 0XC0
#define GOTO_LINE3_POS0 0X94
#define GOTO_LINE4_POS0 0XD4
#define LCD_DATA 24 //p1.24
#define LCD_RS 17
#define LCD_EN 	18
#define LCD_RW 19

#endif
