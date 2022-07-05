/****************************************************************************
 * \file    Gpio_Service.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   GPIO Service layer
 ****************************************************************************/

#include <Gpio_Service.h>
#include <Gpio_User.h>

void GPIOS_v_init(void)
{
  const uint8 allBits = 0xFFu;

  GPIOU_v_setChannelDir(Port1, allBits, Output);
  GPIOU_v_setChannelDir(Port2, allBits, Output);
  GPIOU_v_setChannelState(Port1, allBits, Low);
  GPIOU_v_setChannelState(Port2, allBits, Low);
}

void GPIOS_v_config(void)
{
  const uint8 allBits = 0xFFu;

  // Set All channels of port 2 as output
  GPIOU_v_setChannelDir(Port2, allBits, Output);
  GPIOU_v_setChannelFunction(Port2, allBits, Gpio);
  GPIOU_v_setChannelState(Port2, allBits, Low);

  // set P1.0-P1.3 as input
  GPIOU_v_setChannelDir(Port1, (SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4), Input);
  // Pullup/pulldown resistor disabled
  GPIOU_v_disableInternalRes(Port1, (SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4));
}
