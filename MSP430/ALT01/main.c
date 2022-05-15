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
	CLK_v_clockInit();
	gpioInit();
	gpioConf();
	CLK_v_timerAInit();

	currentState = STARTUP;

	INT_v_interruptEnable();
	INT_v_systemTimerEn();
	while(1)
	{
		if(systemCycle == 1)
		{
			AGH_v_machineStates();
			systemCycle = 0;
		}
	}

}

