#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"
#include "Agh_Driver.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer
	
	uint8_t errorVar;

	gpioInit();
	gpioConf();
	errorVar = startUpState();

	while(1);

	return 0;
}

