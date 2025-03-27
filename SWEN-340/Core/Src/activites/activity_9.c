//#include "activity_7.h"
//#include "printf.h"
//#include "UART.h"
//#include "stdint.h"
//
//static uint8_t buffer[100];
//static struct systick* sys = (struct systick*) 0xE000E010;
//static int count = 0;
//static int timer = 0;
//
//uint8_t read_and_print() {
//    uint8_t byte = USART_Read(USART2);
//    custom_printf("%c", byte);
//    return byte;
//}
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
//	custom_printf ("\n");
//	return (char*) buffer;
//}
//
//void run_activity_9() {
//	while (1) {
//		char* string = read_line();
//		custom_printf("%s\r\n", string);
//	}
//}
//
//void config() {
//    sys->RVR = 7999999;
//    sys->CSR |= 0x1 << 2;
//    sys->CSR |= 0x1;
//}
//
//void count_one_second() {
//    while (!(sys->CSR & (1 << 16))) {
//    timer++;
//    }
//    if (timer >= 10) {
//        count++;
//	    custom_printf("\r\n%d\r\n", count);
//        timer = 0;
//    }
//}
//
//void read_and_clock() {
//	config();
//	while (1) {
//		read_and_print();
//		count_one_second();
//	}
//}
