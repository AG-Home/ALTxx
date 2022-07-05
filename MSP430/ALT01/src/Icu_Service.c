/****************************************************************************
 * \file    Icu_Service.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Interrupt Control Unit (ECU) for MSP430G2553 SERVICE
 ****************************************************************************/

#include <Icu_Service.h>
#include <Icu_User.h>

void ICUS_v_init(void)
{
  const uint8 allBits = 0xFFu;
  ICUU_v_disableGpioInt(Port1, allBits);
  ICUU_v_disableGpioInt(Port2, allBits);
}
