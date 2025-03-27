################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc_dac_demo.c \
../Core/Src/demo.c \
../Core/Src/main.c 

OBJS += \
./Core/Src/adc_dac_demo.o \
./Core/Src/demo.o \
./Core/Src/main.o 

C_DEPS += \
./Core/Src/adc_dac_demo.d \
./Core/Src/demo.d \
./Core/Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/devices -I../Core/Inc/homework -I../Core/Inc/project -I../Core/Inc/system -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc_dac_demo.cyclo ./Core/Src/adc_dac_demo.d ./Core/Src/adc_dac_demo.o ./Core/Src/adc_dac_demo.su ./Core/Src/demo.cyclo ./Core/Src/demo.d ./Core/Src/demo.o ./Core/Src/demo.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su

.PHONY: clean-Core-2f-Src

