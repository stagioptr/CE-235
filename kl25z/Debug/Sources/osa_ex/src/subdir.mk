################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/osa_ex/src/fsl_os_abstraction_ex_bm.c \
../Sources/osa_ex/src/fsl_os_abstraction_ex_free_rtos.c \
../Sources/osa_ex/src/fsl_os_abstraction_ex_mqx.c \
../Sources/osa_ex/src/fsl_os_abstraction_ex_ucosii.c \
../Sources/osa_ex/src/fsl_os_abstraction_ex_ucosiii.c 

OBJS += \
./Sources/osa_ex/src/fsl_os_abstraction_ex_bm.o \
./Sources/osa_ex/src/fsl_os_abstraction_ex_free_rtos.o \
./Sources/osa_ex/src/fsl_os_abstraction_ex_mqx.o \
./Sources/osa_ex/src/fsl_os_abstraction_ex_ucosii.o \
./Sources/osa_ex/src/fsl_os_abstraction_ex_ucosiii.o 

C_DEPS += \
./Sources/osa_ex/src/fsl_os_abstraction_ex_bm.d \
./Sources/osa_ex/src/fsl_os_abstraction_ex_free_rtos.d \
./Sources/osa_ex/src/fsl_os_abstraction_ex_mqx.d \
./Sources/osa_ex/src/fsl_os_abstraction_ex_ucosii.d \
./Sources/osa_ex/src/fsl_os_abstraction_ex_ucosiii.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/osa_ex/src/%.o: ../Sources/osa_ex/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_FREE_RTOS" -I"N:/kl25z/SDK/platform/hal/inc" -I"N:/kl25z/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/kl25z/SDK/platform/system/src/clock/MKL25Z4" -I"N:/kl25z/SDK/platform/system/inc" -I"N:/kl25z/SDK/platform/osa/inc" -I"N:/kl25z/SDK/platform/CMSIS/Include" -I"N:/kl25z/SDK/platform/devices" -I"N:/kl25z/SDK/platform/devices/MKL25Z4/include" -I"N:/kl25z/SDK/platform/utilities/src" -I"N:/kl25z/SDK/platform/utilities/inc" -I"N:/kl25z/SDK/platform/devices/MKL25Z4/startup" -I"N:/kl25z/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/kl25z/Sources" -I"N:/kl25z/Generated_Code" -I"N:/kl25z/SDK/rtos/FreeRTOS/include" -I"N:/kl25z/SDK/rtos/FreeRTOS/port/gcc" -I"N:/kl25z/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/kl25z/SDK/platform/drivers/inc" -I"N:/kl25z/Sources/osa_ex/inc" -I"N:/kl25z/Sources/peripherals/RGB_LED" -I"N:/kl25z/Sources/scheduler/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


