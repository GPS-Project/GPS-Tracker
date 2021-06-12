#include"func.h"
int flag=0;

int main() {
int d;
initialization();
UART0_Init();
UART1_Init();
while (1)
{
	delay_1sec();
	UART0_write(UART1_read());
	gps(UART0_DR_R);
	if(flag==0){
	
		*prev1=lat;
		*prev2=lg;
		flag=1;}
	else if(flag==1){
	d=distance(*prev1,*prev2,(double)lat,(double)lg)}
		if(d==-1){
		skip;}
		else { led(d);
		      segment(d);}
		if(d>100){
		break;}
}
	}
