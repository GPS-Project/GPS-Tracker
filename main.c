#include "stdint.h"
#include "C:/Users/ub/Desktop/project/tm4c123gh6pm.h"
#define RED 0x02

void SystemInit(){}
void initialise(void)
{

SYSCTL_RCGCGPIO_R |= 0x20;

while((SYSCTL_PRGPIO_R &0x20) ==0){}; //for delay
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R = 0x02;

GPIO_PORTF_DIR_R |= 0X02;
GPIO_PORTF_AFSEL_R = 0;
GPIO_PORTF_AMSEL_R = 0;
GPIO_PORTF_DEN_R = 0x02;
GPIO_PORTF_PUR_R = 0;
GPIO_PORTF_PCTL_R=0;
}

double distance()
{
	return 101;
}

void LED(double d)
{
	if(d>100)
	{
		GPIO_PORTF_DATA_R |= RED;
	}
	else
	{
		GPIO_PORTF_DATA_R=0;
	}
}

double d;
int main()
{
initialise();
d=distance();
LED(d);
}