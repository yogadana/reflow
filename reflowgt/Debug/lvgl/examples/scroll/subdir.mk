################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/scroll/lv_example_scroll_1.c \
../lvgl/examples/scroll/lv_example_scroll_2.c \
../lvgl/examples/scroll/lv_example_scroll_3.c \
../lvgl/examples/scroll/lv_example_scroll_4.c \
../lvgl/examples/scroll/lv_example_scroll_5.c \
../lvgl/examples/scroll/lv_example_scroll_6.c \
../lvgl/examples/scroll/lv_example_scroll_7.c 

C_DEPS += \
./lvgl/examples/scroll/lv_example_scroll_1.d \
./lvgl/examples/scroll/lv_example_scroll_2.d \
./lvgl/examples/scroll/lv_example_scroll_3.d \
./lvgl/examples/scroll/lv_example_scroll_4.d \
./lvgl/examples/scroll/lv_example_scroll_5.d \
./lvgl/examples/scroll/lv_example_scroll_6.d \
./lvgl/examples/scroll/lv_example_scroll_7.d 

OBJS += \
./lvgl/examples/scroll/lv_example_scroll_1.o \
./lvgl/examples/scroll/lv_example_scroll_2.o \
./lvgl/examples/scroll/lv_example_scroll_3.o \
./lvgl/examples/scroll/lv_example_scroll_4.o \
./lvgl/examples/scroll/lv_example_scroll_5.o \
./lvgl/examples/scroll/lv_example_scroll_6.o \
./lvgl/examples/scroll/lv_example_scroll_7.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/scroll/%.o lvgl/examples/scroll/%.su lvgl/examples/scroll/%.cyclo: ../lvgl/examples/scroll/%.c lvgl/examples/scroll/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-scroll

clean-lvgl-2f-examples-2f-scroll:
	-$(RM) ./lvgl/examples/scroll/lv_example_scroll_1.cyclo ./lvgl/examples/scroll/lv_example_scroll_1.d ./lvgl/examples/scroll/lv_example_scroll_1.o ./lvgl/examples/scroll/lv_example_scroll_1.su ./lvgl/examples/scroll/lv_example_scroll_2.cyclo ./lvgl/examples/scroll/lv_example_scroll_2.d ./lvgl/examples/scroll/lv_example_scroll_2.o ./lvgl/examples/scroll/lv_example_scroll_2.su ./lvgl/examples/scroll/lv_example_scroll_3.cyclo ./lvgl/examples/scroll/lv_example_scroll_3.d ./lvgl/examples/scroll/lv_example_scroll_3.o ./lvgl/examples/scroll/lv_example_scroll_3.su ./lvgl/examples/scroll/lv_example_scroll_4.cyclo ./lvgl/examples/scroll/lv_example_scroll_4.d ./lvgl/examples/scroll/lv_example_scroll_4.o ./lvgl/examples/scroll/lv_example_scroll_4.su ./lvgl/examples/scroll/lv_example_scroll_5.cyclo ./lvgl/examples/scroll/lv_example_scroll_5.d ./lvgl/examples/scroll/lv_example_scroll_5.o ./lvgl/examples/scroll/lv_example_scroll_5.su ./lvgl/examples/scroll/lv_example_scroll_6.cyclo ./lvgl/examples/scroll/lv_example_scroll_6.d ./lvgl/examples/scroll/lv_example_scroll_6.o ./lvgl/examples/scroll/lv_example_scroll_6.su ./lvgl/examples/scroll/lv_example_scroll_7.cyclo ./lvgl/examples/scroll/lv_example_scroll_7.d ./lvgl/examples/scroll/lv_example_scroll_7.o ./lvgl/examples/scroll/lv_example_scroll_7.su

.PHONY: clean-lvgl-2f-examples-2f-scroll

