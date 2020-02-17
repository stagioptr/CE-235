/* ###################################################################
**     Filename    : Events.c
**     Project     : kl25z
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-02-13, 13:31, # CodeGen: 30
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         TPM1_IRQHandler - void TPM1_IRQHandler(void);
**         TPM0_IRQHandler - void TPM0_IRQHandler(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "scheduler.h"
#include "statistics.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#ifdef tpmTmr2_IDX
/*
** ===================================================================
**     Interrupt handler : TPM1_IRQHandler
**
**     Description :
**         User interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM1_IRQHandler(void)
{
  TPM_DRV_IRQHandler(tpmTmr2_IDX);
  /* Write your code here ... */

}
#else
  /* This IRQ handler is not used by tpmTmr2 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to
   * remove this handler because Processor Expert cannot modify it according to
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr2 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
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
void TPM0_IRQHandler(void)
{
  TPM_DRV_IRQHandler(tpmTmr1_IDX);
  /* Write your code here ... */
  scheduler_statistcs_incrementCount();
	if( OSA_SemaPost( &lowPowerTimerSema ) != kStatus_OSA_Success )
		Sched_Error_Catch(4);				// Error Management.
}
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
