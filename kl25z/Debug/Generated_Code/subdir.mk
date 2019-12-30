################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/DbgCs1.c \
../Generated_Code/MainTask.c \
../Generated_Code/Task10Hz.c \
../Generated_Code/Task1Hz.c \
../Generated_Code/Task25Hz.c \
../Generated_Code/Task2Hz.c \
../Generated_Code/Task50Hz.c \
../Generated_Code/clockMan1.c \
../Generated_Code/free_rtos.c \
../Generated_Code/gpio1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c \
../Generated_Code/tpmTmr1.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/DbgCs1.o \
./Generated_Code/MainTask.o \
./Generated_Code/Task10Hz.o \
./Generated_Code/Task1Hz.o \
./Generated_Code/Task25Hz.o \
./Generated_Code/Task2Hz.o \
./Generated_Code/Task50Hz.o \
./Generated_Code/clockMan1.o \
./Generated_Code/free_rtos.o \
./Generated_Code/gpio1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o \
./Generated_Code/tpmTmr1.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/DbgCs1.d \
./Generated_Code/MainTask.d \
./Generated_Code/Task10Hz.d \
./Generated_Code/Task1Hz.d \
./Generated_Code/Task25Hz.d \
./Generated_Code/Task2Hz.d \
./Generated_Code/Task50Hz.d \
./Generated_Code/clockMan1.d \
./Generated_Code/free_rtos.d \
./Generated_Code/gpio1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d \
./Generated_Code/tpmTmr1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_FREE_RTOS" -I"N:/kl25z/SDK/platform/hal/inc" -I"N:/kl25z/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/kl25z/SDK/platform/system/src/clock/MKL25Z4" -I"N:/kl25z/SDK/platform/system/inc" -I"N:/kl25z/SDK/platform/osa/inc" -I"N:/kl25z/SDK/platform/CMSIS/Include" -I"N:/kl25z/SDK/platform/devices" -I"N:/kl25z/SDK/platform/devices/MKL25Z4/include" -I"N:/kl25z/SDK/platform/utilities/src" -I"N:/kl25z/SDK/platform/utilities/inc" -I"N:/kl25z/SDK/platform/devices/MKL25Z4/startup" -I"N:/kl25z/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/kl25z/Sources" -I"N:/kl25z/Generated_Code" -I"N:/kl25z/SDK/rtos/FreeRTOS/include" -I"N:/kl25z/SDK/rtos/FreeRTOS/port/gcc" -I"N:/kl25z/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/kl25z/SDK/platform/drivers/inc" -I"N:/kl25z/Sources/osa_ex/inc" -I"N:/kl25z/Sources/peripherals/RGB_LED" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


