################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.c \
../lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.c \
../lvgl/demos/flex_layout/lv_demo_flex_layout_main.c \
../lvgl/demos/flex_layout/lv_demo_flex_layout_view.c \
../lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.c \
../lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.c 

C_DEPS += \
./lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d \
./lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d \
./lvgl/demos/flex_layout/lv_demo_flex_layout_main.d \
./lvgl/demos/flex_layout/lv_demo_flex_layout_view.d \
./lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d \
./lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d 

OBJS += \
./lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o \
./lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o \
./lvgl/demos/flex_layout/lv_demo_flex_layout_main.o \
./lvgl/demos/flex_layout/lv_demo_flex_layout_view.o \
./lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o \
./lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/flex_layout/%.o lvgl/demos/flex_layout/%.su lvgl/demos/flex_layout/%.cyclo: ../lvgl/demos/flex_layout/%.c lvgl/demos/flex_layout/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-flex_layout

clean-lvgl-2f-demos-2f-flex_layout:
	-$(RM) ./lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.cyclo ./lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d ./lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o ./lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.su ./lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.cyclo ./lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d ./lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o ./lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.su ./lvgl/demos/flex_layout/lv_demo_flex_layout_main.cyclo ./lvgl/demos/flex_layout/lv_demo_flex_layout_main.d ./lvgl/demos/flex_layout/lv_demo_flex_layout_main.o ./lvgl/demos/flex_layout/lv_demo_flex_layout_main.su ./lvgl/demos/flex_layout/lv_demo_flex_layout_view.cyclo ./lvgl/demos/flex_layout/lv_demo_flex_layout_view.d ./lvgl/demos/flex_layout/lv_demo_flex_layout_view.o ./lvgl/demos/flex_layout/lv_demo_flex_layout_view.su ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.cyclo ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.su ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.cyclo ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o ./lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.su

.PHONY: clean-lvgl-2f-demos-2f-flex_layout

