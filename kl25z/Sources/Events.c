/* ###################################################################
**     Filename    : Events.c
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


/* User includes (#include below this line is not maintained by Processor Expert) */
uint32_t lptimerCount50Hertz = 0;

/*
** ===================================================================
**     Callback    : lpTmr1_OnTimerCompare
**     Description : This callback is called when timer interrupt
**     occurs.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void lpTmr1_OnTimerCompare(void)
{
  /* Write your code here ... */
	lptimerCount50Hertz++;
	if( lptimerCount50Hertz >= 10 ) {
		lptimerCount50Hertz = 0;
		if( OSA_SemaPost( &lowPowerTimerSema ) != kStatus_OSA_Success )
			while(1);
	}
}

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
