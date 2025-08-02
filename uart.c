#include "pro_header.h"

#define UART_INT_ENABLE 1  
 char buff[100]="hello",dummy;
unsigned char i=0,ch,r_flag=0;
void UART0_isr(void) __irq
{
  if((U0IIR & 0x04))
  {
		ch = U0RBR;	
		if(i<100)
			buff[i++] = ch; 
		else
		{
			buff[i] = '\0';
			//i=0;
			r_flag = 1;
		}
  }
  else
  {
      dummy=U0IIR;
  
  }
   VICVectAddr = 0;
}

void InitUART0 (void)
{  
            		
  PINSEL0 = 0x00000005; 
  U0LCR = 0x83;       
  U0DLL = 97;           
  U0LCR = 0x03;         
  
  #if UART_INT_ENABLE > 0

  VICIntSelect = 0x00000000; 
  VICVectAddr0 = (unsigned)UART0_isr;
  VICVectCntl0 = 0x20 | 6; 
  VICIntEnable = 1 << 6; 
  U0IER = 0x03;             
  #endif					
}
void UART0_Tx(char ch) 
{ 
  U0THR = ch;                
  while (!(U0LSR & 0x20));
}
char UART0_Rx(void) 
{                     
  while (!(U0LSR & 0x01));
  return (U0RBR);
}

void UART0_Str(char *s)
{
   while(*s)
       UART0_Tx(*s++);
}

void UART0_Int(unsigned int n)
{
  unsigned char a[10];
  int i=0;
  if(n==0)
  {
    UART0_Tx('0');
	return;
  }
  else
  {
     while(n>0)
	 {
	   a[i++]=(n%10)+48;
	   n=n/10;
	 }
	 --i;
	 for(;i>=0;i--)
	 {
	   UART0_Tx(a[i]);
	 }
   }
}

void UART0_Float(float f)
{
  int x;
  float temp;
  x=f;
  UART0_Int(x);
  UART0_Tx('.');
  temp=(f-x)*100;
  x=temp;
  UART0_Int(x);
}

