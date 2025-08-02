#include "pro_header.h"

u8 kpm_lut[4][4]={{'1','2','3','A'},
									{'4','5','6','B'},
									{'7','8','9','C'},
									{'*','0','#','D'}};
void Init_kpm(void)
{
	SETBIT(IODIR1,ROW0);
	SETBIT(IODIR1,ROW1);
	SETBIT(IODIR1,ROW2);
	SETBIT(IODIR1,ROW3);
	//coumn pins by default input pins
}
u32 colscan(void)
{
	u32 t0,t1,t2,t3;
	t0=READBIT(IOPIN1,COL0);
	t1=READBIT(IOPIN1,COL1);
	t2=READBIT(IOPIN1,COL2);
	t3=READBIT(IOPIN1,COL3);
	return (t0&t1&t2&t3);
}
u32 keyscan(void)
{
	u32 rno,cno;
	while(colscan()==1);
	SCLRBIT(IOCLR1,ROW0);
	SSETBIT(IOSET1,ROW1);
	SSETBIT(IOSET1,ROW2);
	SSETBIT(IOSET1,ROW3);
	if(!colscan())
	{
		rno=0;
		goto colcheck;
	}
	SSETBIT(IOSET1,ROW0);
	SCLRBIT(IOCLR1,ROW1);
	SSETBIT(IOSET1,ROW2);
	SSETBIT(IOSET1,ROW3);
	if(!colscan())
	{
		rno=1;
		goto colcheck;
	}
	SSETBIT(IOSET1,ROW0);
	SSETBIT(IOSET1,ROW1);
	SCLRBIT(IOCLR1,ROW2);
	SSETBIT(IOSET1,ROW3);
	if(!colscan())
	{
		rno=2;
		goto colcheck;
	}
	SSETBIT(IOSET1,ROW0);
	SSETBIT(IOSET1,ROW1);
	SSETBIT(IOSET1,ROW2);
	SCLRBIT(IOCLR1,ROW3);
	if(!colscan())
	{
		rno=3;
		goto colcheck;
	}
	colcheck:
	SCLRBIT(IOCLR1,ROW0);
	SCLRBIT(IOCLR1,ROW1);
	SCLRBIT(IOCLR1,ROW2);
	SCLRBIT(IOCLR1,ROW3);
	if(READBIT(IOPIN1,COL0)==0)
		cno=0;
	else if(READBIT(IOPIN1,COL1)==0)
		cno=1;
	else if(READBIT(IOPIN1,COL2)==0)
		cno=2;
	else if(READBIT(IOPIN1,COL3)==0)
		cno=3;
	return kpm_lut[rno][cno];
}
