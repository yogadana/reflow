################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/list/lv_example_list_1.c \
../lvgl/examples/widgets/list/lv_example_list_2.c 

C_DEPS += \
./lvgl/examples/widgets/list/lv_example_list_1.d \
./lvgl/examples/widgets/list/lv_example_list_2.d 

OBJS += \
./lvgl/examples/widgets/list/lv_example_list_1.o \
./lvgl/examples/widgets/list/lv_example_list_2.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/list/%.o lvgl/examples/widgets/list/%.su lvgl/examples/widgets/list/%.cyclo: ../lvgl/examples/widgets/list/%.c lvgl/examples/widgets/list/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-list

clean-lvgl-2f-examples-2f-widgets-2f-list:
	-$(RM) ./lvgl/examples/widgets/list/lv_example_list_1.cyclo ./lvgl/examples/widgets/list/lv_example_list_1.d ./lvgl/examples/widgets/list/lv_example_list_1.o ./lvgl/examples/widgets/list/lv_example_list_1.su ./lvgl/examples/widgets/list/lv_example_list_2.cyclo ./lvgl/examples/widgets/list/lv_example_list_2.d ./lvgl/examples/widgets/list/lv_example_list_2.o ./lvgl/examples/widgets/list/lv_example_list_2.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-list

