#include "systick.h"
#include "LCD_setup.h"
#include "GPIO.h"
#include "GPS.h"
#include "UART.h" 
#include "calcDistance.h"

extern double currentlatitude ;
extern double currentlongitude ;
extern double distanceDiff ;

int main() 
{
	systick_init() ;
	sys_init() ;
	UART_init() ;
	
	while (1)
	{
		getLocData() ;
		
		GPS_getDistance(currentlatitude, currentlongitude, 30.115, 31.1115) ;
		
		RGB_CTRL () ;
	}
	
	
}
