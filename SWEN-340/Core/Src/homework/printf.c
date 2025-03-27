#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include "UART.h"
#include "printf.h"

// Custom printf function to send formatted output via UART
void custom_printf(const char *format, ...) {
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    USART_Write(USART2, (uint8_t*)buffer, strlen(buffer));
}
