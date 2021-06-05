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


double deg2rad(double);
double rad2deg(double);

double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
 double theta, dist;
static double accdist=0.0;
	
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
  else {
		
		
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
		
		accdist= accdist + dist;
		
    switch(unit) {
      case 'M':
        break;
      case 'K':
        dist = dist * 1.609344;
        break;
      case 'N':
        dist = dist * 0.8684;
        break;
    }
    return (accdist);
  }
}


/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts decimal degrees to radians             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double deg) {
  return (deg * pi / 180);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts radians to decimal degrees             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double rad2deg(double rad) {
  return (rad * 180 / pi);
	
}
