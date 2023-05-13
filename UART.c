#include "UART.h" 
#include "stdlib.h"


/****************************************************
*			  				 UART initialize									  *
****************************************************/

void UART_init ()
{
	SYSCTL_RCGCUART_R |= 0x20;
	SYSCTL_RCGCGPIO_R |= 0x10;
	while ( (SYSCTL_PRGPIO_R & 0x10) == 0x00 )		//wait
	{} 
	UART5_CTL_R &= ~0x01; //disable UART5
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11;
	UART5_LCRH_R |= 0x60;
	UART5_CTL_R |= 0x301; //enable UART5
	GPIO_PORTE_AFSEL_R |= 0x30;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~0x00FF0000) | 0x00110000;
	GPIO_PORTE_DEN_R |= 0x30;
	GPIO_PORTE_AMSEL_R &= ~0x30; // disabling anlog functions for PE4 & PE5
}

void UART_Write(char data) {
  while ((UART5_FR_R & 0x0020) != 0) {}; // check if transmitter FIFO is full 
  UART5_DR_R = data;
}
void Uart_Send_String(char * string) { // function to send a string

  while ( * string) {

    UART_Write( * string);
    string++;
  }

}
char UART_read(void) {
	char x; 
  while ((UART5_FR_R & 0x0010) != 0) {}; // waits until reciever FIFO is full to recieve the data
	x = (char)(UART5_DR_R & 0xFF);
		return  x;// returns the 8 bits of the data
}

void Uart_recieve_String(char * string, int size) { // function to recieve a string

  int i;
  for (i = 0; i < size; i++)
    string[i] = UART_read();

}

void UART2_receiveString(char *Str , char stopChar)
{
	int i = 0;

	/* Receive the first byte */
	Str[i] =  UART_read();

	/* Receive the whole string until the '#' */
	while(Str[i] != stopChar)
	{
		i++;
		Str[i] =  UART_read();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}


