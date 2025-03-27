//#include "stdint.h"
//#include "printf.h"
//
//uint32_t parseDelay(uint8_t* delay) {
//    uint32_t value = 0;
//    while (1) {
//        value = (value << 7) | (*delay & 0x7F);
//        if ((*delay & 0x80) == 0) {
//            break;
//        }
//        delay++;
//    }
//    return value;
//}
//
//void hw8_main() {
//    uint8_t delay1[] = {0x3B, 0x80, 0x27, 0x00};
//    uint8_t delay2[] = {0x83, 0x18, 0x91, 0x54, 0x64};
//    uint8_t delay3[] = {0xC5, 0x92, 0x74, 0xE3, 0x74, 0x12};
//    uint8_t delay4[] = {0x90, 0x82, 0x93, 0x64, 0xD3, 0x89};
//    custom_printf("Delay 1: %u\n", parseDelay(delay1)); // 59
//    custom_printf("Delay 2: %u\n", parseDelay(delay2)); // 408
//    custom_printf("Delay 3: %u\n", parseDelay(delay3)); // 1132916
//    custom_printf("Delay 4: %u\n", parseDelay(delay4)); // 33589732
//}
