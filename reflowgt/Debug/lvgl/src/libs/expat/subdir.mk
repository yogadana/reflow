################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/libs/expat/xmlparse.c \
../lvgl/src/libs/expat/xmlrole.c \
../lvgl/src/libs/expat/xmltok.c \
../lvgl/src/libs/expat/xmltok_impl.c \
../lvgl/src/libs/expat/xmltok_ns.c 

C_DEPS += \
./lvgl/src/libs/expat/xmlparse.d \
./lvgl/src/libs/expat/xmlrole.d \
./lvgl/src/libs/expat/xmltok.d \
./lvgl/src/libs/expat/xmltok_impl.d \
./lvgl/src/libs/expat/xmltok_ns.d 

OBJS += \
./lvgl/src/libs/expat/xmlparse.o \
./lvgl/src/libs/expat/xmlrole.o \
./lvgl/src/libs/expat/xmltok.o \
./lvgl/src/libs/expat/xmltok_impl.o \
./lvgl/src/libs/expat/xmltok_ns.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/libs/expat/%.o lvgl/src/libs/expat/%.su lvgl/src/libs/expat/%.cyclo: ../lvgl/src/libs/expat/%.c lvgl/src/libs/expat/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/yoga/infoglobal/reflow/yt_source/reflowgt/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-libs-2f-expat

clean-lvgl-2f-src-2f-libs-2f-expat:
	-$(RM) ./lvgl/src/libs/expat/xmlparse.cyclo ./lvgl/src/libs/expat/xmlparse.d ./lvgl/src/libs/expat/xmlparse.o ./lvgl/src/libs/expat/xmlparse.su ./lvgl/src/libs/expat/xmlrole.cyclo ./lvgl/src/libs/expat/xmlrole.d ./lvgl/src/libs/expat/xmlrole.o ./lvgl/src/libs/expat/xmlrole.su ./lvgl/src/libs/expat/xmltok.cyclo ./lvgl/src/libs/expat/xmltok.d ./lvgl/src/libs/expat/xmltok.o ./lvgl/src/libs/expat/xmltok.su ./lvgl/src/libs/expat/xmltok_impl.cyclo ./lvgl/src/libs/expat/xmltok_impl.d ./lvgl/src/libs/expat/xmltok_impl.o ./lvgl/src/libs/expat/xmltok_impl.su ./lvgl/src/libs/expat/xmltok_ns.cyclo ./lvgl/src/libs/expat/xmltok_ns.d ./lvgl/src/libs/expat/xmltok_ns.o ./lvgl/src/libs/expat/xmltok_ns.su

.PHONY: clean-lvgl-2f-src-2f-libs-2f-expat

