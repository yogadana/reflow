################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/ebike/generated/font_ebike_130.c \
../lvgl/demos/ebike/generated/font_ebike_56.c \
../lvgl/demos/ebike/generated/font_ebike_inter_14.c \
../lvgl/demos/ebike/generated/font_ebike_inter_20.c \
../lvgl/demos/ebike/generated/font_ebike_trump_24.c \
../lvgl/demos/ebike/generated/font_ebike_trump_40.c \
../lvgl/demos/ebike/generated/font_ebike_trump_48.c \
../lvgl/demos/ebike/generated/font_ebike_trump_72.c \
../lvgl/demos/ebike/generated/img_ebike_arrow_left.c \
../lvgl/demos/ebike/generated/img_ebike_arrow_left_2.c \
../lvgl/demos/ebike/generated/img_ebike_arrow_right.c \
../lvgl/demos/ebike/generated/img_ebike_arrow_right_2.c \
../lvgl/demos/ebike/generated/img_ebike_bg.c \
../lvgl/demos/ebike/generated/img_ebike_bg_large.c \
../lvgl/demos/ebike/generated/img_ebike_clock.c \
../lvgl/demos/ebike/generated/img_ebike_dropdown_icon.c \
../lvgl/demos/ebike/generated/img_ebike_home.c \
../lvgl/demos/ebike/generated/img_ebike_lamp.c \
../lvgl/demos/ebike/generated/img_ebike_scale.c \
../lvgl/demos/ebike/generated/img_ebike_scale_large.c \
../lvgl/demos/ebike/generated/img_ebike_settings.c \
../lvgl/demos/ebike/generated/img_ebike_settings_large.c \
../lvgl/demos/ebike/generated/img_ebike_stats.c \
../lvgl/demos/ebike/generated/img_ebike_stats_large.c \
../lvgl/demos/ebike/generated/img_ebike_whether.c \
../lvgl/demos/ebike/generated/lottie_ebike_settings.c \
../lvgl/demos/ebike/generated/lottie_ebike_stats.c 

C_DEPS += \
./lvgl/demos/ebike/generated/font_ebike_130.d \
./lvgl/demos/ebike/generated/font_ebike_56.d \
./lvgl/demos/ebike/generated/font_ebike_inter_14.d \
./lvgl/demos/ebike/generated/font_ebike_inter_20.d \
./lvgl/demos/ebike/generated/font_ebike_trump_24.d \
./lvgl/demos/ebike/generated/font_ebike_trump_40.d \
./lvgl/demos/ebike/generated/font_ebike_trump_48.d \
./lvgl/demos/ebike/generated/font_ebike_trump_72.d \
./lvgl/demos/ebike/generated/img_ebike_arrow_left.d \
./lvgl/demos/ebike/generated/img_ebike_arrow_left_2.d \
./lvgl/demos/ebike/generated/img_ebike_arrow_right.d \
./lvgl/demos/ebike/generated/img_ebike_arrow_right_2.d \
./lvgl/demos/ebike/generated/img_ebike_bg.d \
./lvgl/demos/ebike/generated/img_ebike_bg_large.d \
./lvgl/demos/ebike/generated/img_ebike_clock.d \
./lvgl/demos/ebike/generated/img_ebike_dropdown_icon.d \
./lvgl/demos/ebike/generated/img_ebike_home.d \
./lvgl/demos/ebike/generated/img_ebike_lamp.d \
./lvgl/demos/ebike/generated/img_ebike_scale.d \
./lvgl/demos/ebike/generated/img_ebike_scale_large.d \
./lvgl/demos/ebike/generated/img_ebike_settings.d \
./lvgl/demos/ebike/generated/img_ebike_settings_large.d \
./lvgl/demos/ebike/generated/img_ebike_stats.d \
./lvgl/demos/ebike/generated/img_ebike_stats_large.d \
./lvgl/demos/ebike/generated/img_ebike_whether.d \
./lvgl/demos/ebike/generated/lottie_ebike_settings.d \
./lvgl/demos/ebike/generated/lottie_ebike_stats.d 

