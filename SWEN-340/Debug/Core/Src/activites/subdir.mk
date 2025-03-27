################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/activites/activity_11.c \
../Core/Src/activites/activity_12.c \
../Core/Src/activites/activity_6.c \
../Core/Src/activites/activity_7.c \
../Core/Src/activites/activity_8.c \
../Core/Src/activites/activity_9.c 

OBJS += \
./Core/Src/activites/activity_11.o \
./Core/Src/activites/activity_12.o \
./Core/Src/activites/activity_6.o \
./Core/Src/activites/activity_7.o \
./Core/Src/activites/activity_8.o \
./Core/Src/activites/activity_9.o 

C_DEPS += \
./Core/Src/activites/activity_11.d \
./Core/Src/activites/activity_12.d \
./Core/Src/activites/activity_6.d \
./Core/Src/activites/activity_7.d \
./Core/Src/activites/activity_8.d \
./Core/Src/activites/activity_9.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/activites/%.o Core/Src/activites/%.su Core/Src/activites/%.cyclo: ../Core/Src/activites/%.c Core/Src/activites/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/devices -I../Core/Inc/homework -I../Core/Inc/project -I../Core/Inc/system -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-activites

clean-Core-2f-Src-2f-activites:
	-$(RM) ./Core/Src/activites/activity_11.cyclo ./Core/Src/activites/activity_11.d ./Core/Src/activites/activity_11.o ./Core/Src/activites/activity_11.su ./Core/Src/activites/activity_12.cyclo ./Core/Src/activites/activity_12.d ./Core/Src/activites/activity_12.o ./Core/Src/activites/activity_12.su ./Core/Src/activites/activity_6.cyclo ./Core/Src/activites/activity_6.d ./Core/Src/activites/activity_6.o ./Core/Src/activites/activity_6.su ./Core/Src/activites/activity_7.cyclo ./Core/Src/activites/activity_7.d ./Core/Src/activites/activity_7.o ./Core/Src/activites/activity_7.su ./Core/Src/activites/activity_8.cyclo ./Core/Src/activites/activity_8.d ./Core/Src/activites/activity_8.o ./Core/Src/activites/activity_8.su ./Core/Src/activites/activity_9.cyclo ./Core/Src/activites/activity_9.d ./Core/Src/activites/activity_9.o ./Core/Src/activites/activity_9.su

.PHONY: clean-Core-2f-Src-2f-activites

