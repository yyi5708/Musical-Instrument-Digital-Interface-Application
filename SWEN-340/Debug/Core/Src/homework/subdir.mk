################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/homework/conversion_1.c \
../Core/Src/homework/conversion_2.c \
../Core/Src/homework/homework_4.c \
../Core/Src/homework/hw6.c \
../Core/Src/homework/hw8.c \
../Core/Src/homework/printf.c 

OBJS += \
./Core/Src/homework/conversion_1.o \
./Core/Src/homework/conversion_2.o \
./Core/Src/homework/homework_4.o \
./Core/Src/homework/hw6.o \
./Core/Src/homework/hw8.o \
./Core/Src/homework/printf.o 

C_DEPS += \
./Core/Src/homework/conversion_1.d \
./Core/Src/homework/conversion_2.d \
./Core/Src/homework/homework_4.d \
./Core/Src/homework/hw6.d \
./Core/Src/homework/hw8.d \
./Core/Src/homework/printf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/homework/%.o Core/Src/homework/%.su Core/Src/homework/%.cyclo: ../Core/Src/homework/%.c Core/Src/homework/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/devices -I../Core/Inc/homework -I../Core/Inc/project -I../Core/Inc/system -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-homework

clean-Core-2f-Src-2f-homework:
	-$(RM) ./Core/Src/homework/conversion_1.cyclo ./Core/Src/homework/conversion_1.d ./Core/Src/homework/conversion_1.o ./Core/Src/homework/conversion_1.su ./Core/Src/homework/conversion_2.cyclo ./Core/Src/homework/conversion_2.d ./Core/Src/homework/conversion_2.o ./Core/Src/homework/conversion_2.su ./Core/Src/homework/homework_4.cyclo ./Core/Src/homework/homework_4.d ./Core/Src/homework/homework_4.o ./Core/Src/homework/homework_4.su ./Core/Src/homework/hw6.cyclo ./Core/Src/homework/hw6.d ./Core/Src/homework/hw6.o ./Core/Src/homework/hw6.su ./Core/Src/homework/hw8.cyclo ./Core/Src/homework/hw8.d ./Core/Src/homework/hw8.o ./Core/Src/homework/hw8.su ./Core/Src/homework/printf.cyclo ./Core/Src/homework/printf.d ./Core/Src/homework/printf.o ./Core/Src/homework/printf.su

.PHONY: clean-Core-2f-Src-2f-homework

