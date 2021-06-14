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
	gps();
	if(flag==0){
	
		prevA=latitude(lat);
		prevB =longitude(lg);
		flag=1;}
	else if(flag==1){
		double A,B;
		A =latitude(lat);
		B =longitude(lg);
	d=distance(prevA,prevB,A,B);
		if(d==-1){
		continue;}
		else { 
		      LED(d);
		      Segment(d);}}
		if(d>100){
		break;}
}
	}
