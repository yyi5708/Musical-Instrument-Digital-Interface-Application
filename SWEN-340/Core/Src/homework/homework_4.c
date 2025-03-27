//#include "homework_4.h"
//#include "UART.h"
//#include "printf.h"
//#include "stdint.h"
//#include "LED.h"
//
//static uint8_t buffer[100];
//static volatile uint32_t counter = 0;
//
//uint8_t read_and_print() {
//    uint8_t byte = USART_Read_Nonblocking(USART2);
//    if (byte != 0) {
//        custom_printf("%c", byte);
//    }
//    return byte;
//}
//
//char* read_line() {
//    uint8_t byte;
//    int index = 0;
//    while (index < sizeof (buffer) - 1) {
//        byte = read_and_print();
//        if (byte == '\r') {
//            break;
//        }
//        buffer [index++] = byte;
//    }
//    buffer [index] = 0;
//    custom_printf("\n");
//    return (char*) buffer;
//}
//
//void counter_handler(void) {
//    counter++;
//}
//
//void run_homework_4() {
//    uint32_t time = 0;
//    while (1) {
//        char* string = read_line();
//        custom_printf("%s\r\n", string);
//        if ((counter - time) >= 1000) {
//            LED_Toggle();
//            time = counter;
//        }
//    }
//}
