################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/others/file_explorer/lv_file_explorer.c 

C_DEPS += \
./lvgl/src/others/file_explorer/lv_file_explorer.d 

OBJS += \
./lvgl/src/others/file_explorer/lv_file_explorer.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/others/file_explorer/%.o lvgl/src/others/file_explorer/%.su lvgl/src/others/file_explorer/%.cyclo: ../lvgl/src/others/file_explorer/%.c lvgl/src/others/file_explorer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-others-2f-file_explorer

clean-lvgl-2f-src-2f-others-2f-file_explorer:
	-$(RM) ./lvgl/src/others/file_explorer/lv_file_explorer.cyclo ./lvgl/src/others/file_explorer/lv_file_explorer.d ./lvgl/src/others/file_explorer/lv_file_explorer.o ./lvgl/src/others/file_explorer/lv_file_explorer.su

.PHONY: clean-lvgl-2f-src-2f-others-2f-file_explorer

