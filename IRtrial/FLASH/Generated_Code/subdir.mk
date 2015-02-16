################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ACTUATOR1.c" \
"../Generated_Code/ACTUATOR2.c" \
"../Generated_Code/BUTTON.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IRsensor.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SERVO1.c" \
"../Generated_Code/SERVO2.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/WAIT1.c" \

C_SRCS += \
../Generated_Code/ACTUATOR1.c \
../Generated_Code/ACTUATOR2.c \
../Generated_Code/BUTTON.c \
../Generated_Code/Cpu.c \
../Generated_Code/IRsensor.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SERVO1.c \
../Generated_Code/SERVO2.c \
../Generated_Code/Vectors.c \
../Generated_Code/WAIT1.c \

OBJS += \
./Generated_Code/ACTUATOR1.o \
./Generated_Code/ACTUATOR2.o \
./Generated_Code/BUTTON.o \
./Generated_Code/Cpu.o \
./Generated_Code/IRsensor.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SERVO1.o \
./Generated_Code/SERVO2.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o \

C_DEPS += \
./Generated_Code/ACTUATOR1.d \
./Generated_Code/ACTUATOR2.d \
./Generated_Code/BUTTON.d \
./Generated_Code/Cpu.d \
./Generated_Code/IRsensor.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SERVO1.d \
./Generated_Code/SERVO2.d \
./Generated_Code/Vectors.d \
./Generated_Code/WAIT1.d \

OBJS_QUOTED += \
"./Generated_Code/ACTUATOR1.o" \
"./Generated_Code/ACTUATOR2.o" \
"./Generated_Code/BUTTON.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/IRsensor.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/SERVO1.o" \
"./Generated_Code/SERVO2.o" \
"./Generated_Code/Vectors.o" \
"./Generated_Code/WAIT1.o" \

C_DEPS_QUOTED += \
"./Generated_Code/ACTUATOR1.d" \
"./Generated_Code/ACTUATOR2.d" \
"./Generated_Code/BUTTON.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/IRsensor.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/SERVO1.d" \
"./Generated_Code/SERVO2.d" \
"./Generated_Code/Vectors.d" \
"./Generated_Code/WAIT1.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ACTUATOR1.o \
./Generated_Code/ACTUATOR2.o \
./Generated_Code/BUTTON.o \
./Generated_Code/Cpu.o \
./Generated_Code/IRsensor.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SERVO1.o \
./Generated_Code/SERVO2.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ACTUATOR1.o: ../Generated_Code/ACTUATOR1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ACTUATOR1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ACTUATOR1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ACTUATOR2.o: ../Generated_Code/ACTUATOR2.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ACTUATOR2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ACTUATOR2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/BUTTON.o: ../Generated_Code/BUTTON.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BUTTON.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BUTTON.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IRsensor.o: ../Generated_Code/IRsensor.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/IRsensor.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/IRsensor.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SERVO1.o: ../Generated_Code/SERVO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SERVO1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SERVO1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SERVO2.o: ../Generated_Code/SERVO2.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SERVO2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SERVO2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/WAIT1.o: ../Generated_Code/WAIT1.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/WAIT1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/WAIT1.o"
	@echo 'Finished building: $<'
	@echo ' '


