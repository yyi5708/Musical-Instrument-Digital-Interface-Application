################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/project/project_part_1.c \
../Core/Src/project/project_part_2.c \
../Core/Src/project/project_part_3.c \
../Core/Src/project/song.c \
../Core/Src/project/tone.c 

OBJS += \
./Core/Src/project/project_part_1.o \
./Core/Src/project/project_part_2.o \
./Core/Src/project/project_part_3.o \
./Core/Src/project/song.o \
./Core/Src/project/tone.o 

C_DEPS += \
./Core/Src/project/project_part_1.d \
./Core/Src/project/project_part_2.d \
./Core/Src/project/project_part_3.d \
./Core/Src/project/song.d \
./Core/Src/project/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/project/%.o Core/Src/project/%.su Core/Src/project/%.cyclo: ../Core/Src/project/%.c Core/Src/project/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/devices -I../Core/Inc/homework -I../Core/Inc/project -I../Core/Inc/system -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-project

clean-Core-2f-Src-2f-project:
	-$(RM) ./Core/Src/project/project_part_1.cyclo ./Core/Src/project/project_part_1.d ./Core/Src/project/project_part_1.o ./Core/Src/project/project_part_1.su ./Core/Src/project/project_part_2.cyclo ./Core/Src/project/project_part_2.d ./Core/Src/project/project_part_2.o ./Core/Src/project/project_part_2.su ./Core/Src/project/project_part_3.cyclo ./Core/Src/project/project_part_3.d ./Core/Src/project/project_part_3.o ./Core/Src/project/project_part_3.su ./Core/Src/project/song.cyclo ./Core/Src/project/song.d ./Core/Src/project/song.o ./Core/Src/project/song.su ./Core/Src/project/tone.cyclo ./Core/Src/project/tone.d ./Core/Src/project/tone.o ./Core/Src/project/tone.su

.PHONY: clean-Core-2f-Src-2f-project

