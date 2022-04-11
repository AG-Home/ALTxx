#include "Clock_User.h"


void clockInit()
{
    // Configusre DCO
    DCOCTL = CALDCO_1MHZ;   
    BCSCTL1 = CALBC1_1MHZ;

    // Set CPU clock at 1Mhz
    BCSCTL2 &= ~MCLK_DCOCLK & ~MCLK_DIVIDER_1 & ~SMCLK_DCOCLK & ~SMCLK_DIVIDER_1 & ~DCO_RESISTOR;

}