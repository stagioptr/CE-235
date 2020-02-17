/*
 * Copyright (c) 2020, Vítor E. S. da Cruz
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
#include "fsl_tpm_driver.h"
#include "statistics.h"

int32_t ticksCount = 0;

statistiucs_t scheduler_statistcs_getCount ( void )
{
	statistiucs_t temp;

	temp.count = TPM_DRV_CounterRead(TPM0_IDX);
	temp.ticks = ticksCount;

	return temp;
}

void scheduler_statistcs_addTime ( statistiucs_t* totals, statistiucs_t* countBeforeOperation )
{
	uint32_t temp = TPM_DRV_CounterRead(TPM0_IDX);

	if( temp > countBeforeOperation->count )
	{
		totals->count += temp - countBeforeOperation->count;
	}
	else
	{
		totals->count += ( 60000 - ( countBeforeOperation->count - temp ) );
		totals->ticks--;
	}
	while( totals->count >= 60000 )
	{
		totals->count -= 60000;
		totals->ticks += 1;
	}
	totals->ticks += abs( ticksCount - countBeforeOperation->ticks );
}

statistiucs_t scheduler_statistcs_differenceOfTime ( statistiucs_t* start, statistiucs_t* stop )
{
	statistiucs_t result;

	result.ticks = abs( stop->ticks - start->ticks );
	if( stop->count > start->count )
	{
		result.count = stop->count - start->count;
	}
	else
	{
		result.count = ( 60000 - ( start->count - stop->count ) );
		result.ticks--;
	}

	return result;
}

uint32_t scheduler_statistcs_convertToMicroseconds ( statistiucs_t* value )
{
	uint32_t temp;

	temp = value->ticks * 20;
	temp += ( ( value->count * 20 ) / 60000 );

	return temp;
}

void scheduler_statistcs_incrementCount ( void )
{
	ticksCount++;
}
