//#include "stdio.h"
//#include "string.h"
//#include "LED.h"
//#include "UART.h"
//#include "demo.h"
//#include "stm32l4xx.h"
//#include "systick.h"
//
////static void delay_loop(int value)
////{
////	for (int i = 0; i < value; i++)
////		;
////}
//
//static void demo_of_UART_print(int counter) {
//	int n;
//	uint8_t buffer[BUFFER_SIZE];
//	n = sprintf((char *)buffer, "counter = %d\r\n", counter);
//	USART_Write(USART2, buffer, n);
////	delay_loop( 8000000 );
//	delay_systick();
//	LED_Toggle();
//}
//
//void run_demo() {
//	int counter = 0;
//	init_systick();
//	while (1) {
//		demo_of_UART_print(counter);
//		counter++;
//	}
//}
