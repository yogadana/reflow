################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/ui/images.c \
../Core/Inc/ui/screens.c \
../Core/Inc/ui/styles.c \
../Core/Inc/ui/ui.c \
../Core/Inc/ui/ui_image_back.c \
../Core/Inc/ui/ui_image_next.c 

C_DEPS += \
./Core/Inc/ui/images.d \
./Core/Inc/ui/screens.d \
./Core/Inc/ui/styles.d \
./Core/Inc/ui/ui.d \
./Core/Inc/ui/ui_image_back.d \
./Core/Inc/ui/ui_image_next.d 

OBJS += \
./Core/Inc/ui/images.o \
./Core/Inc/ui/screens.o \
./Core/Inc/ui/styles.o \
./Core/Inc/ui/ui.o \
./Core/Inc/ui/ui_image_back.o \
./Core/Inc/ui/ui_image_next.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ui/%.o Core/Inc/ui/%.su Core/Inc/ui/%.cyclo: ../Core/Inc/ui/%.c Core/Inc/ui/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ui

clean-Core-2f-Inc-2f-ui:
	-$(RM) ./Core/Inc/ui/images.cyclo ./Core/Inc/ui/images.d ./Core/Inc/ui/images.o ./Core/Inc/ui/images.su ./Core/Inc/ui/screens.cyclo ./Core/Inc/ui/screens.d ./Core/Inc/ui/screens.o ./Core/Inc/ui/screens.su ./Core/Inc/ui/styles.cyclo ./Core/Inc/ui/styles.d ./Core/Inc/ui/styles.o ./Core/Inc/ui/styles.su ./Core/Inc/ui/ui.cyclo ./Core/Inc/ui/ui.d ./Core/Inc/ui/ui.o ./Core/Inc/ui/ui.su ./Core/Inc/ui/ui_image_back.cyclo ./Core/Inc/ui/ui_image_back.d ./Core/Inc/ui/ui_image_back.o ./Core/Inc/ui/ui_image_back.su ./Core/Inc/ui/ui_image_next.cyclo ./Core/Inc/ui/ui_image_next.d ./Core/Inc/ui/ui_image_next.o ./Core/Inc/ui/ui_image_next.su

.PHONY: clean-Core-2f-Inc-2f-ui

