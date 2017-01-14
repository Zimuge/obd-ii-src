################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/drivers_src/can_controllor.cpp \
../src/drivers_src/kwp_usart.cpp \
../src/drivers_src/led.cpp \
../src/drivers_src/timer.cpp \
../src/drivers_src/usart.cpp 

OBJS += \
./src/drivers_src/can_controllor.o \
./src/drivers_src/kwp_usart.o \
./src/drivers_src/led.o \
./src/drivers_src/timer.o \
./src/drivers_src/usart.o 

CPP_DEPS += \
./src/drivers_src/can_controllor.d \
./src/drivers_src/kwp_usart.d \
./src/drivers_src/led.d \
./src/drivers_src/timer.d \
./src/drivers_src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers_src/%.o: ../src/drivers_src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++11 -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\adapter_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc\usbd" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\drivers_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\obd_protocol_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\utilities_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\board_inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


