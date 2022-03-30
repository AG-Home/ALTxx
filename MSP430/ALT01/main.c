#include <msp430g2553.h>
#include <stdint.h>

#define INPUT (uint8_t)0
#define ALL_OUTPUT (uint8_t)0xFF

void gpioInit(void);

int main(void)
{
	
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer
	gpioInit();

	return 0;
}

void gpioInit(void)
{
	//* Reset All GPIO's
	//* Set as Output to avoid unused pin issue
	P1DIR = ALL_OUTPUT;
	P2DIR = ALL_OUTPUT;
	P3DIR = ALL_OUTPUT;
	P1OUT = 0;
	P2OUT = 0;
	P3OUT = 0;
}
