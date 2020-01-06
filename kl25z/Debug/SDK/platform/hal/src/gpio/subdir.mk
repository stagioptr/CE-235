################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/hal/src/gpio/fsl_gpio_hal.c 

OBJS += \
./SDK/platform/hal/src/gpio/fsl_gpio_hal.o 

C_DEPS += \
./SDK/platform/hal/src/gpio/fsl_gpio_hal.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/hal/src/gpio/%.o: ../SDK/platform/hal/src/gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_FREE_RTOS" -I"N:/kl25z/SDK/platform/hal/inc" -I"N:/kl25z/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/kl25z/SDK/platform/system/src/clock/MKL25Z4" -I"N:/kl25z/SDK/platform/system/inc" -I"N:/kl25z/SDK/platform/osa/inc" -I"N:/kl25z/SDK/platform/CMSIS/Include" -I"N:/kl25z/SDK/platform/devices" -I"N:/kl25z/SDK/platform/devices/MKL25Z4/include" -I"N:/kl25z/SDK/platform/utilities/src" -I"N:/kl25z/SDK/platform/utilities/inc" -I"N:/kl25z/SDK/platform/devices/MKL25Z4/startup" -I"N:/kl25z/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/kl25z/Sources" -I"N:/kl25z/Generated_Code" -I"N:/kl25z/SDK/rtos/FreeRTOS/include" -I"N:/kl25z/SDK/rtos/FreeRTOS/port/gcc" -I"N:/kl25z/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/kl25z/SDK/platform/drivers/inc" -I"N:/kl25z/Sources/osa_ex/inc" -I"N:/kl25z/Sources/peripherals/RGB_LED" -I"N:/kl25z/Sources/scheduler/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


