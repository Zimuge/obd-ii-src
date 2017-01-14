################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/chip_15xx_src/acmp_15xx.c \
../src/chip_15xx_src/adc_15xx.c \
../src/chip_15xx_src/chip_15xx.c \
../src/chip_15xx_src/clock_15xx.c \
../src/chip_15xx_src/crc_15xx.c \
../src/chip_15xx_src/dac_15xx.c \
../src/chip_15xx_src/dma_15xx.c \
../src/chip_15xx_src/eeprom.c \
../src/chip_15xx_src/gpio_15xx.c \
../src/chip_15xx_src/i2c_common_15xx.c \
../src/chip_15xx_src/i2cm_15xx.c \
../src/chip_15xx_src/i2cs_15xx.c \
../src/chip_15xx_src/iap.c \
../src/chip_15xx_src/iocon_15xx.c \
../src/chip_15xx_src/pinint_15xx.c \
../src/chip_15xx_src/pmu_15xx.c \
../src/chip_15xx_src/ring_buffer.c \
../src/chip_15xx_src/ritimer_15xx.c \
../src/chip_15xx_src/rtc_15xx.c \
../src/chip_15xx_src/sct_15xx.c \
../src/chip_15xx_src/sct_pwm_15xx.c \
../src/chip_15xx_src/sctipu_15xx.c \
../src/chip_15xx_src/spi_15xx.c \
../src/chip_15xx_src/stopwatch_15xx.c \
../src/chip_15xx_src/swm_15xx.c \
../src/chip_15xx_src/sysctl_15xx.c \
../src/chip_15xx_src/sysinit_15xx.c \
../src/chip_15xx_src/uart_15xx.c \
../src/chip_15xx_src/wwdt_15xx.c 

OBJS += \
./src/chip_15xx_src/acmp_15xx.o \
./src/chip_15xx_src/adc_15xx.o \
./src/chip_15xx_src/chip_15xx.o \
./src/chip_15xx_src/clock_15xx.o \
./src/chip_15xx_src/crc_15xx.o \
./src/chip_15xx_src/dac_15xx.o \
./src/chip_15xx_src/dma_15xx.o \
./src/chip_15xx_src/eeprom.o \
./src/chip_15xx_src/gpio_15xx.o \
./src/chip_15xx_src/i2c_common_15xx.o \
./src/chip_15xx_src/i2cm_15xx.o \
./src/chip_15xx_src/i2cs_15xx.o \
./src/chip_15xx_src/iap.o \
./src/chip_15xx_src/iocon_15xx.o \
./src/chip_15xx_src/pinint_15xx.o \
./src/chip_15xx_src/pmu_15xx.o \
./src/chip_15xx_src/ring_buffer.o \
./src/chip_15xx_src/ritimer_15xx.o \
./src/chip_15xx_src/rtc_15xx.o \
./src/chip_15xx_src/sct_15xx.o \
./src/chip_15xx_src/sct_pwm_15xx.o \
./src/chip_15xx_src/sctipu_15xx.o \
./src/chip_15xx_src/spi_15xx.o \
./src/chip_15xx_src/stopwatch_15xx.o \
./src/chip_15xx_src/swm_15xx.o \
./src/chip_15xx_src/sysctl_15xx.o \
./src/chip_15xx_src/sysinit_15xx.o \
./src/chip_15xx_src/uart_15xx.o \
./src/chip_15xx_src/wwdt_15xx.o 

C_DEPS += \
./src/chip_15xx_src/acmp_15xx.d \
./src/chip_15xx_src/adc_15xx.d \
./src/chip_15xx_src/chip_15xx.d \
./src/chip_15xx_src/clock_15xx.d \
./src/chip_15xx_src/crc_15xx.d \
./src/chip_15xx_src/dac_15xx.d \
./src/chip_15xx_src/dma_15xx.d \
./src/chip_15xx_src/eeprom.d \
./src/chip_15xx_src/gpio_15xx.d \
./src/chip_15xx_src/i2c_common_15xx.d \
./src/chip_15xx_src/i2cm_15xx.d \
./src/chip_15xx_src/i2cs_15xx.d \
./src/chip_15xx_src/iap.d \
./src/chip_15xx_src/iocon_15xx.d \
./src/chip_15xx_src/pinint_15xx.d \
./src/chip_15xx_src/pmu_15xx.d \
./src/chip_15xx_src/ring_buffer.d \
./src/chip_15xx_src/ritimer_15xx.d \
./src/chip_15xx_src/rtc_15xx.d \
./src/chip_15xx_src/sct_15xx.d \
./src/chip_15xx_src/sct_pwm_15xx.d \
./src/chip_15xx_src/sctipu_15xx.d \
./src/chip_15xx_src/spi_15xx.d \
./src/chip_15xx_src/stopwatch_15xx.d \
./src/chip_15xx_src/swm_15xx.d \
./src/chip_15xx_src/sysctl_15xx.d \
./src/chip_15xx_src/sysinit_15xx.d \
./src/chip_15xx_src/uart_15xx.d \
./src/chip_15xx_src/wwdt_15xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/chip_15xx_src/%.o: ../src/chip_15xx_src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\adapter_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc\usbd" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\chip_15xx_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\drivers_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\obd_protocol_inc" -I"C:\Users\cheri\Desktop\OBD-II\src\Adapter\adapter_0_0_1\inc\utilities_inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


