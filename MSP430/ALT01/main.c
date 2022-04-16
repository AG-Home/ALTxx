#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"
#include "Agh_Driver.h"
#include "Clock_User.h"
#include "Interrupt_User.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer

	clockInit();
	gpioInit();
	gpioConf();

	uint8_t errorVar;

	errorVar = startUpState();
	if(errorVar > 0)
	{
		errorTask(errorVar, ERROR_SENSOR_NOT_OK);
		P2OUT |= BUZZR;
		while (1);	// Wait for external reset 			
	}

	while(1);

	return 0;
}

