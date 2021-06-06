#include<stdint.h>
#include"tm4c123gh6pm.h"

void segment(int d){
	int digit[3],number,i,j;
	GPIO_PORTD_DATA_R =(GPIO_PORTD_DATA_R & 0x00) | (GPIO_PORTD_DATA_R | 0x70);
		i=0;
		if(d>100)
			{
	
			number=d;
			while(i<3)
				{
				digit[i]=number%10;
				number=number/10;
				i++;
	    	}
			}
for(i=0;i<3;i++)
	{

		GPIO_PORTA_DATA_R=(GPIO_PORTA_DATA_R & 0X0F) | (1<<(4+i));

                GPIO_PORTD_DATA_R=(GPIO_PORTD_DATA_R & 0XF0) | (digit[i]&0x0F);
//for delay
		for(j=0;j<100;j++){}
  }
}