OBJS += \
./lvgl/demos/ebike/generated/font_ebike_130.o \
./lvgl/demos/ebike/generated/font_ebike_56.o \
./lvgl/demos/ebike/generated/font_ebike_inter_14.o \
./lvgl/demos/ebike/generated/font_ebike_inter_20.o \
./lvgl/demos/ebike/generated/font_ebike_trump_24.o \
./lvgl/demos/ebike/generated/font_ebike_trump_40.o \
./lvgl/demos/ebike/generated/font_ebike_trump_48.o \
./lvgl/demos/ebike/generated/font_ebike_trump_72.o \
./lvgl/demos/ebike/generated/img_ebike_arrow_left.o \
./lvgl/demos/ebike/generated/img_ebike_arrow_left_2.o \
./lvgl/demos/ebike/generated/img_ebike_arrow_right.o \
./lvgl/demos/ebike/generated/img_ebike_arrow_right_2.o \
./lvgl/demos/ebike/generated/img_ebike_bg.o \
./lvgl/demos/ebike/generated/img_ebike_bg_large.o \
./lvgl/demos/ebike/generated/img_ebike_clock.o \
./lvgl/demos/ebike/generated/img_ebike_dropdown_icon.o \
./lvgl/demos/ebike/generated/img_ebike_home.o \
./lvgl/demos/ebike/generated/img_ebike_lamp.o \
./lvgl/demos/ebike/generated/img_ebike_scale.o \
./lvgl/demos/ebike/generated/img_ebike_scale_large.o \
./lvgl/demos/ebike/generated/img_ebike_settings.o \
./lvgl/demos/ebike/generated/img_ebike_settings_large.o \
./lvgl/demos/ebike/generated/img_ebike_stats.o \
./lvgl/demos/ebike/generated/img_ebike_stats_large.o \
./lvgl/demos/ebike/generated/img_ebike_whether.o \
./lvgl/demos/ebike/generated/lottie_ebike_settings.o \
./lvgl/demos/ebike/generated/lottie_ebike_stats.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/ebike/generated/%.o lvgl/demos/ebike/generated/%.su lvgl/demos/ebike/generated/%.cyclo: ../lvgl/demos/ebike/generated/%.c lvgl/demos/ebike/generated/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-ebike-2f-generated

