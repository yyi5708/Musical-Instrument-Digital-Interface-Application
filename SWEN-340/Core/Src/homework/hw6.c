//#include "stm32l476xx.h"
//#include "UART.h"
//
//uint8_t rxBuffer[BUFFER_SIZE];
//uint32_t rxCounter = 0;
//
//void UART2_Init(void) {
//    RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;
//    RCC->CCIPR &= ~RCC_CCIPR_USART2SEL;
//    RCC->CCIPR |= RCC_CCIPR_USART2SEL_0;
//    UART2_GPIO_Init();
//    USART_Init(USART2);
//    NVIC_EnableIRQ(USART2_IRQn);
//}
//
//void USART2_IRQHandler(void) {
//    USART_IRQHandler(USART2, rxBuffer, &rxCounter);
//}
//
//int main(void) {
//    UART2_Init();
//    while (1) {
//        if (rxCounter > 0) {
//            USART_Write(USART2, rxBuffer, rxCounter);
//            rxCounter = 0;
//        }
//    }
//}
