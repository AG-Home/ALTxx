#include "Clock_User.h"

uint8_t counterTimerA = 0;

void clockInit(void)
{
    // Configusre DCO
    DCOCTL = CALDCO_1MHZ;   
    BCSCTL1 = CALBC1_1MHZ;

    // Set CPU clock at 1Mhz
    BCSCTL2 &= ~MCLK_DCOCLK & ~MCLK_DIVIDER_1 & ~SMCLK_DCOCLK & ~SMCLK_DIVIDER_1 & ~DCO_RESISTOR;

}

void timerAInit(void)
{
    TACTL |= TACTL_SMCLK | TACTL_DIV1 | TACTL_UPMODE;
    TA0CCR0 = 10000 - 1;    // 10ms
    TACCTL0 |= CCIE;    // Enable interrupt
}