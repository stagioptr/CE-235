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
#include "TerminalTask.h"
#include "tpmTmr1.h"
#include "DbgCs1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
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
semaphore_t terminalSema = NULL;

msg_queue_handler_t task50HzQueueHandler = NULL;
msg_queue_handler_t task25HzQueueHandler = NULL;
msg_queue_handler_t task10HzQueueHandler = NULL;
msg_queue_handler_t task2HzQueueHandler = NULL;
msg_queue_handler_t task1HzQueueHandler = NULL;
msg_queue_handler_t terminalQueueHandler = NULL;

msg_queue_t task50HzQueue;
msg_queue_t task25HzQueue;
msg_queue_t task10HzQueue;
msg_queue_t task2HzQueue;
msg_queue_t task1HzQueue;
msg_queue_t terminalQueue;

msg_queue_handler_t errorQueueHandler = NULL;
msg_queue_t errorQueue[10];

task_setup_t task_setup[] =
{
	{
		.semaphore = &task50HzSema,
		.msg_queue_handler = &task50HzQueueHandler,
		.msg_queue = &task50HzQueue,
		.timer_division = 1
	},
	{
		.semaphore = &task25HzSema,
		.msg_queue_handler = &task25HzQueueHandler,
		.msg_queue = &task25HzQueue,
		.timer_division = 2
	},
	{
		.semaphore = &task10HzSema,
		.msg_queue_handler = &task10HzQueueHandler,
		.msg_queue = &task10HzQueue,
		.timer_division = 5
	},
	{
		.semaphore = &task2HzSema,
		.msg_queue_handler = &task2HzQueueHandler,
		.msg_queue = &task2HzQueue,
		.timer_division = 25
	},
	{
		.semaphore = &task1HzSema,
		.msg_queue_handler = &task1HzQueueHandler,
		.msg_queue = &task1HzQueue,
		.timer_division = 50
	},
	{
		.semaphore = &terminalSema,
		.msg_queue_handler = &terminalQueueHandler,
		.msg_queue = &terminalQueue,
		.timer_division = 5
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
  errorQueueHandler = OSA_MsgQCreate( errorQueue, 10, 1 );

  if( scheduler_setup( task_setup, sizeof(task_setup)/sizeof(task_setup_t) ) != kStatus_scheduler_Initialized )
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

void NMI_Handler (void)
{
	Sched_Error_Catch(13);				// Error Management.
	while(1);
}

void HardFault_Handler (void)
{
	Sched_Error_Catch(14);				// Error Management.
	while(1);
}

/*
** ===================================================================
**     Callback    : Sched_Error_Catch
**     Description : Software error treatment.
**     Parameters  :
**     Returns : Nothing
** ===================================================================
*/
void Sched_Error_Catch( uint32_t err_code )
{
/*
 * Add error code into an queue and then, in the shell task, it can be
 * printed in the terminal.
 */
	OSA_MsgQPut( errorQueueHandler, &err_code );

/*
 * Turn on Error LED and probe, making possible to sinalize and measure the exact
 * time that this error happened.
 */
	GPIO_DRV_TogglePinOutput(Probe_Scheduler_Error);
	ledrgb_setRedLed();
}

#ifdef __cplusplus
}  /* extern "C" */
#endif


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
