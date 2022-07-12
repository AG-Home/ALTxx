/****************************************************************************
 * \file    MCU_Service.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   MCU Service layer for MSP430G2553
 ****************************************************************************/

#include <Mcu_Service.h>
#include <Mcu_Types.h>
#include <Mcu_User.h>

void MCUS_v_init(void)
{
  // configure DCO source clock to 1MHz
  MCUU_v_confDCO(Clk1Mhz);
}

void MCUS_v_gptConfig(void)
{
  const uint16 timerPeriod = 50000;     // 50ms 

  // configure System Counter
  // 1 tick -> 1uS
  MCUU_v_confControlTimerA0(TasselSMClk, IdOne, UpMode, Taclrclear);

  // 50000 ticks -> 50ms
  MCUU_v_setMaxTimerA0Counter(timerPeriod);
}
