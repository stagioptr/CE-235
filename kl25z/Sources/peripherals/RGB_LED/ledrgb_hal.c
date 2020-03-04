/* ***************************************************************** */
/* File name:        ledrgb_hal.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related RGB LED from the FRDM-KL25Z board       */
/*                   controller. REMARKS LEDS are inverted input     */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    27ago2019                                       */
/* ***************************************************************** */
/*
 * Copyright (c) 2019, Denis Loubach
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

#include "ledrgb_hal.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"


/* ************************************************ */
/* Method name:        ledrgb_init                  */
/* Method description: Initialize the RGB LED device*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_init(void)
{
    /* un-gate port clock*/
    CLOCK_SYS_EnablePortClock(PORTB_IDX);
    CLOCK_SYS_EnablePortClock(PORTD_IDX);

    /* set pin as gpio */
    PORT_HAL_SetMuxMode(PORTB, RED_LED_PIN, kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTB, GREEN_LED_PIN, kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTD, BLUE_LED_PIN, kPortMuxAsGpio);

    /* set pin as digital output */
    GPIO_HAL_SetPinDir(PTB, RED_LED_PIN, kGpioDigitalOutput);
    GPIO_HAL_SetPinDir(PTB, GREEN_LED_PIN, kGpioDigitalOutput);
    GPIO_HAL_SetPinDir(PTD, BLUE_LED_PIN, kGpioDigitalOutput);

    /* clear all leds */
    ledrgb_clearRedLed();
    ledrgb_clearGreenLed();
    ledrgb_clearBlueLed();
}



/* ************************************************ */
/* Method name:        ledrgb_clearRedLed           */
/* Method description: Clear the "red" led from RGB */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearRedLed(void)
{
    /* clear desired led */
    GPIO_HAL_SetPinOutput(PTB, RED_LED_PIN);
}



/* ************************************************ */
/* Method name:        ledrgb_setRedLed             */
/* Method description: Set the "red" led from RGB   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setRedLed(void)
{
    /* set desired led */
    GPIO_HAL_ClearPinOutput(PTB, RED_LED_PIN);
}



/* ************************************************ */
/* Method name:        ledrgb_clearGreenLed         */
/* Method description: Clear "green" led from RGB   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearGreenLed(void)
{
    /* clear desired led */
    GPIO_HAL_SetPinOutput(PTB, GREEN_LED_PIN);
}



/* ************************************************ */
/* Method name:        ledrgb_setGreenLed           */
/* Method description: Set the "green" led from RGB */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setGreenLed(void)
{
    /* set desired led */
    GPIO_HAL_ClearPinOutput(PTB, GREEN_LED_PIN);
}



/* ************************************************ */
/* Method name:        ledrgb_clearBlueLed          */
/* Method description: Clear the "blue" led from RGB*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearBlueLed(void)
{
    /* clear desired led */
    GPIO_HAL_SetPinOutput(PTD, BLUE_LED_PIN);
}



/* ************************************************ */
/* Method name:        ledrgb_setBlueLed            */
/* Method description: Set the "blud" led from RGB  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setBlueLed(void)
{
    /* set desired led */
    GPIO_HAL_ClearPinOutput(PTD, BLUE_LED_PIN);
}

