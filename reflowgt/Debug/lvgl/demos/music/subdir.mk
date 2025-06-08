################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/music/lv_demo_music.c \
../lvgl/demos/music/lv_demo_music_list.c \
../lvgl/demos/music/lv_demo_music_main.c 

C_DEPS += \
./lvgl/demos/music/lv_demo_music.d \
./lvgl/demos/music/lv_demo_music_list.d \
./lvgl/demos/music/lv_demo_music_main.d 

OBJS += \
./lvgl/demos/music/lv_demo_music.o \
./lvgl/demos/music/lv_demo_music_list.o \
./lvgl/demos/music/lv_demo_music_main.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/music/%.o lvgl/demos/music/%.su lvgl/demos/music/%.cyclo: ../lvgl/demos/music/%.c lvgl/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-music

clean-lvgl-2f-demos-2f-music:
	-$(RM) ./lvgl/demos/music/lv_demo_music.cyclo ./lvgl/demos/music/lv_demo_music.d ./lvgl/demos/music/lv_demo_music.o ./lvgl/demos/music/lv_demo_music.su ./lvgl/demos/music/lv_demo_music_list.cyclo ./lvgl/demos/music/lv_demo_music_list.d ./lvgl/demos/music/lv_demo_music_list.o ./lvgl/demos/music/lv_demo_music_list.su ./lvgl/demos/music/lv_demo_music_main.cyclo ./lvgl/demos/music/lv_demo_music_main.d ./lvgl/demos/music/lv_demo_music_main.o ./lvgl/demos/music/lv_demo_music_main.su

.PHONY: clean-lvgl-2f-demos-2f-music

