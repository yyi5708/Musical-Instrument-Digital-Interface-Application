//#include "dac.h"
//#include "stdint.h"
//#include "tone.h"
//#include "printf.h"
//
//void activity_12_a() {
//    DAC_Init();
//    DAC_Start();
//    while (1) {
//        DAC_Set_Value(4000);
//        DAC_Set_Value(3000);
//        DAC_Set_Value(2000);
//        DAC_Set_Value(1000);
//        DAC_Set_Value(0);
//    }
//}
//
//void activity_12_b(int frequency) {
//    DAC_Init();
//    DAC_Start();
//    int counter = 500 / frequency;
//    while (1) {
//        DAC_Set_Value(4000);
//        custom_printf("1");
//        HAL_Delay(counter * 1000);
//        DAC_Set_Value(0);
//        custom_printf("0");
//        HAL_Delay(counter * 1000);
//    }
//}
//
//void activity_12_c(uint8_t note_index, uint8_t amplitude) {
//    DAC_Init();
//    DAC_Start();
//    add_tone(note_index, amplitude);
//    play_tones();
//}
//
//void activity_12_main() {
////	activity_12_a();
////	activity_12_b(100);
////	activity_12_c(0, 3000);
//}
