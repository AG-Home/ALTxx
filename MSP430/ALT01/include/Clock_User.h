#ifndef CLOCK_USER
#define CLOCK_USER

#include <msp430g2553.h>
#include <stdint.h>

extern uint8_t systemCounter;
extern uint8_t counterErrorToggle;
extern uint8_t systemCycle;


#define MCLK_DCOCLK 0b11000000
#define MCLK_DIVIDER_1   0b00110000
#define SMCLK_DCOCLK 0b00001000
#define SMCLK_DIVIDER_1   0b00000110
#define DCO_RESISTOR   0b00000001

// defines for timer conf
#define TACTL_SMCLK 0b1000000000    // SMCLK
#define TACTL_DIV1 0b0000000000 // Divider by 1
#define TACTL_UPMODE 0b0000010000 // Up mode: the timer counts up to TACCR0.

#define MS_100 2
#define MS_500 5


void CLK_v_clockInit(void);

void CLK_v_timerAInit(void);


#endif
