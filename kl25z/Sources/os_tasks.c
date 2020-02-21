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
#include "statistics.h"
#include "terminal.h"

extern msg_queue_handler_t errorQueueHandler;
extern msg_queue_t errorQueue[10];

statistiucs_t
		statisticsTask1Hz = { 0, 0 },
		statisticsTask2Hz = { 0, 0 },
		statisticsTask10Hz = { 0, 0 },
		statisticsTask25Hz = { 0, 0 },
		statisticsTask50Hz = { 0, 0 };

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
	uint32_t rtos_token;
	statistiucs_t temp = { 0, 0 };

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

  	if( OSA_SemaWait( scheduler_task_pSemaphore(4), OSA_WAIT_FOREVER ) == kStatus_OSA_Success )
  	{
  		temp = scheduler_statistcs_getCount();

  		OSA_TimeDelay(1);

  		scheduler_statistcs_addTime( &statisticsTask1Hz, &temp );

  		if( OSA_MsgQGet( scheduler_task_pQueueHandler(4), &rtos_token, 0 ) != kStatus_OSA_Success )
			{
				Sched_Error_Catch(8);				// Error Management.
			}
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
	uint32_t rtos_token;
	statistiucs_t temp = { 0, 0 };

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  if( OSA_SemaWait( scheduler_task_pSemaphore(3), OSA_WAIT_FOREVER ) == kStatus_OSA_Success )
	  {
		  temp = scheduler_statistcs_getCount();

	  	OSA_TimeDelay(3);

	  	scheduler_statistcs_addTime( &statisticsTask2Hz, &temp );

	  	if( OSA_MsgQGet( scheduler_task_pQueueHandler(3), &rtos_token, 0 ) != kStatus_OSA_Success )
			{
				Sched_Error_Catch(9);				// Error Management.
			}
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
	uint32_t rtos_token;
	statistiucs_t temp = { 0, 0 };

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  if( OSA_SemaWait( scheduler_task_pSemaphore(2), OSA_WAIT_FOREVER ) == kStatus_OSA_Success )
	  {
	  	temp = scheduler_statistcs_getCount();

	  	OSA_TimeDelay(10);

			scheduler_statistcs_addTime( &statisticsTask10Hz, &temp );

			if( OSA_MsgQGet( scheduler_task_pQueueHandler(2), &rtos_token, 0 ) != kStatus_OSA_Success )
			{
				Sched_Error_Catch(10);				// Error Management.
			}
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
	uint32_t rtos_token;
	statistiucs_t temp = { 0, 0 };

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  if( OSA_SemaWait( scheduler_task_pSemaphore(1), OSA_WAIT_FOREVER ) == kStatus_OSA_Success )
	  {
	  	temp = scheduler_statistcs_getCount();

			OSA_TimeDelay(30);

			scheduler_statistcs_addTime( &statisticsTask25Hz, &temp );

	  	if( OSA_MsgQGet( scheduler_task_pQueueHandler(1), &rtos_token, 0 ) != kStatus_OSA_Success )
			{
				Sched_Error_Catch(11);				// Error Management.
			}
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
	uint32_t rtos_token;
	statistiucs_t temp = { 0, 0 };

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */


	  if( OSA_SemaWait( scheduler_task_pSemaphore(0), OSA_WAIT_FOREVER ) == kStatus_OSA_Success )
	  {
	  	temp = scheduler_statistcs_getCount();

	  	OSA_TimeDelay(7);

			scheduler_statistcs_addTime( &statisticsTask50Hz, &temp );

			if( OSA_MsgQGet( scheduler_task_pQueueHandler(0), &rtos_token, 0 ) != kStatus_OSA_Success )
			{
				Sched_Error_Catch(12);				// Error Management.
			}
	  }


#ifdef PEX_USE_RTOS
  }
#endif
}

/*
** ===================================================================
**     Callback    : Terminal_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Terminal_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	uint32_t rtos_token;
	statistiucs_t systemTotal;

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

  	if( OSA_SemaWait( scheduler_task_pSemaphore(5), OSA_WAIT_FOREVER ) == kStatus_OSA_Success )
		{
			shell_stateMachine();
/*
 * @REMOVE
 * @{
 * For debug purposes, this code print all tasks statistics into the terminal without any command.
 * This may be removed, though.
 */
			systemTotal = scheduler_statistcs_getCount();
			debug_printf("\rTask 1 Hz: %d ms - Task 2 Hz: %d ms - Task 10 Hz: %d ms - Task 25 Hz: %d ms - Task 50 Hz: %d ms - Total: %d ms",
					scheduler_statistcs_convertToMiliseconds(&statisticsTask1Hz),
					scheduler_statistcs_convertToMiliseconds(&statisticsTask2Hz),
					scheduler_statistcs_convertToMiliseconds(&statisticsTask10Hz),
					scheduler_statistcs_convertToMiliseconds(&statisticsTask25Hz),
					scheduler_statistcs_convertToMiliseconds(&statisticsTask50Hz),
					scheduler_statistcs_convertToMiliseconds(&systemTotal) );
/*
 * @}
 */

			if( OSA_MsgQGet( scheduler_task_pQueueHandler(5), &rtos_token, 0 ) != kStatus_OSA_Success )
			{
				Sched_Error_Catch(12);				// Error Management.
			}
		}

#ifdef PEX_USE_RTOS
  }
#endif
}

/* END os_tasks */
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
