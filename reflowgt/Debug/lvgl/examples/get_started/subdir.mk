################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/get_started/lv_example_get_started_1.c \
../lvgl/examples/get_started/lv_example_get_started_2.c \
../lvgl/examples/get_started/lv_example_get_started_3.c \
../lvgl/examples/get_started/lv_example_get_started_4.c 

C_DEPS += \
./lvgl/examples/get_started/lv_example_get_started_1.d \
./lvgl/examples/get_started/lv_example_get_started_2.d \
./lvgl/examples/get_started/lv_example_get_started_3.d \
./lvgl/examples/get_started/lv_example_get_started_4.d 

OBJS += \
./lvgl/examples/get_started/lv_example_get_started_1.o \
./lvgl/examples/get_started/lv_example_get_started_2.o \
./lvgl/examples/get_started/lv_example_get_started_3.o \
./lvgl/examples/get_started/lv_example_get_started_4.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/get_started/%.o lvgl/examples/get_started/%.su lvgl/examples/get_started/%.cyclo: ../lvgl/examples/get_started/%.c lvgl/examples/get_started/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-get_started

clean-lvgl-2f-examples-2f-get_started:
	-$(RM) ./lvgl/examples/get_started/lv_example_get_started_1.cyclo ./lvgl/examples/get_started/lv_example_get_started_1.d ./lvgl/examples/get_started/lv_example_get_started_1.o ./lvgl/examples/get_started/lv_example_get_started_1.su ./lvgl/examples/get_started/lv_example_get_started_2.cyclo ./lvgl/examples/get_started/lv_example_get_started_2.d ./lvgl/examples/get_started/lv_example_get_started_2.o ./lvgl/examples/get_started/lv_example_get_started_2.su ./lvgl/examples/get_started/lv_example_get_started_3.cyclo ./lvgl/examples/get_started/lv_example_get_started_3.d ./lvgl/examples/get_started/lv_example_get_started_3.o ./lvgl/examples/get_started/lv_example_get_started_3.su ./lvgl/examples/get_started/lv_example_get_started_4.cyclo ./lvgl/examples/get_started/lv_example_get_started_4.d ./lvgl/examples/get_started/lv_example_get_started_4.o ./lvgl/examples/get_started/lv_example_get_started_4.su

.PHONY: clean-lvgl-2f-examples-2f-get_started

