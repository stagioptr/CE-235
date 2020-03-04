/* ###################################################################
**     Filename    : os_tasks.h
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
** @file os_tasks.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/

#ifndef __os_tasks_H
#define __os_tasks_H
/* MODULE os_tasks */

#include "fsl_device_registers.h"
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

#ifdef __cplusplus
extern "C" {
#endif

/*
** ===================================================================
**     Callback    : Task1Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task1Hz_task(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : Task2Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task2Hz_task(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : Task10Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task10Hz_task(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : Task25Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task25Hz_task(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : Task50Hz_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task50Hz_task(os_task_param_t task_init_data);


/*
** ===================================================================
**     Callback    : Terminal_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Terminal_task(os_task_param_t task_init_data);

/* END os_tasks */

/*
** ===================================================================
**     Callback    : Sched_Error_Catch
**     Description : Error.
**     Parameters  :
**     Returns : Nothing
** ===================================================================
*/

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __os_tasks_H*/
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
