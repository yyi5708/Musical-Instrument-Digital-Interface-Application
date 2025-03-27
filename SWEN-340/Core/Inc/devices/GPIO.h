#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

// Button B1 (connected to pin 13 of port C)
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

// Button S1 (connected to pin 9 of port A)
#define S1_Pin GPIO_PIN_9
#define S1_GPIO_Port GPIOA

// GPIO initialization function to configure input pins and interrupts
void GPIO_Init(void);

// Interrupt handler for EXTI lines 9 to 5 (for button S1)
void EXTI9_5_IRQHandler(void);

// Interrupt handler for EXTI lines 15 to 10 (for button B1)
void EXTI15_10_IRQHandler(void);

#endif /* INC_GPIO_H_ */
