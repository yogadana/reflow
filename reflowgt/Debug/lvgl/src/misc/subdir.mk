################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/misc/lv_anim.c \
../lvgl/src/misc/lv_anim_timeline.c \
../lvgl/src/misc/lv_area.c \
../lvgl/src/misc/lv_array.c \
../lvgl/src/misc/lv_async.c \
../lvgl/src/misc/lv_bidi.c \
../lvgl/src/misc/lv_circle_buf.c \
../lvgl/src/misc/lv_color.c \
../lvgl/src/misc/lv_color_op.c \
../lvgl/src/misc/lv_event.c \
../lvgl/src/misc/lv_fs.c \
../lvgl/src/misc/lv_iter.c \
../lvgl/src/misc/lv_ll.c \
../lvgl/src/misc/lv_log.c \
../lvgl/src/misc/lv_lru.c \
../lvgl/src/misc/lv_math.c \
../lvgl/src/misc/lv_matrix.c \
../lvgl/src/misc/lv_palette.c \
../lvgl/src/misc/lv_profiler_builtin.c \
../lvgl/src/misc/lv_rb.c \
../lvgl/src/misc/lv_style.c \
../lvgl/src/misc/lv_style_gen.c \
../lvgl/src/misc/lv_templ.c \
../lvgl/src/misc/lv_text.c \
../lvgl/src/misc/lv_text_ap.c \
../lvgl/src/misc/lv_timer.c \
../lvgl/src/misc/lv_tree.c \
../lvgl/src/misc/lv_utils.c 

C_DEPS += \
./lvgl/src/misc/lv_anim.d \
./lvgl/src/misc/lv_anim_timeline.d \
./lvgl/src/misc/lv_area.d \
./lvgl/src/misc/lv_array.d \
./lvgl/src/misc/lv_async.d \
./lvgl/src/misc/lv_bidi.d \
./lvgl/src/misc/lv_circle_buf.d \
./lvgl/src/misc/lv_color.d \
./lvgl/src/misc/lv_color_op.d \
./lvgl/src/misc/lv_event.d \
./lvgl/src/misc/lv_fs.d \
./lvgl/src/misc/lv_iter.d \
./lvgl/src/misc/lv_ll.d \
./lvgl/src/misc/lv_log.d \
./lvgl/src/misc/lv_lru.d \
./lvgl/src/misc/lv_math.d \
./lvgl/src/misc/lv_matrix.d \
./lvgl/src/misc/lv_palette.d \
./lvgl/src/misc/lv_profiler_builtin.d \
./lvgl/src/misc/lv_rb.d \
./lvgl/src/misc/lv_style.d \
./lvgl/src/misc/lv_style_gen.d \
./lvgl/src/misc/lv_templ.d \
./lvgl/src/misc/lv_text.d \
./lvgl/src/misc/lv_text_ap.d \
./lvgl/src/misc/lv_timer.d \
./lvgl/src/misc/lv_tree.d \
./lvgl/src/misc/lv_utils.d 

OBJS += \
./lvgl/src/misc/lv_anim.o \
./lvgl/src/misc/lv_anim_timeline.o \
./lvgl/src/misc/lv_area.o \
./lvgl/src/misc/lv_array.o \
./lvgl/src/misc/lv_async.o \
./lvgl/src/misc/lv_bidi.o \
./lvgl/src/misc/lv_circle_buf.o \
./lvgl/src/misc/lv_color.o \
./lvgl/src/misc/lv_color_op.o \
./lvgl/src/misc/lv_event.o \
./lvgl/src/misc/lv_fs.o \
./lvgl/src/misc/lv_iter.o \
./lvgl/src/misc/lv_ll.o \
./lvgl/src/misc/lv_log.o \
./lvgl/src/misc/lv_lru.o \
./lvgl/src/misc/lv_math.o \
./lvgl/src/misc/lv_matrix.o \
./lvgl/src/misc/lv_palette.o \
./lvgl/src/misc/lv_profiler_builtin.o \
./lvgl/src/misc/lv_rb.o \
./lvgl/src/misc/lv_style.o \
./lvgl/src/misc/lv_style_gen.o \
./lvgl/src/misc/lv_templ.o \
./lvgl/src/misc/lv_text.o \
./lvgl/src/misc/lv_text_ap.o \
./lvgl/src/misc/lv_timer.o \
./lvgl/src/misc/lv_tree.o \
./lvgl/src/misc/lv_utils.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/misc/%.o lvgl/src/misc/%.su lvgl/src/misc/%.cyclo: ../lvgl/src/misc/%.c lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-misc

