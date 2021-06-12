#include "stdint.h"
#include "C:/Keil/EE319KwareSpring2021/inc/tm4c123gh6pm.h"


//masks;
#define UNLOCK 0x4C4F434B
#define RED 0x02
#define UART 0xC0
#define N 2
#include <math.h>
#define pi 3.14159265358979323846
double*prev1;
double* prev2;
char lat[20];                      // latitude array
char lg[20];
void SystemInit();
void initialization();
void LED(double );
void Segment(int );
double deg2rad(double);
double rad2deg(double);
double distance(double , double , double , double );
void delay_1sec(void);
char UART1_read(void);
void UART1_Init(void);
void UART0_write(char c);
char UART0_read(void);
void UART0_Init(void);
void gps();
