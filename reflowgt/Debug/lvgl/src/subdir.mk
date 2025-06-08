################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/lv_init.c 

C_DEPS += \
./lvgl/src/lv_init.d 

OBJS += \
./lvgl/src/lv_init.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/%.o lvgl/src/%.su lvgl/src/%.cyclo: ../lvgl/src/%.c lvgl/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src

clean-lvgl-2f-src:
	-$(RM) ./lvgl/src/lv_init.cyclo ./lvgl/src/lv_init.d ./lvgl/src/lv_init.o ./lvgl/src/lv_init.su

.PHONY: clean-lvgl-2f-src

