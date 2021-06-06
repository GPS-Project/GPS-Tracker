#include "stdint.h"
#include "C:/Users/El.Takwa/Desktop/proj/tm4c123gh6pm.h"
//masks:
#define UNLOCK 0x4C4F434B
#define RED 0x02
#define UART 0x03
void SystemInit(){}
/*led-->PF1
	     UART-->PA0&PA1
	     7-segments-->PB */
	void initialization()
	{
		//SETTING CLK FOR A,F,D*
		SYSCTL_RCGCGPIO_R |=0x29;
		while ((SYSCTL_PRGPIO_R &0x29)==0){};
		//*LED**
			GPIO_PORTF_LOCK_R = UNLOCK;
			GPIO_PORTF_CR_R  |= RED; 
			GPIO_PORTF_AMSEL_R&=(~RED);
			GPIO_PORTF_AFSEL_R &=(~RED);
			GPIO_PORTF_DEN_R |= RED; 
			GPIO_PORTF_PCTL_R = 0x0; //generalpurpose
			GPIO_PORTF_DIR_R|= RED;
			GPIO_PORTF_DATA_R&=(~RED);
			//*7-SEGMENTS*
			GPIO_PORTD_LOCK_R|= UNLOCK;
			GPIO_PORTD_CR_R  |=0xFF;
			GPIO_PORTD_AMSEL_R =0x00;
			GPIO_PORTD_AFSEL_R =0x00;
			GPIO_PORTD_PCTL_R =0x00;
			GPIO_PORTD_DEN_R |=0xFF;
			GPIO_PORTD_DIR_R|=0xFF;
			GPIO_PORTD_DATA_R=0x00;	

			GPIO_PORTA_LOCK_R|= UNLOCK;
			GPIO_PORTA_CR_R  |=0xFF;
			GPIO_PORTA_AMSEL_R =0x00;
			GPIO_PORTA_AFSEL_R =0x00;
			GPIO_PORTA_PCTL_R =0x00;
			GPIO_PORTA_DEN_R |=0xFF;
			GPIO_PORTA_DIR_R|=0xFF;
			GPIO_PORTA_DATA_R=0x70;	

	}
