################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tests/example_1/helloworld.c 

C_DEPS += \
./Tests/example_1/helloworld.d 

OBJS += \
./Tests/example_1/helloworld.o 


# Each subdirectory must supply rules for building sources it contributes
Tests/example_1/%.o Tests/example_1/%.su Tests/example_1/%.cyclo: ../Tests/example_1/%.c Tests/example_1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/William/STM32CubeIDE/workspace_1.8.0/F4VE/Application" -I"C:/Users/William/STM32CubeIDE/workspace_1.8.0/F4VE/Tests/example_1" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Tests-2f-example_1

clean-Tests-2f-example_1:
	-$(RM) ./Tests/example_1/helloworld.cyclo ./Tests/example_1/helloworld.d ./Tests/example_1/helloworld.o ./Tests/example_1/helloworld.su

.PHONY: clean-Tests-2f-example_1

