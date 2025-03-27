#ifndef __NUCLEO476_UART_H
#define __NUCLEO476_UART_H

#include "stm32l476xx.h"

//Defines the buffer size for UART communication
#define BUFFER_SIZE (1000)

// Function prototype to initialize UART2
void UART2_Init(void);

// Function prototype to initialize GPIO pins for UART2
void UART2_GPIO_Init(void);

// Interrupt handler for USART1
void USART1_IRQHandler(void);

// Interrupt handler for USART2
void USART2_IRQHandler(void);

// Function prototype to initialize a specified USART module
void USART_Init(USART_TypeDef * USARTx);

// Function prototype to write data to a specified USART module
void USART_Write(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t nBytes);

// Function prototype for blocking read data from a specified USART module
uint8_t USART_Read(USART_TypeDef * USARTx);

// Function prototype for non-blocking read from a specified USART module
uint8_t USART_Read_Nonblocking(USART_TypeDef * USARTx);

// Function prototype for adding a delay in microseconds for USART timing
void USART_Delay(uint32_t us);

// USART interrupt handler for managing read operations with a buffer
void USART_IRQHandler(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t * pRx_counter);

#endif /* __NUCLEO476_UART_H */
