/*
 * Smenete platform setup.
 *
 * Copyright Thinnect Inc. 2019
 * @license <PROPRIETARY>
 */
#include "platform.h"
#include <stdio.h>
#include <stdint.h>
#include "em_chip.h"
#include "em_rmu.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_msc.h"

uint32_t PLATFORM_Init()
{
	volatile uint32_t i;
	uint32_t resetCause;

	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;
	CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;

	// Set the vector table to the start location
	SCB->VTOR = (uint32_t)VTOR_START_LOCATION;

	resetCause = RMU_ResetCauseGet();
	RMU_ResetCauseClear();

	for(i = 0; i < 3000000; i++)__asm__("nop");

	if(resetCause & RMU_RSTCAUSE_EM4RST)
	{
		EMU->CMD = EMU_CMD_EM4UNLATCH;
	}

	CHIP_Init();

	EMU_DCDCInit(&dcdcInit);
	CMU_OscillatorEnable(cmuOsc_HFRCO, 1, 1);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	CMU_HFXOInit(&hfxoInit);
	CMU_LFXOInit(&lfxoInit);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
	CMU_OscillatorEnable(cmuOsc_HFRCO, 0, 0);
	SystemCoreClockUpdate();

	MSC_Init();

    CMU_ClockEnable(cmuClock_GPIO, true);

	// SPI
	GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 1); // HOLD
	GPIO_PinModeSet(gpioPortC, 9, gpioModePushPull, 1); // WP

	return resetCause;
}

void PLATFORM_RadioInit()
{
	// Nothing
}
