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
#if defined (FSL_RTOS_UCOSII)

#include <string.h>
#include <assert.h>
#include "fsl_os_abstraction.h"
#include "fsl_os_abstraction_ex.h"
#include "fsl_interrupt_manager.h"

/*! @brief Converts milliseconds to ticks*/
#define MSEC_TO_TICK(msec)  (((uint32_t)(msec)+500uL/(uint32_t)configTICK_RATE_HZ) \
                             *(uint32_t)configTICK_RATE_HZ/1000uL)
#define TICKS_TO_MSEC(tick) ((tick)*1000uL/(uint32_t)configTICK_RATE_HZ)

/*FUNCTION**********************************************************************
 *
 * Function Name : OSA_BinarySemaCreate
 * Description   : This function is used to create a binary semaphore. Return
 * kStatus_OSA_Success if create successfully, otherwise return kStatus_OSA_Error.
 *
 *END**************************************************************************/
osa_status_t OSA_BinarySemaCreate(semaphore_t *pSem)
{
#warning "OSA_BinarySemaCreate: This routine was not developed in this version, so return OSA error."

  return kStatus_OSA_Error; /* creating semaphore failed */
}

#endif /* FSL_RTOS_UCOSII */

/*******************************************************************************
 * EOF
 ******************************************************************************/
