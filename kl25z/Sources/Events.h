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

#ifdef tpmTmr1_IDX
/*
** ===================================================================
**     Interrupt handler : TPM0_IRQHandler
**
**     Description :
**         User interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM0_IRQHandler(void);
#else
  /* This IRQ handler is not used by tpmTmr1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to
   * remove this handler because Processor Expert cannot modify it according to
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

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
