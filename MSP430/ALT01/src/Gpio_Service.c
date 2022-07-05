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