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
	
		prevA=lat;
		prevB=lg;
		flag=1;}
	else if(flag==1){
		A=lat;
		B=lg;
	d=distance(prevA,prevB,A,B)}
		if(d==-1){
		skip;}
		else { 
		      LED(d);
		      Segment(d);}
		if(d>100){
		break;}
}
	}
