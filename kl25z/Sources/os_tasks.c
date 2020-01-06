/* ###################################################################
**     Filename    : os_tasks.c
**     Project     : kl25z
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-12-12, 12:30, # CodeGen: 14
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task1Hz_task  - void Task1Hz_task(os_task_param_t task_init_data);
**         Task2Hz_task  - void Task2Hz_task(os_task_param_t task_init_data);
**         Task10Hz_task - void Task10Hz_task(os_task_param_t task_init_data);
**         Task25Hz_task - void Task25Hz_task(os_task_param_t task_init_data);
**         Task50Hz_task - void Task50Hz_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file os_tasks.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/
/* MODULE os_tasks */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "ledrgb_hal.h"
#include "scheduler.h"

/*
** ===================================================================
**     Callback    : Task1Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task1Hz_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */


  	if( OSA_SemaWait( scheduler_task_pSemaphore(4), 1002 ) == kStatus_OSA_Success ) {
  		OSA_TimeDelay(10);                 /* Example code (for task release) */
  		GPIO_DRV_TogglePinOutput(Probe_Scheduler_Error);
  	}
  	else {
    	Sched_Error_Catch(2);				// Error Management.
  	}



#ifdef PEX_USE_RTOS
  }
#endif
}

/*
** ===================================================================
**     Callback    : Task2Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task2Hz_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */


  	if( OSA_SemaWait( scheduler_task_pSemaphore(3), 502 ) == kStatus_OSA_Success ) {
  		OSA_TimeDelay(10);                 /* Example code (for task release) */
		}
		else {
			Sched_Error_Catch(2);				// Error Management.
		}




#ifdef PEX_USE_RTOS
  }
#endif
}

/*
** ===================================================================
**     Callback    : Task10Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task10Hz_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */


  	if( OSA_SemaWait( scheduler_task_pSemaphore(2), 102 ) == kStatus_OSA_Success ) {
  		OSA_TimeDelay(10);                 /* Example code (for task release) */
		}
		else {
			Sched_Error_Catch(2);				// Error Management.
		}



#ifdef PEX_USE_RTOS
  }
#endif
}

/*
** ===================================================================
**     Callback    : Task25Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task25Hz_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */


  	if( OSA_SemaWait( scheduler_task_pSemaphore(1), 42 ) == kStatus_OSA_Success ) {
  		OSA_TimeDelay(10);                 /* Example code (for task release) */
		}
		else {
			Sched_Error_Catch(2);				// Error Management.
		}



#ifdef PEX_USE_RTOS
  }
#endif
}

/*
** ===================================================================
**     Callback    : Task50Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task50Hz_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */


  	if( OSA_SemaWait( scheduler_task_pSemaphore(0), 22 ) == kStatus_OSA_Success ) {
  		OSA_TimeDelay(10);                 /* Example code (for task release) */
		}
		else {
			Sched_Error_Catch(2);				// Error Management.
		}



#ifdef PEX_USE_RTOS
  }
#endif
}

/* END os_tasks */

/*
** ===================================================================
**     Callback    : Sched_Error_Catch
**     Description : Error.
**     Parameters  :
**     Returns : Nothing
** ===================================================================
*/
void Sched_Error_Catch( uint32_t err_code )
{
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
