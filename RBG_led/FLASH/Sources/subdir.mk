################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/adc.c" \
"../Sources/botones.c" \
"../Sources/lcd.c" \
"../Sources/main.c" \
"../Sources/pwm.c" \
"../Sources/rtc.c" \
"../Sources/sa_mtb.c" \
"../Sources/timer.c" \

C_SRCS += \
../Sources/adc.c \
../Sources/botones.c \
../Sources/lcd.c \
../Sources/main.c \
../Sources/pwm.c \
../Sources/rtc.c \
../Sources/sa_mtb.c \
../Sources/timer.c \

OBJS += \
./Sources/adc.o \
./Sources/botones.o \
./Sources/lcd.o \
./Sources/main.o \
./Sources/pwm.o \
./Sources/rtc.o \
./Sources/sa_mtb.o \
./Sources/timer.o \

C_DEPS += \
./Sources/adc.d \
./Sources/botones.d \
./Sources/lcd.d \
./Sources/main.d \
./Sources/pwm.d \
./Sources/rtc.d \
./Sources/sa_mtb.d \
./Sources/timer.d \

OBJS_QUOTED += \
"./Sources/adc.o" \
"./Sources/botones.o" \
"./Sources/lcd.o" \
"./Sources/main.o" \
"./Sources/pwm.o" \
"./Sources/rtc.o" \
"./Sources/sa_mtb.o" \
"./Sources/timer.o" \

C_DEPS_QUOTED += \
"./Sources/adc.d" \
"./Sources/botones.d" \
"./Sources/lcd.d" \
"./Sources/main.d" \
"./Sources/pwm.d" \
"./Sources/rtc.d" \
"./Sources/sa_mtb.d" \
"./Sources/timer.d" \

OBJS_OS_FORMAT += \
./Sources/adc.o \
./Sources/botones.o \
./Sources/lcd.o \
./Sources/main.o \
./Sources/pwm.o \
./Sources/rtc.o \
./Sources/sa_mtb.o \
./Sources/timer.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/adc.o: ../Sources/adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/adc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/adc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/botones.o: ../Sources/botones.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/botones.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/botones.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcd.o: ../Sources/lcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcd.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcd.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pwm.o: ../Sources/pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pwm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pwm.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/rtc.o: ../Sources/rtc.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/rtc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/rtc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/timer.o: ../Sources/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/timer.o"
	@echo 'Finished building: $<'
	@echo ' '


