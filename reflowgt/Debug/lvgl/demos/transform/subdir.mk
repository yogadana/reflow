################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/transform/lv_demo_transform.c 

C_DEPS += \
./lvgl/demos/transform/lv_demo_transform.d 

OBJS += \
./lvgl/demos/transform/lv_demo_transform.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/transform/%.o lvgl/demos/transform/%.su lvgl/demos/transform/%.cyclo: ../lvgl/demos/transform/%.c lvgl/demos/transform/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-transform

clean-lvgl-2f-demos-2f-transform:
	-$(RM) ./lvgl/demos/transform/lv_demo_transform.cyclo ./lvgl/demos/transform/lv_demo_transform.d ./lvgl/demos/transform/lv_demo_transform.o ./lvgl/demos/transform/lv_demo_transform.su

.PHONY: clean-lvgl-2f-demos-2f-transform

