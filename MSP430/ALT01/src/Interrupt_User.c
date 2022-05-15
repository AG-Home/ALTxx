#include "Interrupt_User.h"
#include "Gpio_User.h"
#include "Clock_User.h"



void INT_v_interruptEnable(void)
{
    _BIS_SR(GIE);
    // __enable_interrupt();
}

void interruptDisable(void)
{
    _BIC_SR(GIE);
    // __disable_interrupt();
}

void INT_v_toggleTimerError(uint8_t u_data)
{
    P2OUT ^= u_data;
    counterErrorToggle = 0;
}

void INT_v_gpioIntEn(void)
{
    // Pullup/pulldown resistor disabled
	P1REN |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;
	P1IE |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;	// Enable interrupt for bit 0-3
	P1IES |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;	// The bits 0-3 are set with a high-to-low transition
	P1IFG &= ~ALL_BITS; //* clear interrupts
}

void INT_v_systemTimerEn(void)
{
    TA0CCTL0 |= CCIE;    // Enable interrupt
}

//Timer A ISR
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A_CCR0_ISR(void)
{
    systemCounter++;
    if(systemCounter == MS_100)
    {
        systemCycle = 1;
        systemCounter = 0;
    }

}

