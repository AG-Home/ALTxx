/****************************************************************************
 * \file    MCU_User.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   MCU ECU layer for MSP430G2553
 ****************************************************************************/

#include <Mcu_Driver.h>
#include <Mcu_User.h>

void MCUU_v_confDCO(t_Freq e_frequence)
{
  switch(e_frequence)
  {
    case Clk16Mhz:
      DCOCTL  = CALDCO_16MHZ;
      BCSCTL1 = CALBC1_16MHZ;
      break;
    case Clk12Mhz:
      DCOCTL  = CALDCO_12MHZ;
      BCSCTL1 = CALBC1_12MHZ;
      break;
    case Clk8Mhz:
      DCOCTL  = CALDCO_8MHZ;
      BCSCTL1 = CALBC1_8MHZ;
      break;
    case Clk1Mhz:
      DCOCTL  = CALDCO_1MHZ;
      BCSCTL1 = CALBC1_1MHZ;
      break;

    default:
      break;
  }
}

void MCUU_v_confBCO2(t_Selm e_selm, t_Divm e_divm, t_Sels e_sels, t_Divs e_divs, t_Dcor e_dcor)
{
  BCSCTL2 = e_selm | e_divm | e_sels | e_divs | e_dcor;
}

void MCUU_v_confControlTimerA0(t_Tassel e_tassel, t_Id e_id, t_Mc e_mc, t_Taclr e_taclr)
{
  TA0CTL |= e_tassel | e_id | e_mc | e_taclr;
}
