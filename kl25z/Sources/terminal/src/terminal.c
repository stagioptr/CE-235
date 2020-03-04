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

#include "stdint.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#include "statistics.h"
#include "terminal.h"

/*
 * get all tasks statistics to show in the terminal.
 */
extern statistiucs_t
		statisticsTask1Hz,
		statisticsTask2Hz,
		statisticsTask10Hz,
		statisticsTask25Hz,
		statisticsTask50Hz;

/*
 * Menu text definition
 */
int8_t mainMenu[] = "\033c\
*******************************************************************************\n\r\
******************************************************************************\n\r\
For debug purposes, this terminal can be helpful to analise inconsistencies\n\r\
while the operational system is running.\n\r\n\r\
                                Main Menu\n\r\n\r\
\
1- OS Pause\n\r\
2- OS Show task states\n\r\
3- OS Resume\n\r\n\r\
\
";

int8_t systemRunningString[] = "\
The system is currently running.\n\r\n\r\
";

int8_t systemSuspendedString[] = "\
The system is currently suspended.\n\r\n\r\
";

typedef enum {
	SYSTEM_SUSPENDED,
	SYSTEM_RUNNING,
} systemStateEnum_t;

/*
 * Definition of machine's states.
 */
typedef enum {
	PRINTING_MENU,
	WAIT_COMMAND,
	SUSPENDING_OS,
	RESUMMING_OS,
	SHOW_TASK_STATES,
	EXIT_MACHINE
} shellStateEnum_t;

/*
 * Machine state control variables.
 */
static shellStateEnum_t state = PRINTING_MENU;
static systemStateEnum_t systemState = SYSTEM_RUNNING;

void shell_stateMachine(void)
{
	switch( state )
	{
	case PRINTING_MENU:
		debug_printf("%s", mainMenu);
		if( systemState == SYSTEM_RUNNING )
			debug_printf("%s", systemRunningString);
		else if( systemState == SYSTEM_SUSPENDED )
			debug_printf("%s", systemSuspendedString);

		state = WAIT_COMMAND;
		break;

	case WAIT_COMMAND:
	{
		int8_t keyPressed = 0;

		keyPressed = debug_getchar();

		if( keyPressed == '1' && systemState == SYSTEM_RUNNING )
			state = SUSPENDING_OS;
		else if( keyPressed == '2' && systemState == SYSTEM_SUSPENDED )
			state = SHOW_TASK_STATES;
		else if( keyPressed == '3' && systemState == SYSTEM_SUSPENDED )
			state = RESUMMING_OS;
		break;
	}

	case SHOW_TASK_STATES:
	{
		debug_printf("\n\rTask 1 Hz: %d\n\r", scheduler_statistcs_convertToMiliseconds(&statisticsTask1Hz) );
		debug_printf("\n\rTask 2 Hz: %d\n\r", scheduler_statistcs_convertToMiliseconds(&statisticsTask2Hz) );
		debug_printf("\n\rTask 10 Hz: %d\n\r", scheduler_statistcs_convertToMiliseconds(&statisticsTask10Hz) );
		debug_printf("\n\rTask 25 Hz: %d\n\r", scheduler_statistcs_convertToMiliseconds(&statisticsTask25Hz) );
		debug_printf("\n\rTask 50 Hz: %d\n\r", scheduler_statistcs_convertToMiliseconds(&statisticsTask50Hz) );

		state = WAIT_COMMAND;

		break;
	}

	case SUSPENDING_OS:
		systemState = SYSTEM_SUSPENDED;

		state = PRINTING_MENU;
		break;

	case RESUMMING_OS:
		systemState = SYSTEM_RUNNING;

		state = PRINTING_MENU;
		break;

	case EXIT_MACHINE:
	default:
		return;
	}
}
