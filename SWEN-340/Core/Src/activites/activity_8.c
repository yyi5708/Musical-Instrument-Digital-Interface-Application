//#include "UART.h"
//#include "printf.h"
//#include "stdint.h"
//
//uint8_t read_and_print() {
//    uint8_t byte = USART_Read (USART2);
//    custom_printf ("%c", byte);
//    return byte;
//}
//
//static uint8_t buffer[80];
//
//char* read_line() {
//	uint8_t byte = read_and_print();
//	int index = 0;
//	while (byte != '\r') {
//		buffer [index] = byte;
//		index++;
//		byte = read_and_print();
//	}
//	buffer [index] = 0;
//	custom_printf("\n");
//	return (char*) buffer;
//}
//
//void run_activity_8() {
////	char* string = read_line();
////	custom_printf("%s\r\n", string);
//	while (1) {
//		char* string = read_line();
//		custom_printf ("%s\r\n", string);
//	}
//}
