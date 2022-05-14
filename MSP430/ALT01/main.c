#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"
#include "Agh_Driver.h"
#include "Clock_User.h"
#include "Interrupt_User.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer

	uint8_t errorVar;

	// Initialization
	clockInit();
	gpioInit();
	gpioConf();
	timerAInit();
	interruptEnable();

	currentState = STARTUP;



	// errorVar = startUpState();

	// if(errorVar > 0)
	// {
	// 	errorTask(errorVar, ERROR_SENSOR_NOT_OK);
	// 	P2OUT |= BUZZR;
	// 	while (1)	// Wait for external reset 	
	// 	{
	// 		if(counter == 49)
	// 		{
	// 			toggleTimerError(errorVar);
	// 		}
	// 	}		
	// }


	while(1)
	{
		AGH_v_machineStates();
	}

	return 0;
}