clean-lvgl-2f-src-2f-misc:
	-$(RM) ./lvgl/src/misc/lv_anim.cyclo ./lvgl/src/misc/lv_anim.d ./lvgl/src/misc/lv_anim.o ./lvgl/src/misc/lv_anim.su ./lvgl/src/misc/lv_anim_timeline.cyclo ./lvgl/src/misc/lv_anim_timeline.d ./lvgl/src/misc/lv_anim_timeline.o ./lvgl/src/misc/lv_anim_timeline.su ./lvgl/src/misc/lv_area.cyclo ./lvgl/src/misc/lv_area.d ./lvgl/src/misc/lv_area.o ./lvgl/src/misc/lv_area.su ./lvgl/src/misc/lv_array.cyclo ./lvgl/src/misc/lv_array.d ./lvgl/src/misc/lv_array.o ./lvgl/src/misc/lv_array.su ./lvgl/src/misc/lv_async.cyclo ./lvgl/src/misc/lv_async.d ./lvgl/src/misc/lv_async.o ./lvgl/src/misc/lv_async.su ./lvgl/src/misc/lv_bidi.cyclo ./lvgl/src/misc/lv_bidi.d ./lvgl/src/misc/lv_bidi.o ./lvgl/src/misc/lv_bidi.su ./lvgl/src/misc/lv_circle_buf.cyclo ./lvgl/src/misc/lv_circle_buf.d ./lvgl/src/misc/lv_circle_buf.o ./lvgl/src/misc/lv_circle_buf.su ./lvgl/src/misc/lv_color.cyclo ./lvgl/src/misc/lv_color.d ./lvgl/src/misc/lv_color.o ./lvgl/src/misc/lv_color.su ./lvgl/src/misc/lv_color_op.cyclo ./lvgl/src/misc/lv_color_op.d ./lvgl/src/misc/lv_color_op.o ./lvgl/src/misc/lv_color_op.su ./lvgl/src/misc/lv_event.cyclo ./lvgl/src/misc/lv_event.d ./lvgl/src/misc/lv_event.o ./lvgl/src/misc/lv_event.su ./lvgl/src/misc/lv_fs.cyclo ./lvgl/src/misc/lv_fs.d ./lvgl/src/misc/lv_fs.o ./lvgl/src/misc/lv_fs.su ./lvgl/src/misc/lv_iter.cyclo ./lvgl/src/misc/lv_iter.d ./lvgl/src/misc/lv_iter.o ./lvgl/src/misc/lv_iter.su ./lvgl/src/misc/lv_ll.cyclo ./lvgl/src/misc/lv_ll.d ./lvgl/src/misc/lv_ll.o ./lvgl/src/misc/lv_ll.su ./lvgl/src/misc/lv_log.cyclo ./lvgl/src/misc/lv_log.d ./lvgl/src/misc/lv_log.o ./lvgl/src/misc/lv_log.su ./lvgl/src/misc/lv_lru.cyclo ./lvgl/src/misc/lv_lru.d ./lvgl/src/misc/lv_lru.o ./lvgl/src/misc/lv_lru.su ./lvgl/src/misc/lv_math.cyclo ./lvgl/src/misc/lv_math.d ./lvgl/src/misc/lv_math.o ./lvgl/src/misc/lv_math.su ./lvgl/src/misc/lv_matrix.cyclo ./lvgl/src/misc/lv_matrix.d ./lvgl/src/misc/lv_matrix.o ./lvgl/src/misc/lv_matrix.su ./lvgl/src/misc/lv_palette.cyclo ./lvgl/src/misc/lv_palette.d ./lvgl/src/misc/lv_palette.o ./lvgl/src/misc/lv_palette.su ./lvgl/src/misc/lv_profiler_builtin.cyclo ./lvgl/src/misc/lv_profiler_builtin.d ./lvgl/src/misc/lv_profiler_builtin.o ./lvgl/src/misc/lv_profiler_builtin.su ./lvgl/src/misc/lv_rb.cyclo ./lvgl/src/misc/lv_rb.d ./lvgl/src/misc/lv_rb.o ./lvgl/src/misc/lv_rb.su ./lvgl/src/misc/lv_style.cyclo ./lvgl/src/misc/lv_style.d ./lvgl/src/misc/lv_style.o ./lvgl/src/misc/lv_style.su ./lvgl/src/misc/lv_style_gen.cyclo ./lvgl/src/misc/lv_style_gen.d ./lvgl/src/misc/lv_style_gen.o ./lvgl/src/misc/lv_style_gen.su ./lvgl/src/misc/lv_templ.cyclo ./lvgl/src/misc/lv_templ.d ./lvgl/src/misc/lv_templ.o ./lvgl/src/misc/lv_templ.su ./lvgl/src/misc/lv_text.cyclo ./lvgl/src/misc/lv_text.d ./lvgl/src/misc/lv_text.o ./lvgl/src/misc/lv_text.su ./lvgl/src/misc/lv_text_ap.cyclo ./lvgl/src/misc/lv_text_ap.d ./lvgl/src/misc/lv_text_ap.o ./lvgl/src/misc/lv_text_ap.su ./lvgl/src/misc/lv_timer.cyclo ./lvgl/src/misc/lv_timer.d ./lvgl/src/misc/lv_timer.o ./lvgl/src/misc/lv_timer.su ./lvgl/src/misc/lv_tree.cyclo ./lvgl/src/misc/lv_tree.d ./lvgl/src/misc/lv_tree.o ./lvgl/src/misc/lv_tree.su ./lvgl/src/misc/lv_utils.cyclo ./lvgl/src/misc/lv_utils.d ./lvgl/src/misc/lv_utils.o ./lvgl/src/misc/lv_utils.su

.PHONY: clean-lvgl-2f-src-2f-misc

