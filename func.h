#include "stdint.h"
#include "C:/Keil/EE319KwareSpring2021/inc/tm4c123gh6pm.h"


//masks;
#define UNLOCK 0x4C4F434B
#define RED 0x02
#define UART 0xC0
#define N 2
#include <math.h>
#define pi 3.14159265358979323846
int prev_values[N];
void SystemInit();
void initialization();
void LED(double );
void Segment(int );
double deg2rad(double);
double rad2deg(double);
double distance(double , double , double , double );
void delay_1sec(void);