#ifndef INTERRUPT_USER
#define INTERRUPT_USER

#pragma once

#include <msp430g2553.h>
#include <stdint.h>

void INT_v_interruptEnable(void);

void interruptDisable(void);

/// Toggle for 0.5sec the pin(s) with a possible error
void INT_v_toggleTimerError(uint8_t u_data);

void INT_v_gpioIntEn(uint8_t u_dir);

void INT_v_systemTimerEn(void);

#endif
