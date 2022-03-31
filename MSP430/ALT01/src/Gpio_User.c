#include "Gpio_User.h"

void gpioInit(void)
{
	//* Reset All GPIO's
	//* Set as Output to avoid unused pin issue
	P1DIR = ALL_BITS;
	P2DIR = ALL_BITS;
	P3DIR = ALL_BITS;
	P1OUT = 0;
	P2OUT = 0;
	P3OUT = 0;
}

void gpioConf(void)
{
	//* set all P2 as output
	P2DIR = ALL_BITS;
	P2OUT = 0;

	P1DIR &= ~SENSOR1;
	P1DIR &= ~SENSOR2;
	P1DIR &= ~SENSOR3;
	P1DIR &= ~SENSOR4;
	P1REN |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;
	P1IE |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;	//* Enable interrupt for bit 0-3
	P1IES |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;	//* The bits 0-3 are set with a high-to-low transition
	P1IFG &= ~ALL_BITS; //* clear interrupts
}

