################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/adapter_0_0_1.cpp \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc15xx.cpp 

C_SRCS += \
../src/crp.c 

OBJS += \
./src/adapter_0_0_1.o \
./src/cr_cpp_config.o \
./src/cr_startup_lpc15xx.o \
./src/crp.o 

CPP_DEPS += \
./src/adapter_0_0_1.d \
./src/cr_cpp_config.d \
./src/cr_startup_lpc15xx.d 

C_DEPS += \
./src/crp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++11 -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\adapter_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc\usbd" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\drivers_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\obd_protocol_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\utilities_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\board_inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\adapter_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc\usbd" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\drivers_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\obd_protocol_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\utilities_inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


