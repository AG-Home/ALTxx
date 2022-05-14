#include "Interrupt_User.h"

// uint8_t counter = 0;
uint8_t counter = 0;

void interruptEnable(void)
{
    _BIS_SR(GIE);
    // __enable_interrupt();
}

void interruptDisable(void)
{
    _BIC_SR(GIE);
    // __disable_interrupt();
}

void toggleTimerError(uint8_t u_data)
{
    P2OUT ^= u_data;
    counter = 0;
}


//Timer A ISR
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A_CCR0_ISR(void)
{
    counter++;
}
