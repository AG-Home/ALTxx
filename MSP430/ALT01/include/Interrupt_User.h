#ifndef INTERRUPT_USER
#define INTERRUPT_USER

#include <msp430g2553.h>
#include <stdint.h>

extern uint8_t counter;

void interruptEnable(void);

void interruptDisable(void);

/// Toggle for 0.5sec the pin(s) with a possible error 
void toggleTimerError(uint8_t u_data);

void INT_v_gpioIntEn(void);

#endif
