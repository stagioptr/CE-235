/* ***************************************************************** */
/* File name:        ledrgb_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling RGB LED from the        */
/*                   FRDM-KL25Z board                                */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
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

#ifndef SOURCES_LEDRGB_HAL_H_
#define SOURCES_LEDRGB_HAL_H_

/* FDRMKL25Z RGB LED pins defintion */
#define RED_LED_PIN     (uint32_t) 18u
#define GREEN_LED_PIN   (uint32_t) 19u
#define BLUE_LED_PIN    (uint32_t) 1u

/* ************************************************ */
/* Method name:        ledrgb_init                  */
/* Method description: Initialize the RGB LED device*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_init(void);


/* ************************************************ */
/* Method name:        ledrgb_clearRedLed           */
/* Method description: Clear the "red" led from RGB */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearRedLed(void);


/* ************************************************ */
/* Method name:        ledrgb_setRedLed             */
/* Method description: Set the "red" led from RGB   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setRedLed(void);


/* ************************************************ */
/* Method name:        ledrgb_clearGreenLed         */
/* Method description: Clear  "green" led from RGB  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearGreenLed(void);


/* ************************************************ */
/* Method name:        ledrgb_setGreenLed           */
/* Method description: Set the "green" led from RGB */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setGreenLed(void);


/* ************************************************ */
/* Method name:        ledrgb_clearBlueLed          */
/* Method description: Clear the "blue" led from RGB*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearBlueLed(void);


/* ************************************************ */
/* Method name:        ledrgb_setBlueLed            */
/* Method description: Set the "blud" led from RGB  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setBlueLed(void);


#endif /* SOURCES_LEDRGB_HAL_H_ */

