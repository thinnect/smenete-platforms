/**
 * Platform IO configuration for smnt.
 *
 * Copyright Thinnect Inc. 2019
 * @license <PROPRIETARY>
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#include "em_gpio.h"

#define PLATFORM_LED_COUNT 2
#define PLATFORM_LED0_PORT gpioPortF
#define PLATFORM_LED0_PIN  6
#define PLATFORM_LED1_PORT gpioPortF
#define PLATFORM_LED1_PIN  7

#define PLATFORM_PIN_COUNT 0
//#define PLATFORM_PIN1_PORT gpioPortA
//#define PLATFORM_PIN1_PIN  0

// PIR sensor
#define PIR_INT_PORT 	gpioPortF
#define PIR_INT_PIN 	3

// No button
//#define PLATFORM_BUTTON_PORT gpioPortF
//#define PLATFORM_BUTTON_PIN  4

#endif//PLATFORM_IO_H_
