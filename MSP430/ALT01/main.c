/****************************************************************************
 * \file    main.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   main
 ****************************************************************************/

#include <Agh_Driver.h>
#include <Clock_User.h>
#include <Gpio_User.h>
#include <Interrupt_User.h>
#include <msp430g2553.h>
#include <stdint.h>
#include <Gpio_Service.h>

/**
 *
 * main function where all is called
 *
 */
int main(void);

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD; //* stop watchdog timer

  // Initialization
  CLK_v_clockInit();
  GPIOS_v_init();
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
