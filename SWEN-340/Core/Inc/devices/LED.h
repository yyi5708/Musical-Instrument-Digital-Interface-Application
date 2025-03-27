#ifndef __NUCLEO476_LED_H
#define __NUCLEO476_LED_H

#include "stm32l476xx.h"

// Function prototype to initialize the LED
void LED_Init(void);

// Function prototype to turn the LED off
void LED_Off(void);

// Function prototype to turn the LED on
void LED_On(void);

// Function prototype to toggle the LED state
void LED_Toggle(void);

#endif /* __NUCLEO476_LED_H */
