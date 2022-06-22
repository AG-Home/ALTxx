/**
 * @file main.c
 * @author My Self
 * @date 9 Sep 2012
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 */


#include "Agh_Driver.h"
#include "Clock_User.h"
#include "Gpio_User.h"
#include "Interrupt_User.h"
#include <msp430g2553.h>
#include <stdint.h>

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
