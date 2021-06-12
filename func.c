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
    accdist += dist;
    prev_values[0]=lat2;
    prev_values[1]=lon2;	
    *prev1=lat2;
    *prev2=lon2;
	  return (accdist);
//for testing
	//return(102);
	
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
void delay_1sec(void){
       unsigned long i;   
       for(i = 0; i <= 3000000; i++ ){};
		}
void UART0_Init(void){
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
    
    UART0_CTL_R &= ~UART_CTL_UARTEN;
    //set buad rate devider
    UART0_IBRD_R = 104;
    UART0_FBRD_R = 11;
		UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART0_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);

    GPIO_PORTA_AFSEL_R |= 0x03;
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & ~0xFF) | (GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX);
    GPIO_PORTA_DEN_R |= 0x03;
}

char UART0_read(void){
    while((UART0_FR_R&0x10) == 0x10);
    return UART0_DR_R & 0xFF;
}

void UART0_write(char c){
    while((UART0_FR_R & UART_FR_TXFF) != 0);
    UART0_DR_R = c;
}

void UART1_Init(void){
    SYSCTL_RCGCUART_R |= 0x02;
    while((SYSCTL_PRUART_R & 0x02) == 0);
    SYSCTL_RCGCGPIO_R |= 0x02;
		while((SYSCTL_PRGPIO_R & 0x02) == 0);
	
	  GPIO_PORTB_CR_R |= 0x1F;
    GPIO_PORTB_AMSEL_R &= ~0x1F;
    GPIO_PORTB_AFSEL_R |= 0x03;
    GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & ~0xFF) | (GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX);
    GPIO_PORTB_DEN_R |= 0x1F;
    GPIO_PORTB_DIR_R |= 0x1E;
    GPIO_PORTB_DIR_R &= ~0x01;
    
    UART1_CTL_R &= ~UART_CTL_UARTEN;
    //set buad rate devider
    UART1_IBRD_R = 104;
    UART1_FBRD_R = 11;
	  UART1_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART1_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
}

char UART1_read(void){
    while((UART1_FR_R & 0x10) == 0x10);
    return UART1_DR_R & 0xFF;
}
