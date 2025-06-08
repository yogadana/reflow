################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lvgl/src/others/vg_lite_tvg/vg_lite_tvg.cpp 

C_SRCS += \
../lvgl/src/others/vg_lite_tvg/vg_lite_matrix.c 

C_DEPS += \
./lvgl/src/others/vg_lite_tvg/vg_lite_matrix.d 

OBJS += \
./lvgl/src/others/vg_lite_tvg/vg_lite_matrix.o \
./lvgl/src/others/vg_lite_tvg/vg_lite_tvg.o 

CPP_DEPS += \
./lvgl/src/others/vg_lite_tvg/vg_lite_tvg.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/others/vg_lite_tvg/%.o lvgl/src/others/vg_lite_tvg/%.su lvgl/src/others/vg_lite_tvg/%.cyclo: ../lvgl/src/others/vg_lite_tvg/%.c lvgl/src/others/vg_lite_tvg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
lvgl/src/others/vg_lite_tvg/%.o lvgl/src/others/vg_lite_tvg/%.su lvgl/src/others/vg_lite_tvg/%.cyclo: ../lvgl/src/others/vg_lite_tvg/%.cpp lvgl/src/others/vg_lite_tvg/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-others-2f-vg_lite_tvg

clean-lvgl-2f-src-2f-others-2f-vg_lite_tvg:
	-$(RM) ./lvgl/src/others/vg_lite_tvg/vg_lite_matrix.cyclo ./lvgl/src/others/vg_lite_tvg/vg_lite_matrix.d ./lvgl/src/others/vg_lite_tvg/vg_lite_matrix.o ./lvgl/src/others/vg_lite_tvg/vg_lite_matrix.su ./lvgl/src/others/vg_lite_tvg/vg_lite_tvg.cyclo ./lvgl/src/others/vg_lite_tvg/vg_lite_tvg.d ./lvgl/src/others/vg_lite_tvg/vg_lite_tvg.o ./lvgl/src/others/vg_lite_tvg/vg_lite_tvg.su

.PHONY: clean-lvgl-2f-src-2f-others-2f-vg_lite_tvg

