/**
 * Platform IO configuration for smnt.
 *
 * Copyright Thinnect Inc. 2019
 * @license <PROPRIETARY>
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#include "em_gpio.h"
#include "em_adc.h"

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

#define PLATFORM_ADC_COUNT 2
// 0: MCU ADC
// 1: External I2C ADC on SM1
// TODO external needs a better fake-pointer-marker than NULL probably
#define PLAFTORM_ADCS { ADC0, NULL }

#endif//PLATFORM_IO_H_
