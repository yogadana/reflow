################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/scale/lv_example_scale_1.c \
../lvgl/examples/widgets/scale/lv_example_scale_2.c \
../lvgl/examples/widgets/scale/lv_example_scale_3.c \
../lvgl/examples/widgets/scale/lv_example_scale_4.c \
../lvgl/examples/widgets/scale/lv_example_scale_5.c \
../lvgl/examples/widgets/scale/lv_example_scale_6.c \
../lvgl/examples/widgets/scale/lv_example_scale_7.c \
../lvgl/examples/widgets/scale/lv_example_scale_8.c \
../lvgl/examples/widgets/scale/lv_example_scale_9.c 

C_DEPS += \
./lvgl/examples/widgets/scale/lv_example_scale_1.d \
./lvgl/examples/widgets/scale/lv_example_scale_2.d \
./lvgl/examples/widgets/scale/lv_example_scale_3.d \
./lvgl/examples/widgets/scale/lv_example_scale_4.d \
./lvgl/examples/widgets/scale/lv_example_scale_5.d \
./lvgl/examples/widgets/scale/lv_example_scale_6.d \
./lvgl/examples/widgets/scale/lv_example_scale_7.d \
./lvgl/examples/widgets/scale/lv_example_scale_8.d \
./lvgl/examples/widgets/scale/lv_example_scale_9.d 

OBJS += \
./lvgl/examples/widgets/scale/lv_example_scale_1.o \
./lvgl/examples/widgets/scale/lv_example_scale_2.o \
./lvgl/examples/widgets/scale/lv_example_scale_3.o \
./lvgl/examples/widgets/scale/lv_example_scale_4.o \
./lvgl/examples/widgets/scale/lv_example_scale_5.o \
./lvgl/examples/widgets/scale/lv_example_scale_6.o \
./lvgl/examples/widgets/scale/lv_example_scale_7.o \
./lvgl/examples/widgets/scale/lv_example_scale_8.o \
./lvgl/examples/widgets/scale/lv_example_scale_9.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/scale/%.o lvgl/examples/widgets/scale/%.su lvgl/examples/widgets/scale/%.cyclo: ../lvgl/examples/widgets/scale/%.c lvgl/examples/widgets/scale/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-scale

clean-lvgl-2f-examples-2f-widgets-2f-scale:
	-$(RM) ./lvgl/examples/widgets/scale/lv_example_scale_1.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_1.d ./lvgl/examples/widgets/scale/lv_example_scale_1.o ./lvgl/examples/widgets/scale/lv_example_scale_1.su ./lvgl/examples/widgets/scale/lv_example_scale_2.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_2.d ./lvgl/examples/widgets/scale/lv_example_scale_2.o ./lvgl/examples/widgets/scale/lv_example_scale_2.su ./lvgl/examples/widgets/scale/lv_example_scale_3.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_3.d ./lvgl/examples/widgets/scale/lv_example_scale_3.o ./lvgl/examples/widgets/scale/lv_example_scale_3.su ./lvgl/examples/widgets/scale/lv_example_scale_4.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_4.d ./lvgl/examples/widgets/scale/lv_example_scale_4.o ./lvgl/examples/widgets/scale/lv_example_scale_4.su ./lvgl/examples/widgets/scale/lv_example_scale_5.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_5.d ./lvgl/examples/widgets/scale/lv_example_scale_5.o ./lvgl/examples/widgets/scale/lv_example_scale_5.su ./lvgl/examples/widgets/scale/lv_example_scale_6.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_6.d ./lvgl/examples/widgets/scale/lv_example_scale_6.o ./lvgl/examples/widgets/scale/lv_example_scale_6.su ./lvgl/examples/widgets/scale/lv_example_scale_7.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_7.d ./lvgl/examples/widgets/scale/lv_example_scale_7.o ./lvgl/examples/widgets/scale/lv_example_scale_7.su ./lvgl/examples/widgets/scale/lv_example_scale_8.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_8.d ./lvgl/examples/widgets/scale/lv_example_scale_8.o ./lvgl/examples/widgets/scale/lv_example_scale_8.su ./lvgl/examples/widgets/scale/lv_example_scale_9.cyclo ./lvgl/examples/widgets/scale/lv_example_scale_9.d ./lvgl/examples/widgets/scale/lv_example_scale_9.o ./lvgl/examples/widgets/scale/lv_example_scale_9.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-scale

