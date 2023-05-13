#ifndef UART
#define UART


#include "GPS.h"
#include "GPIO.h"
#include "LCD_setup.h"

void UART_init (void) ;

void UART_write(char data) ;

void Uart_Send_String(char * string) ;

char UART_read(void) ;

void UART2_receiveString(char *Str , char stopChar) ;


#endif

