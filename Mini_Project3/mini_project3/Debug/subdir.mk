################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DC_motor.c \
../PWM_TIMER0.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../miniproject.c 

OBJS += \
./ADC.o \
./DC_motor.o \
./PWM_TIMER0.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./miniproject.o 

C_DEPS += \
./ADC.d \
./DC_motor.d \
./PWM_TIMER0.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./miniproject.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


