/*
 * Copyright (c) 2019, Vítor E. S. da Cruz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <string.h>
#include <assert.h>
#include "fsl_os_abstraction.h"
#include "fsl_os_abstraction_ex.h"
#include "fsl_interrupt_manager.h"
#include "scheduler.h"

/*
 * Create all semaphores to be initialized.
 */
semaphore_t lowPowerTimerSema = NULL;

task_setup_t *task_setup_pointer = NULL;
uint32_t max_semaphores = 0;

scheduler_status_t scheduler_setup ( task_setup_t *task_setup, uint32_t length )
{
  /* Initialize all user tasks semaphores */

	task_setup_pointer = task_setup;
	max_semaphores = length;

  if( OSA_BinarySemaCreate( &lowPowerTimerSema ) != kStatus_OSA_Success )
  	Sched_Error_Catch(1);				// Error Management.

  for( uint32_t index = 0; index<length; index++ )
  {
  	if( OSA_BinarySemaCreate( task_setup[index].semaphore ) != kStatus_OSA_Success )
  		Sched_Error_Catch(1);				// Error Management.
  }
	return kStatus_scheduler_Initialized;
}

semaphore_t scheduler_task_pSemaphore ( uint32_t index )
{
	return task_setup_pointer[index].semaphore;
}

uint32_t scheduler_task_pTimer_division ( uint32_t index )
{
	return task_setup_pointer[index].timer_division;
}

__attribute((weak)) void Sched_Error_Catch( uint32_t err_code )
{
	/*
	 * Do nothing. The user must add his own implementation of this routine.
	 */

	return;
}
