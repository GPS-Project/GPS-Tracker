#include<stdint.h>
#include"tm4c123gh6pm.h"

int main(void){
	int distance=657;
	int digit[3],number,i;
	GPIO_PORTB_DATA_R =(GPIO_PORTB_DATA_R & 0x00) | (GPIO_PORTB_DATA_R | 0x70);
	while(1){
		i=0;
		if(distance>=100){
			number=distance;
			while(i<3){
				digit[i]=number%10;
				number=number/10;
				i++;
		}}
for(i=0;i<3;i++){
	GPIO_PORTB_DATA_R=(GPIO_PORTB_DATA_R & 0x00)|(digit[i]&0x0F)|(1<<(4+i));
	SysCtlDelay(10);
}}
}

