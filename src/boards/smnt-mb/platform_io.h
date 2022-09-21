/**
 * Platform IO configuration for smnt.
 *
 * Copyright Thinnect Inc. 2021.
 * @license <MIT>
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

#define PLATFORM_I2C_COUNT 1
#define PLATFORM_I2CS { I2C0 }

#define PLATFORM_ADC_COUNT 2
// 0: MCU ADC
// 1: External I2C ADC on SM1
// TODO external needs a better fake-pointer-marker than NULL probably
#define PLATFORM_ADCS { ADC0, NULL }
#define DMA_ADC ADC0

// 5V regulator (always PWM mode)
#define POWER_CONTROL_5V_ENABLE_PORT gpioPortB
#define POWER_CONTROL_5V_ENABLE_PIN 13

// 3V3 regulator external output control
#define POWER_CONTROL_3V3_ENABLE_PORT gpioPortB
#define POWER_CONTROL_3V3_ENABLE_PIN 12

// Mode switching of the main 3V3 regulator
#define POWER_CONTROL_3V3_PWM_MODE_ENABLE_PORT gpioPortF
#define POWER_CONTROL_3V3_PWM_MODE_ENABLE_PIN 4

// Microwave sensor enable
#define MICROWAVE_SENSOR_ENABLE_PORT gpioPortD
#define MICROWAVE_SENSOR_ENABLE_PIN 12

// Microwave sensor ADC
#define MICROWAVE_SENSOR_ADC_INPUT_PORT gpioPortD
#define MICROWAVE_SENSOR_ADC_INPUT_PIN 14
#define MICROWAVE_SENSOR_ADC_SCAN_GROUP adcScanInputGroup0
#define MICROWAVE_SENSOR_ADC_POS_SEL adcPosSelAPORT3XCH6

// Noise sensor ADC
#define NOISE_SENSOR_ADC_INPUT_PORT gpioPortD
#define NOISE_SENSOR_ADC_INPUT_PIN 13
#define NOISE_SENSOR_ADC_SCAN_GROUP adcScanInputGroup0
#define NOISE_SENSOR_ADC_POS_SEL adcPosSelAPORT4XCH5

#endif//PLATFORM_IO_H_
