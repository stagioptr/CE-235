/* ###################################################################
**     Filename    : rtos_main_task.c
**     Project     : kl25z
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-12-11, 15:53, # CodeGen: 1
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         main_task - void main_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file rtos_main_task.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup rtos_main_task_module rtos_main_task module documentation
**  @{
*/
/* MODULE rtos_main_task */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "scheduler.h"

typedef enum
{
	SCHEDULER_50_HZ = 0,
	SCHEDULER_25_HZ,
	SCHEDULER_10_HZ,
	SCHEDULER_2_HZ,
	SCHEDULER_1_HZ,
	SCHEDULER_FREQ_LENGTH
}scheduler_frequency_e;

uint32_t scheduler_count_a[SCHEDULER_FREQ_LENGTH] =
{
		0, 0, 0, 0, 0
};

/* Initialization of Processor Expert components function prototype */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
extern void PEX_components_init(void);
#endif

/*
** ===================================================================
**     Callback    : main_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void main_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
//	uint32_t schedulerCount = 0;

  /* Initialization of Processor Expert components (when some RTOS is active). DON'T REMOVE THIS CODE!!! */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
  PEX_components_init();
#endif
  /* End of Processor Expert components initialization.  */

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  if( OSA_SemaWait( &lowPowerTimerSema, 22 ) == kStatus_OSA_Success )
	  {
		  GPIO_DRV_TogglePinOutput(Probe_Scheduler_Tick);

		  for( scheduler_frequency_e loop = SCHEDULER_50_HZ; loop<SCHEDULER_FREQ_LENGTH; loop++ )
		  {
			  scheduler_count_a[loop]++;

			  if( scheduler_count_a[loop] >= scheduler_task_pTimer_division(loop) )
			  {
				  scheduler_count_a[loop] = 0;

				  if( OSA_SemaPost( scheduler_task_pSemaphore(loop) ) != kStatus_OSA_Success )
				  {
					  Sched_Error_Catch(3);				// Error Management.
				  }
			  }
		  }
	  }
	  else
	  {
	  	Sched_Error_Catch(6);				// Error Management.
		  // catch error.
	  }

#ifdef PEX_USE_RTOS
  }
#endif
}

/* END rtos_main_task */

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
