#ifndef GPIO
#define GPIO

#include <stdio.h>
#include <stdint.h>
#include <Math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "C:/Keil/ARM/tm4c123gh6pm.h"

void sys_init (void) ;

void RGB_off (void) ;

void RGB_CTRL (float distancediff) ;

#endif
