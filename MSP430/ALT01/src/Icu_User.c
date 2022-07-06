/****************************************************************************
 * \file    Icu_User.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Interrupt Control Unit (ECU) for MSP430G2553
 ****************************************************************************/

#include <Icu_Driver.h>
#include <Icu_User.h>

void ICUU_v_enableGpioInt(t_Port e_port, uint8 u_channel)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      P1IE |= u_channel;
      break;
    case Port2:
      P2IE |= u_channel;
      break;
    default:
      break;
  }
}

void ICUU_v_disableGpioInt(t_Port e_port, uint8 u_channel)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      P1IE &= u_channel;
      break;
    case Port2:
      P2IE &= u_channel;
      break;
    default:
      break;
  }
}

void ICUU_v_setEdgeGpioInt(t_Port e_port, uint8 u_channel, t_EdgeSelect e_edgeType)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      if(e_edgeType == EdgeUp)
      {
        P1IES &= ~u_channel;
      } else {
        P1IES |= u_channel;
      }
      break;
    case Port2:
      if(e_edgeType == EdgeUp)
      {
        P2IES &= ~u_channel;
      } else {
        P2IES |= u_channel;
      }
      break;
    default:
      break;
  }
}

void ICUU_v_setGIESR(void)
{
  BIS_SR(GIE);
}

void ICUU_v_cleanGIESR(void)
{
  BIC_SR(GIE);
}