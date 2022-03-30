#include "Gpio_User.h"

void gpioInit(void)
{
	//* Reset All GPIO's
	//* Set as Output to avoid unused pin issue
	// P1DIR = ALL_OUTPUT;
	// P2DIR = ALL_OUTPUT;
	// P3DIR = ALL_OUTPUT;
	// P1OUT = 0;
	// P2OUT = 0;
	// P3OUT = 0;

	P1DIR = BIT0;
	P1OUT = BIT0;
}

