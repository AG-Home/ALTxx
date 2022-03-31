#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"

int main(void)
{
	
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer
	gpioInit();
	gpioConf();

	while(1);

	return 0;
}

