#include "stdint.h"
#include "C:/Users/ub/Desktop/project/tm4c123gh6pm.h"
#define RED 0x02

void SystemInit(){}
void init(void)
{
uint32_t delay;
SYSCTL_RCGCGPIO_R |= 0x20;
delay =1; //dummy variable or while loop

GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R = 0x1F;

GPIO_PORTF_DIR_R = 0X0E;
GPIO_PORTF_AFSEL_R = 0;
GPIO_PORTF_AMSEL_R = 0;
GPIO_PORTF_DEN_R = 0x1F;
GPIO_PORTF_PUR_R = 0x11;
GPIO_PORTF_PCTL_R=0;
}

void LED(double distance)
{
	if (distance>100.0)
	{
		GPIO_PORTF_DATA_R|=RED;
	}
	else
	{
		GPIO_PORTF_DATA_R=0;
	}
}

int main()
{
init();
LED(90);
LED(101);	
}