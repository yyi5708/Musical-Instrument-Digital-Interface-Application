#include "UART.h"

//Define the pin number for UART Transmit (TX)
#define TX_PIN 2
//Define the pin number for UART Receive (RX)
#define RX_PIN 3

// Initialize UART2
void UART2_Init(void) {
	RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;
	RCC->CCIPR &= ~RCC_CCIPR_USART2SEL;
	RCC->CCIPR |= RCC_CCIPR_USART2SEL_0;
	UART2_GPIO_Init();
	USART_Init(USART2);
}

// Initialize GPIO pins for UART2
void UART2_GPIO_Init(void) {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~(3<<(2*TX_PIN) | 3<<(2*RX_PIN));
	GPIOA->MODER |= 2<<(2*TX_PIN) | 2<<(2*RX_PIN);
	GPIOA->AFR[0] &= ~(0xF<<(4*TX_PIN) | 0xF<<(4*RX_PIN));
	GPIOA->AFR[0] |= 7<<(4*TX_PIN) | 7<<(4*RX_PIN);
	GPIOA->OSPEEDR |= 3<<(2*TX_PIN) | 3<<(2*RX_PIN);
	GPIOA->PUPDR &= ~(3<<(2*TX_PIN) | 3<<(2*RX_PIN));
	GPIOA->OTYPER &= ~(1<<TX_PIN | 1<<RX_PIN);
}

// Initialize USART with specified parameters
void USART_Init(USART_TypeDef * USARTx) {
	USARTx->CR1 &= ~USART_CR1_UE;
	USARTx->CR1 &= ~USART_CR1_M;
	USARTx->CR1 &= ~USART_CR1_OVER8;
	USARTx->CR2 &= ~USART_CR2_STOP;   
	USARTx->BRR = 0x208D;
	USARTx->CR1 |= (USART_CR1_RE | USART_CR1_TE);
  if (USARTx == UART4){	
		USARTx->CR1 |= USART_CR1_RXNEIE;
		USARTx->CR1 &= ~USART_CR1_TCIE;
		USARTx->CR1 &= ~USART_CR1_IDLEIE;
		USARTx->CR1 &= ~USART_CR1_TXEIE;
		USARTx->CR1 &= ~USART_CR1_PEIE;
		USARTx->CR1 &= ~USART_CR2_LBDIE;
		USARTx->CR1 &= ~USART_CR3_EIE;
	}
	if (USARTx == USART2){
		USARTx->ICR |= USART_ICR_TCCF;
		USART1->CR3 |= USART_CR3_DMAT | USART_CR3_DMAR;
	}
	USARTx->CR1  |= USART_CR1_UE;
	while ((USARTx->ISR & USART_ISR_TEACK) == 0);
	while ((USARTx->ISR & USART_ISR_REACK) == 0);
}

// Read a byte from the specified USART
uint8_t USART_Read(USART_TypeDef * USARTx) {
	while (!(USARTx->ISR & USART_ISR_RXNE));
	return ((uint8_t)(USARTx->RDR & 0xFF));
}

// Read a byte from the specified USART non-blockingly
uint8_t USART_Read_Nonblocking(USART_TypeDef * USARTx) {
    if (USARTx->ISR & USART_ISR_RXNE) {
        return ((uint8_t)(USARTx->RDR & 0xFF));
    }
    return 0;
}

// Write a buffer of bytes to the specified USART
void USART_Write(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t nBytes) {
	int i;
	for (i = 0; i < nBytes; i++) {
		while (!(USARTx->ISR & USART_ISR_TXE));
		USARTx->TDR = buffer[i] & 0xFF;
		USART_Delay(300);
	}
	while (!(USARTx->ISR & USART_ISR_TC));
	USARTx->ISR &= ~USART_ISR_TC;
}

// Delay function for USART operations
void USART_Delay(uint32_t us) {
	uint32_t time = 100*us/7;    
	while(--time);   
}

// USART interrupt handler for receiving and error management
void USART_IRQHandler(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t * pRx_counter){
	if(USARTx->ISR & USART_ISR_RXNE) {
		buffer[*pRx_counter] = USARTx->RDR;
		(*pRx_counter)++;  
		if((*pRx_counter) >= BUFFER_SIZE )  {
			(*pRx_counter) = 0;
		}   
	} else if(USARTx->ISR & USART_ISR_TXE) {
// 		USARTx->ISR &= ~USART_ISR_TXE;
//		Tx1_Counter++;
	} else if(USARTx->ISR & USART_ISR_ORE) {
		while(1);
	} else if(USARTx->ISR & USART_ISR_PE) {
		while(1);
	} else if(USARTx->ISR & USART_ISR_PE) {
		while(1);
	} else if (USARTx->ISR & USART_ISR_NE){
		while(1);     
	}	
}
