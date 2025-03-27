//#include "activity_7.h"
//#include "printf.h"
//
//static int count = 0;
//
//void SysTick_Handler() {
//	count++;
//}
//
//void run_activity_7() {
//    struct systick* sys = (struct systick*) 0xE000E010;
//    sys->RVR = 7999999;
//    sys->CSR |= 0x1 << 2;
//    sys->CSR |= 0x1 << 1;
//    sys->CSR |= 0x1;
//    custom_printf("/r/n");
//    while (1) {
//    	if (count % 10 == 0)
//    		custom_printf("%5d\r", count / 10);
//    }
//}
