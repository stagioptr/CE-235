/* ###################################################################
**     Filename    : Events.h
**     Project     : kl25z
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-12-11, 15:13, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "free_rtos.h"
#include "MainTask.h"
#include "lpTmr1.h"
#include "gpio1.h"
#include "Task50Hz.h"
#include "Task25Hz.h"
#include "Task10Hz.h"
#include "Task2Hz.h"
#include "Task1Hz.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Semaphore for control real time scheduler execution frequency.
 */
extern semaphore_t lowPowerTimerSema;

extern semaphore_t task50HzSema;
extern semaphore_t task25HzSema;
extern semaphore_t task10HzSema;
extern semaphore_t task2HzSema;
extern semaphore_t task1HzSema;

/*
** ===================================================================
**     Callback    : lpTmr1_OnTimerCompare
**     Description : This callback is called when timer interrupt
**     occurs.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void lpTmr1_OnTimerCompare(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __Events_H*/
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
