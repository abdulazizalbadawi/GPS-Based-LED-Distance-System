#include "systick.h"
#include "LCD_setup.h"
#include "GPIO.h"
#include "GPS.h"
#include "UART.h"


#include <stdio.h>
#include <stdint.h>
#include <Math.h>
#include <string.h>


double currentlatitude  ;
double currentlongitude ;
double distanceDiff ;
	
	
char GPS_logname [] = "$GPRMC," ;
char GPS_out[85] ;
char GPS_formated [12][20] ;
char *token ;

void getLocData ()
{
    int i, flag ;
		char c ;
    flag =1 ;

    //check on the log name
    do {
      
			for (i=0 ; i<7 ; i++)
        {
						c = UART_read() ; 
            if (c != GPS_logname[i] ) 
							{
                flag = 0 ;
                break;
							}
        }
    }  while (flag != 1) ;


    //save the data to the GPS array
    if (flag == 1) 
		{
        i= 0 ;
				do 
				{
					c =UART_read() ;
					GPS_out[i] = c ;
					i++ ;										
				} while(c != '*') ;
					

        i =0 ;
        for (token = strtok(GPS_out, ",") ; token ; token = strtok(NULL ,",") )
        {
            strcpy(GPS_formated[i] , token) ;
            i++ ;
        }

        //check if the data is valid or no
        if ((strcmp(GPS_formated[1], "A")) == 0 )
        {
            if (strcmp(GPS_formated[3], "N") == 0 ) {
                 currentlatitude = atof(GPS_formated[2]) ;
            }

            else{
                 currentlatitude = -(atof(GPS_formated[2])) ;
            }

            //check on the longitude direction
            if (strcmp(GPS_formated[5], "E") == 0) {
                 currentlongitude = atof(GPS_formated[4]);
            } else {
                 currentlongitude = -atof(GPS_formated[4]);
            }
        }
    }
}



