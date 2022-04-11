#ifndef CLOCK_USER
#define CLOCK_USER

#include <msp430g2553.h>

#define MCLK_DCOCLK 0b11000000
#define MCLK_DIVIDER_1   0b00110000
#define SMCLK_DCOCLK 0b00001000
#define SMCLK_DIVIDER_1   0b00000110
#define DCO_RESISTOR   0b00000001

void clockInit();

#endif
