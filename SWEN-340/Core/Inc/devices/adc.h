#ifndef INC_ADC_H_
#define INC_ADC_H_
#define ADC_CHANNEL ADC_CHANNEL_5

#include "stm32l4xx.h"

void ADC_Init();
void ADC_Start();
uint32_t ADC_Read_Value_Blocking();

#endif /* INC_ADC_H_ */
