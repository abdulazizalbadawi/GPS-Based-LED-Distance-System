#include "GPIO.h"

void sys_init ()
{
	SYSCTL_RCGCGPIO_R |= 0x20 ;										//enable port F clock 
	while ( (SYSCTL_PRGPIO_R & 0x20) == 0x00 )		//wait
	{} 
	GPIO_PORTF_LOCK_R = 0x4C4F434B ;		//unlock the locked registers
	GPIO_PORTF_CR_R =0x1F ;							//enable changes to the 5 pins of the port
	GPIO_PORTF_DEN_R = 0x1F ;						//enable digital function on PF0-PF4
	GPIO_PORTF_DIR_R = 0x0E ;						//set PF1-PF3 outputs and PF0 and PF4 as input
	GPIO_PORTF_AFSEL_R = 0;							//disable alternative function
	GPIO_PORTF_AMSEL_R = 0 ;						//disable the analog function
	GPIO_PORTF_PCTL_R = 0 ;							//make the pins GPIO
	GPIO_PORTF_PUR_R = 0x11 ;						//enable pull up resistors on PF0-PF4
}


void RGB_off ()
{
	GPIO_PORTF_DATA_R &= 0X11 ;
}


void RGB_CTRL (float distancediff)
{
	if (distancediff<0)
		distancediff *= -1 ;
	
	if ( distancediff <= 5 && distancediff != 0) //yellow led to be on
	{
		RGB_off() ;
		GPIO_PORTF_DATA_R |= 0X0A ;
	}
	
	else if( distancediff >5)  //red led to be on 
	{
		RGB_off() ;
		GPIO_PORTF_DATA_R |= 0X02 ;
	}
	
	else //green led to be on 
	{
		RGB_off() ;
		GPIO_PORTF_DATA_R |= 0X8 ; 
	}
}

