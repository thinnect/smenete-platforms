/**
 * Basic microwave sensor configuration on the SM3 platform.
 *
 * Copyright ProLab 2020.
 * @license <PROPRIETARY>
 */

#include "loglevels.h"
#define __MODUUL__ "mws"
#define __LOG_LEVEL__ (LOG_LEVEL_mw_setup & BASE_LOG_LEVEL)
#include "log.h"

#include "mw_vehicle_sensor.h"

#include "cmsis_os2.h"

/**
 * Microwave setup is a bit complicated on SM3, there is the regulator control,
 * and separately the sensor control, even though the sensor is the only thing
 * using the regulatr. On top of that, the regulator must be in PWM mode, which
 * is not very efficient, but burst mode can cause noise in the MW sensor.
 */
static void semw_power_control(bool enable)
{
	debug1("sensor pwr %d", (int)enable);

	if(enable)
	{
		// Enable 5V regulator
		GPIO_PinModeSet(gpioPortB, 13, gpioModePushPull, 1);

		// Set regulator to PWM mode
		GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 1);

		// Enable MW sensor
		GPIO_PinModeSet(gpioPortD, 12, gpioModePushPull, 1);

		// Wait a bit
		osDelay(60);
	}
	else
	{
		// Disable MW sensor
		GPIO_PinModeSet(gpioPortD, 12, gpioModePushPull, 0);

		// Set regulator to burst mode
		GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0);

		// Disable 5V regulator as it is not used for anything else
		GPIO_PinModeSet(gpioPortB, 13, gpioModePushPull, 0);
	}
}

void mw_sensor_setup()
{
	semw_input_config_t icfg;
	icfg.gpio_port = gpioPortD;
	icfg.gpio_pin = 14;
	icfg.adc_scan_group = adcScanInputGroup0;
	icfg.adc_pos_sel = adcPosSelAPORT3XCH6;

	semw_init(&icfg, &semw_power_control);
}
