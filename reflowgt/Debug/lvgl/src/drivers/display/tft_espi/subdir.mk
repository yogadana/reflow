################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lvgl/src/drivers/display/tft_espi/lv_tft_espi.cpp 

OBJS += \
./lvgl/src/drivers/display/tft_espi/lv_tft_espi.o 

CPP_DEPS += \
./lvgl/src/drivers/display/tft_espi/lv_tft_espi.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/drivers/display/tft_espi/%.o lvgl/src/drivers/display/tft_espi/%.su lvgl/src/drivers/display/tft_espi/%.cyclo: ../lvgl/src/drivers/display/tft_espi/%.cpp lvgl/src/drivers/display/tft_espi/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-drivers-2f-display-2f-tft_espi

clean-lvgl-2f-src-2f-drivers-2f-display-2f-tft_espi:
	-$(RM) ./lvgl/src/drivers/display/tft_espi/lv_tft_espi.cyclo ./lvgl/src/drivers/display/tft_espi/lv_tft_espi.d ./lvgl/src/drivers/display/tft_espi/lv_tft_espi.o ./lvgl/src/drivers/display/tft_espi/lv_tft_espi.su

.PHONY: clean-lvgl-2f-src-2f-drivers-2f-display-2f-tft_espi

