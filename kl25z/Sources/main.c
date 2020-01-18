/* ###################################################################
**     Filename    : main.c
**     Project     : kl25z
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-12-11, 15:13, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "free_rtos.h"
#include "MainTask.h"
#include "gpio1.h"
#include "Task50Hz.h"
#include "Task25Hz.h"
#include "Task10Hz.h"
#include "Task2Hz.h"
#include "Task1Hz.h"
#include "tpmTmr1.h"
#include "DbgCs1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "fsl_os_abstraction_ex.h"
#include "ledrgb_hal.h"
#include "scheduler.h"

/*
 * Semaphore for control real time scheduler execution frequency.
 */
semaphore_t task50HzSema = NULL;
semaphore_t task25HzSema = NULL;
semaphore_t task10HzSema = NULL;
semaphore_t task2HzSema = NULL;
semaphore_t task1HzSema = NULL;

task_setup_t task_semaphores[] =
{
	{	.semaphore = &task50HzSema,
		.timer_division = 1
	},
	{	.semaphore = &task25HzSema,
		.timer_division = 2
	},
	{	.semaphore = &task10HzSema,
		.timer_division = 5
	},
	{	.semaphore = &task2HzSema,
		.timer_division = 25
	},
	{	.semaphore = &task1HzSema,
		.timer_division = 50
	},
};

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* Initialize  */
  if( scheduler_setup( task_semaphores, sizeof(task_semaphores)/sizeof(task_setup_t) ) != kStatus_scheduler_Initialized )
  	Sched_Error_Catch(1);				// Error Management.

  ledrgb_init();

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
