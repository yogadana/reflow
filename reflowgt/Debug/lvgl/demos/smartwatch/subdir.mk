################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/smartwatch/lv_demo_smartwatch.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_control.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_home.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_list.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_qr.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_settings.c \
../lvgl/demos/smartwatch/lv_demo_smartwatch_weather.c 

C_DEPS += \
./lvgl/demos/smartwatch/lv_demo_smartwatch.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_control.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_home.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_list.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_qr.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_settings.d \
./lvgl/demos/smartwatch/lv_demo_smartwatch_weather.d 

OBJS += \
./lvgl/demos/smartwatch/lv_demo_smartwatch.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_control.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_home.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_list.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_qr.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_settings.o \
./lvgl/demos/smartwatch/lv_demo_smartwatch_weather.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/smartwatch/%.o lvgl/demos/smartwatch/%.su lvgl/demos/smartwatch/%.cyclo: ../lvgl/demos/smartwatch/%.c lvgl/demos/smartwatch/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-smartwatch

clean-lvgl-2f-demos-2f-smartwatch:
	-$(RM) ./lvgl/demos/smartwatch/lv_demo_smartwatch.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch.d ./lvgl/demos/smartwatch/lv_demo_smartwatch.o ./lvgl/demos/smartwatch/lv_demo_smartwatch.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_control.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_control.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_control.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_control.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_easter_egg.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_home.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_home.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_home.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_home.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_list.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_list.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_list.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_list.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_notifications.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_qr.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_qr.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_qr.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_qr.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_settings.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_settings.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_settings.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_settings.su ./lvgl/demos/smartwatch/lv_demo_smartwatch_weather.cyclo ./lvgl/demos/smartwatch/lv_demo_smartwatch_weather.d ./lvgl/demos/smartwatch/lv_demo_smartwatch_weather.o ./lvgl/demos/smartwatch/lv_demo_smartwatch_weather.su

.PHONY: clean-lvgl-2f-demos-2f-smartwatch

