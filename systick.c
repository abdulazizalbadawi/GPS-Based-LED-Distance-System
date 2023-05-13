#include "C:/Keil/ARM/tm4c123gh6pm.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "systick.h"


void systick_init() 
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R  = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0X05;
}

void delay_ms(int time) 
{
	int counter= 0;
	NVIC_ST_CURRENT_R = 0 ;
	NVIC_ST_RELOAD_R = 16000-1 ;

	while(counter < time)
	{
		if ( (NVIC_ST_CTRL_R & 0X10000) != 0)
			counter++ ;
	}
}

void delay_us(int time)
{	
	int counter= 0;
	NVIC_ST_CURRENT_R = 0 ;
	NVIC_ST_RELOAD_R = 16-1 ;

	while(counter < time)
	{
		if ( (NVIC_ST_CTRL_R & 0X10000) != 0)
			counter++ ;
	}
}

