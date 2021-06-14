#include "C:/Users/El.Takwa/Desktop/proj/tm4c123gh6pm.h"
//#include <stdbool.h>
//#define MAX 100 //max number of characters recieved ftom gps module
unsigned char data ;
unsigned int i;
//unsigned char stringdata [MAX];
char UART0_read (void){
	while ((UART0_FR_R &0x10)!=0){
	 return UART0_DR_R&0xFF;
	}
}
/*void readmsg (){
while ((UART2_FR_R &0x10)!=0){
	 data = (UART2_DR_R&0xFF);
	if(data != '*'){
	stringdata[i]=data;}
	else
		break;
	}
}*/
	
	
	
	/*for (i=0;i<MAX;i++){
	if (data == 'G'){
		if (data =='P')
			if (data =='R')
				if (data=='M')
					if(data =='C')
					stringdata [i]=data;*/
	

