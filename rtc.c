#include "pro_header.h"

#define FOSC      12000000

#define CCLK  	  5*FOSC

#define PCLK  	  CCLK/4

#define PREINT_VAL ((PCLK/32768)-1)

#define PREFRAC_VAL (PCLK - ((PREINT_VAL + 1) * 32768))


void rtc_init(void)
{
  PREINT=PREINT_VAL;

  PREFRAC=PREFRAC_VAL;


  CCR=0x11; //timer started
   HOUR=10;
   MIN=40;
   SEC=00;
   }