clean-lvgl-2f-demos-2f-ebike-2f-generated:
	-$(RM) ./lvgl/demos/ebike/generated/font_ebike_130.cyclo ./lvgl/demos/ebike/generated/font_ebike_130.d ./lvgl/demos/ebike/generated/font_ebike_130.o ./lvgl/demos/ebike/generated/font_ebike_130.su ./lvgl/demos/ebike/generated/font_ebike_56.cyclo ./lvgl/demos/ebike/generated/font_ebike_56.d ./lvgl/demos/ebike/generated/font_ebike_56.o ./lvgl/demos/ebike/generated/font_ebike_56.su ./lvgl/demos/ebike/generated/font_ebike_inter_14.cyclo ./lvgl/demos/ebike/generated/font_ebike_inter_14.d ./lvgl/demos/ebike/generated/font_ebike_inter_14.o ./lvgl/demos/ebike/generated/font_ebike_inter_14.su ./lvgl/demos/ebike/generated/font_ebike_inter_20.cyclo ./lvgl/demos/ebike/generated/font_ebike_inter_20.d ./lvgl/demos/ebike/generated/font_ebike_inter_20.o ./lvgl/demos/ebike/generated/font_ebike_inter_20.su ./lvgl/demos/ebike/generated/font_ebike_trump_24.cyclo ./lvgl/demos/ebike/generated/font_ebike_trump_24.d ./lvgl/demos/ebike/generated/font_ebike_trump_24.o ./lvgl/demos/ebike/generated/font_ebike_trump_24.su ./lvgl/demos/ebike/generated/font_ebike_trump_40.cyclo ./lvgl/demos/ebike/generated/font_ebike_trump_40.d ./lvgl/demos/ebike/generated/font_ebike_trump_40.o ./lvgl/demos/ebike/generated/font_ebike_trump_40.su ./lvgl/demos/ebike/generated/font_ebike_trump_48.cyclo ./lvgl/demos/ebike/generated/font_ebike_trump_48.d ./lvgl/demos/ebike/generated/font_ebike_trump_48.o ./lvgl/demos/ebike/generated/font_ebike_trump_48.su ./lvgl/demos/ebike/generated/font_ebike_trump_72.cyclo ./lvgl/demos/ebike/generated/font_ebike_trump_72.d ./lvgl/demos/ebike/generated/font_ebike_trump_72.o ./lvgl/demos/ebike/generated/font_ebike_trump_72.su ./lvgl/demos/ebike/generated/img_ebike_arrow_left.cyclo ./lvgl/demos/ebike/generated/img_ebike_arrow_left.d ./lvgl/demos/ebike/generated/img_ebike_arrow_left.o ./lvgl/demos/ebike/generated/img_ebike_arrow_left.su ./lvgl/demos/ebike/generated/img_ebike_arrow_left_2.cyclo ./lvgl/demos/ebike/generated/img_ebike_arrow_left_2.d ./lvgl/demos/ebike/generated/img_ebike_arrow_left_2.o ./lvgl/demos/ebike/generated/img_ebike_arrow_left_2.su ./lvgl/demos/ebike/generated/img_ebike_arrow_right.cyclo ./lvgl/demos/ebike/generated/img_ebike_arrow_right.d ./lvgl/demos/ebike/generated/img_ebike_arrow_right.o ./lvgl/demos/ebike/generated/img_ebike_arrow_right.su ./lvgl/demos/ebike/generated/img_ebike_arrow_right_2.cyclo ./lvgl/demos/ebike/generated/img_ebike_arrow_right_2.d ./lvgl/demos/ebike/generated/img_ebike_arrow_right_2.o ./lvgl/demos/ebike/generated/img_ebike_arrow_right_2.su ./lvgl/demos/ebike/generated/img_ebike_bg.cyclo ./lvgl/demos/ebike/generated/img_ebike_bg.d ./lvgl/demos/ebike/generated/img_ebike_bg.o ./lvgl/demos/ebike/generated/img_ebike_bg.su ./lvgl/demos/ebike/generated/img_ebike_bg_large.cyclo ./lvgl/demos/ebike/generated/img_ebike_bg_large.d ./lvgl/demos/ebike/generated/img_ebike_bg_large.o ./lvgl/demos/ebike/generated/img_ebike_bg_large.su ./lvgl/demos/ebike/generated/img_ebike_clock.cyclo ./lvgl/demos/ebike/generated/img_ebike_clock.d ./lvgl/demos/ebike/generated/img_ebike_clock.o ./lvgl/demos/ebike/generated/img_ebike_clock.su ./lvgl/demos/ebike/generated/img_ebike_dropdown_icon.cyclo ./lvgl/demos/ebike/generated/img_ebike_dropdown_icon.d ./lvgl/demos/ebike/generated/img_ebike_dropdown_icon.o ./lvgl/demos/ebike/generated/img_ebike_dropdown_icon.su ./lvgl/demos/ebike/generated/img_ebike_home.cyclo ./lvgl/demos/ebike/generated/img_ebike_home.d ./lvgl/demos/ebike/generated/img_ebike_home.o ./lvgl/demos/ebike/generated/img_ebike_home.su ./lvgl/demos/ebike/generated/img_ebike_lamp.cyclo ./lvgl/demos/ebike/generated/img_ebike_lamp.d ./lvgl/demos/ebike/generated/img_ebike_lamp.o ./lvgl/demos/ebike/generated/img_ebike_lamp.su ./lvgl/demos/ebike/generated/img_ebike_scale.cyclo ./lvgl/demos/ebike/generated/img_ebike_scale.d ./lvgl/demos/ebike/generated/img_ebike_scale.o ./lvgl/demos/ebike/generated/img_ebike_scale.su ./lvgl/demos/ebike/generated/img_ebike_scale_large.cyclo ./lvgl/demos/ebike/generated/img_ebike_scale_large.d ./lvgl/demos/ebike/generated/img_ebike_scale_large.o ./lvgl/demos/ebike/generated/img_ebike_scale_large.su ./lvgl/demos/ebike/generated/img_ebike_settings.cyclo ./lvgl/demos/ebike/generated/img_ebike_settings.d ./lvgl/demos/ebike/generated/img_ebike_settings.o ./lvgl/demos/ebike/generated/img_ebike_settings.su ./lvgl/demos/ebike/generated/img_ebike_settings_large.cyclo ./lvgl/demos/ebike/generated/img_ebike_settings_large.d ./lvgl/demos/ebike/generated/img_ebike_settings_large.o ./lvgl/demos/ebike/generated/img_ebike_settings_large.su ./lvgl/demos/ebike/generated/img_ebike_stats.cyclo ./lvgl/demos/ebike/generated/img_ebike_stats.d ./lvgl/demos/ebike/generated/img_ebike_stats.o ./lvgl/demos/ebike/generated/img_ebike_stats.su ./lvgl/demos/ebike/generated/img_ebike_stats_large.cyclo ./lvgl/demos/ebike/generated/img_ebike_stats_large.d ./lvgl/demos/ebike/generated/img_ebike_stats_large.o ./lvgl/demos/ebike/generated/img_ebike_stats_large.su ./lvgl/demos/ebike/generated/img_ebike_whether.cyclo ./lvgl/demos/ebike/generated/img_ebike_whether.d ./lvgl/demos/ebike/generated/img_ebike_whether.o ./lvgl/demos/ebike/generated/img_ebike_whether.su ./lvgl/demos/ebike/generated/lottie_ebike_settings.cyclo ./lvgl/demos/ebike/generated/lottie_ebike_settings.d ./lvgl/demos/ebike/generated/lottie_ebike_settings.o ./lvgl/demos/ebike/generated/lottie_ebike_settings.su ./lvgl/demos/ebike/generated/lottie_ebike_stats.cyclo ./lvgl/demos/ebike/generated/lottie_ebike_stats.d ./lvgl/demos/ebike/generated/lottie_ebike_stats.o ./lvgl/demos/ebike/generated/lottie_ebike_stats.su

.PHONY: clean-lvgl-2f-demos-2f-ebike-2f-generated

