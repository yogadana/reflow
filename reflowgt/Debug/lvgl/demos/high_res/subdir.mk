################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/high_res/lv_demo_high_res.c \
../lvgl/demos/high_res/lv_demo_high_res_api_example.c \
../lvgl/demos/high_res/lv_demo_high_res_app_about.c \
../lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.c \
../lvgl/demos/high_res/lv_demo_high_res_app_smart_home.c \
../lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.c \
../lvgl/demos/high_res/lv_demo_high_res_app_thermostat.c \
../lvgl/demos/high_res/lv_demo_high_res_home.c \
../lvgl/demos/high_res/lv_demo_high_res_top_margin.c \
../lvgl/demos/high_res/lv_demo_high_res_util.c 

C_DEPS += \
./lvgl/demos/high_res/lv_demo_high_res.d \
./lvgl/demos/high_res/lv_demo_high_res_api_example.d \
./lvgl/demos/high_res/lv_demo_high_res_app_about.d \
./lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.d \
./lvgl/demos/high_res/lv_demo_high_res_app_smart_home.d \
./lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.d \
./lvgl/demos/high_res/lv_demo_high_res_app_thermostat.d \
./lvgl/demos/high_res/lv_demo_high_res_home.d \
./lvgl/demos/high_res/lv_demo_high_res_top_margin.d \
./lvgl/demos/high_res/lv_demo_high_res_util.d 

OBJS += \
./lvgl/demos/high_res/lv_demo_high_res.o \
./lvgl/demos/high_res/lv_demo_high_res_api_example.o \
./lvgl/demos/high_res/lv_demo_high_res_app_about.o \
./lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.o \
./lvgl/demos/high_res/lv_demo_high_res_app_smart_home.o \
./lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.o \
./lvgl/demos/high_res/lv_demo_high_res_app_thermostat.o \
./lvgl/demos/high_res/lv_demo_high_res_home.o \
./lvgl/demos/high_res/lv_demo_high_res_top_margin.o \
./lvgl/demos/high_res/lv_demo_high_res_util.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/high_res/%.o lvgl/demos/high_res/%.su lvgl/demos/high_res/%.cyclo: ../lvgl/demos/high_res/%.c lvgl/demos/high_res/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-high_res

clean-lvgl-2f-demos-2f-high_res:
	-$(RM) ./lvgl/demos/high_res/lv_demo_high_res.cyclo ./lvgl/demos/high_res/lv_demo_high_res.d ./lvgl/demos/high_res/lv_demo_high_res.o ./lvgl/demos/high_res/lv_demo_high_res.su ./lvgl/demos/high_res/lv_demo_high_res_api_example.cyclo ./lvgl/demos/high_res/lv_demo_high_res_api_example.d ./lvgl/demos/high_res/lv_demo_high_res_api_example.o ./lvgl/demos/high_res/lv_demo_high_res_api_example.su ./lvgl/demos/high_res/lv_demo_high_res_app_about.cyclo ./lvgl/demos/high_res/lv_demo_high_res_app_about.d ./lvgl/demos/high_res/lv_demo_high_res_app_about.o ./lvgl/demos/high_res/lv_demo_high_res_app_about.su ./lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.cyclo ./lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.d ./lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.o ./lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.su ./lvgl/demos/high_res/lv_demo_high_res_app_smart_home.cyclo ./lvgl/demos/high_res/lv_demo_high_res_app_smart_home.d ./lvgl/demos/high_res/lv_demo_high_res_app_smart_home.o ./lvgl/demos/high_res/lv_demo_high_res_app_smart_home.su ./lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.cyclo ./lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.d ./lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.o ./lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.su ./lvgl/demos/high_res/lv_demo_high_res_app_thermostat.cyclo ./lvgl/demos/high_res/lv_demo_high_res_app_thermostat.d ./lvgl/demos/high_res/lv_demo_high_res_app_thermostat.o ./lvgl/demos/high_res/lv_demo_high_res_app_thermostat.su ./lvgl/demos/high_res/lv_demo_high_res_home.cyclo ./lvgl/demos/high_res/lv_demo_high_res_home.d ./lvgl/demos/high_res/lv_demo_high_res_home.o ./lvgl/demos/high_res/lv_demo_high_res_home.su ./lvgl/demos/high_res/lv_demo_high_res_top_margin.cyclo ./lvgl/demos/high_res/lv_demo_high_res_top_margin.d ./lvgl/demos/high_res/lv_demo_high_res_top_margin.o ./lvgl/demos/high_res/lv_demo_high_res_top_margin.su ./lvgl/demos/high_res/lv_demo_high_res_util.cyclo ./lvgl/demos/high_res/lv_demo_high_res_util.d ./lvgl/demos/high_res/lv_demo_high_res_util.o ./lvgl/demos/high_res/lv_demo_high_res_util.su

.PHONY: clean-lvgl-2f-demos-2f-high_res

