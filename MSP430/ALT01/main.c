#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"
#include "Agh_Driver.h"
#include "Clock_User.h"
#include "Interrupt_User.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer

	// Initialization
	clockInit();
	gpioInit();
	gpioConf();
	timerAInit();

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
	interruptEnable();

	while(1)
	{
		AGH_v_machineStates();
	}

}

