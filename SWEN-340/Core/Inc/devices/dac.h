#ifndef INC_DAC_H_
#define INC_DAC_H_

#include "stm32l4xx.h"

void DAC_Init();
void DAC_Start();
void DAC_Set_Value(uint32_t value);

#endif /* INC_DAC_H_ */
