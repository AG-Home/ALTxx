#ifndef CLOCK_USER
#define CLOCK_USER

#include <msp430g2553.h>
#include <stdint.h>

extern uint8_t systemCounter;
extern uint8_t counterErrorToggle;
extern uint8_t counterPumpToggle;
extern uint8_t systemCycle;

#define MS_100       2
#define MS_500       5


#endif
