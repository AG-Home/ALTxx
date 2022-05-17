#include "Clock_User.h"

uint8_t systemCounter = 0;
uint8_t counterErrorToggle = 0;
uint8_t counterPumpToggle = 0;
uint8_t systemCycle = 0;

void CLK_v_clockInit(void)
{
    // Configusre DCO
    DCOCTL = CALDCO_1MHZ;   
    BCSCTL1 = CALBC1_1MHZ;

    // Set CPU clock at 1Mhz
    BCSCTL2 &= ~MCLK_DCOCLK & ~MCLK_DIVIDER_1 & ~SMCLK_DCOCLK & ~SMCLK_DIVIDER_1 & ~DCO_RESISTOR;

}

void CLK_v_timerAInit(void)
{
    TA0CTL |= TACTL_SMCLK | TACTL_DIV1 | TACTL_UPMODE;
    TA0CCR0 = 50000 - 1;    // 50ms
    TA0CCR1 = 50000 - 1;    // 50ms
}
