#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"

int main(void)
{
	
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer
	gpioInit();

	while(1);

	return 0;
}

