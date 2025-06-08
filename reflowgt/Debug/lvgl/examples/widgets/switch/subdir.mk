################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/switch/lv_example_switch_1.c \
../lvgl/examples/widgets/switch/lv_example_switch_2.c 

C_DEPS += \
./lvgl/examples/widgets/switch/lv_example_switch_1.d \
./lvgl/examples/widgets/switch/lv_example_switch_2.d 

OBJS += \
./lvgl/examples/widgets/switch/lv_example_switch_1.o \
./lvgl/examples/widgets/switch/lv_example_switch_2.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/switch/%.o lvgl/examples/widgets/switch/%.su lvgl/examples/widgets/switch/%.cyclo: ../lvgl/examples/widgets/switch/%.c lvgl/examples/widgets/switch/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-switch

clean-lvgl-2f-examples-2f-widgets-2f-switch:
	-$(RM) ./lvgl/examples/widgets/switch/lv_example_switch_1.cyclo ./lvgl/examples/widgets/switch/lv_example_switch_1.d ./lvgl/examples/widgets/switch/lv_example_switch_1.o ./lvgl/examples/widgets/switch/lv_example_switch_1.su ./lvgl/examples/widgets/switch/lv_example_switch_2.cyclo ./lvgl/examples/widgets/switch/lv_example_switch_2.d ./lvgl/examples/widgets/switch/lv_example_switch_2.o ./lvgl/examples/widgets/switch/lv_example_switch_2.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-switch

