/****************************************************************************
 * \file    Sar.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Start Aplication Routine (pre-appl) module for MSP430G2553
 ****************************************************************************/

#include <Gpio_Service.h>
#include <Icu_Service.h>
#include <Mcu_Service.h>

void SAR_v_startUp(void)
{
  MCUS_v_init();

  GPIOS_v_init();

  GPIOS_v_config(); // TODO remove it

  ICUS_v_init();
}
