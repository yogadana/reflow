################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/benchmark/lv_demo_benchmark.c 

C_DEPS += \
./lvgl/demos/benchmark/lv_demo_benchmark.d 

OBJS += \
./lvgl/demos/benchmark/lv_demo_benchmark.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/benchmark/%.o lvgl/demos/benchmark/%.su lvgl/demos/benchmark/%.cyclo: ../lvgl/demos/benchmark/%.c lvgl/demos/benchmark/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-benchmark

clean-lvgl-2f-demos-2f-benchmark:
	-$(RM) ./lvgl/demos/benchmark/lv_demo_benchmark.cyclo ./lvgl/demos/benchmark/lv_demo_benchmark.d ./lvgl/demos/benchmark/lv_demo_benchmark.o ./lvgl/demos/benchmark/lv_demo_benchmark.su

.PHONY: clean-lvgl-2f-demos-2f-benchmark

