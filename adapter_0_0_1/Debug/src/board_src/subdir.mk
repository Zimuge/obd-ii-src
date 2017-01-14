################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/board_src/adpapter_board.cpp \
../src/board_src/board_configure.cpp 

OBJS += \
./src/board_src/adpapter_board.o \
./src/board_src/board_configure.o 

CPP_DEPS += \
./src/board_src/adpapter_board.d \
./src/board_src/board_configure.d 


# Each subdirectory must supply rules for building sources it contributes
src/board_src/%.o: ../src/board_src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++11 -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\adapter_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc\usbd" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\drivers_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\obd_protocol_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\utilities_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\board_inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


