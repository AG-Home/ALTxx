#include "Interrupt_User.h"
#include "Gpio_User.h"
#include "Clock_User.h"
#include "Agh_Driver.h"



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

void INT_v_gpioIntEn(uint8_t u_dir)
{

	P1IE |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;	// Enable interrupt for bit 0-3
    if(u_dir == DOWN)
    {
        P1IES &= ~(SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4);	// The bits 0-3 are set with a low-high transition
    }
    else
    {
        P1IES |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;	// The bits 0-3 are set with a high-to-low transition
    }
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
    TA0CCTL0 &= ~CCIFG;

}

//GPIO port1 interrupt
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    switch (P1IFG)
    {
    case SENSOR1:
        intFlagGpio = LED1;
        break;
    
    case SENSOR2:
        intFlagGpio = LED2;
        break;

    case SENSOR3:
        intFlagGpio = LED3;
        break;

    case SENSOR4:
        intFlagGpio = LED4;
        break;
    default:
        break;
    }
    P1IFG &= ~ALL_BITS;
}

