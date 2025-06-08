################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/ebike/lv_demo_ebike.c \
../lvgl/demos/ebike/lv_demo_ebike_home.c \
../lvgl/demos/ebike/lv_demo_ebike_settings.c \
../lvgl/demos/ebike/lv_demo_ebike_stats.c 

C_DEPS += \
./lvgl/demos/ebike/lv_demo_ebike.d \
./lvgl/demos/ebike/lv_demo_ebike_home.d \
./lvgl/demos/ebike/lv_demo_ebike_settings.d \
./lvgl/demos/ebike/lv_demo_ebike_stats.d 

OBJS += \
./lvgl/demos/ebike/lv_demo_ebike.o \
./lvgl/demos/ebike/lv_demo_ebike_home.o \
./lvgl/demos/ebike/lv_demo_ebike_settings.o \
./lvgl/demos/ebike/lv_demo_ebike_stats.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/ebike/%.o lvgl/demos/ebike/%.su lvgl/demos/ebike/%.cyclo: ../lvgl/demos/ebike/%.c lvgl/demos/ebike/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-ebike

clean-lvgl-2f-demos-2f-ebike:
	-$(RM) ./lvgl/demos/ebike/lv_demo_ebike.cyclo ./lvgl/demos/ebike/lv_demo_ebike.d ./lvgl/demos/ebike/lv_demo_ebike.o ./lvgl/demos/ebike/lv_demo_ebike.su ./lvgl/demos/ebike/lv_demo_ebike_home.cyclo ./lvgl/demos/ebike/lv_demo_ebike_home.d ./lvgl/demos/ebike/lv_demo_ebike_home.o ./lvgl/demos/ebike/lv_demo_ebike_home.su ./lvgl/demos/ebike/lv_demo_ebike_settings.cyclo ./lvgl/demos/ebike/lv_demo_ebike_settings.d ./lvgl/demos/ebike/lv_demo_ebike_settings.o ./lvgl/demos/ebike/lv_demo_ebike_settings.su ./lvgl/demos/ebike/lv_demo_ebike_stats.cyclo ./lvgl/demos/ebike/lv_demo_ebike_stats.d ./lvgl/demos/ebike/lv_demo_ebike_stats.o ./lvgl/demos/ebike/lv_demo_ebike_stats.su

.PHONY: clean-lvgl-2f-demos-2f-ebike

