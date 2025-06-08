################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/drivers/wayland/lv_wayland.c \
../lvgl/src/drivers/wayland/lv_wayland_smm.c 

C_DEPS += \
./lvgl/src/drivers/wayland/lv_wayland.d \
./lvgl/src/drivers/wayland/lv_wayland_smm.d 

OBJS += \
./lvgl/src/drivers/wayland/lv_wayland.o \
./lvgl/src/drivers/wayland/lv_wayland_smm.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/drivers/wayland/%.o lvgl/src/drivers/wayland/%.su lvgl/src/drivers/wayland/%.cyclo: ../lvgl/src/drivers/wayland/%.c lvgl/src/drivers/wayland/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-drivers-2f-wayland

clean-lvgl-2f-src-2f-drivers-2f-wayland:
	-$(RM) ./lvgl/src/drivers/wayland/lv_wayland.cyclo ./lvgl/src/drivers/wayland/lv_wayland.d ./lvgl/src/drivers/wayland/lv_wayland.o ./lvgl/src/drivers/wayland/lv_wayland.su ./lvgl/src/drivers/wayland/lv_wayland_smm.cyclo ./lvgl/src/drivers/wayland/lv_wayland_smm.d ./lvgl/src/drivers/wayland/lv_wayland_smm.o ./lvgl/src/drivers/wayland/lv_wayland_smm.su

.PHONY: clean-lvgl-2f-src-2f-drivers-2f-wayland

