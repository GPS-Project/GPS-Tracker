#include"func.h"
void SystemInit(){}
void initialization()
	{
		        //SETTING CLK FOR A,F,B*
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

	
void LED(double d)
{
	if(d>100)
	{
		GPIO_PORTF_DATA_R |= RED;
	}
	
}
void Segment(int d)
{
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
double distance(double lat1, double lon1, double lat2, double lon2) {
double theta, dist;
static double accdist=0.0;
	
  if ((lat1 == lat2) && (lon1 == lon2)) 
    return 0;
  
  else {
		
		
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
		
	
  
        dist = (dist * 1.609344)*1000;
        //return (accdist);
//for testing
	return(102);
	
       }
}
//  This function converts decimal degrees to radians    

double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees 
double rad2deg(double rad) {
  return (rad * 180 / pi);
	
}	
