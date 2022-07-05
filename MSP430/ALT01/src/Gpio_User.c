/****************************************************************************
 * \file    Gpio_User.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   GPIO ECU Abstraction layer
 ****************************************************************************/

#include <Gpio_Driver.h>
#include <Gpio_User.h>

uint8 GPIOU_u_readChannel(t_Port e_port, uint8 u_channel)
{
  uint8 retValue;

  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      if((u_channel & P1IN) == u_channel)
      {
        retValue = True; // u_channel is High
      } else
      {
        retValue = False; // u_channel is Low
      }
      break;
    case Port2:
      if((u_channel & P2IN) == u_channel)
      {
        retValue = True; // u_channel is High
      } else
      {
        retValue = False; // u_channel is Low
      }
      break;
    default:
      retValue = False;
      break;
  }

  return retValue;
}

void GPIOU_v_setChannelState(t_Port e_port, uint8 u_channel, t_ChannelState e_state)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      if(e_state == High)
      {
        P1OUT |= u_channel; // write 1 in u_channel
      } else
      {
        P1OUT &= ~u_channel; // write 0 in u_channel
      }
      break;
    case Port2:
      if(e_state == High)
      {
        P2OUT |= u_channel; // write 1 in u_channel
      } else
      {
        P2OUT &= ~u_channel; // write 0 in u_channel
      }
      break;
    default:
      // Do nothing
      break;
  }
}

void GPIOU_v_setChannelDir(t_Port e_port, uint8 u_channel, t_DirState e_dir)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      if(e_dir == Input)
      {
        P1DIR &= ~u_channel;
      } else
      {
        P1DIR |= u_channel;
      }
      break;
    case Port2:
      if(e_dir == Input)
      {
        P2DIR &= ~u_channel;
      } else
      {
        P2DIR |= u_channel;
      }
      break;
    default:
      // Do nothing
      break;
  }
}

// PxPS1 = 0 and PxPS2 = 0 -> I/O function is selected.
// PxPS1 = 1 and PxPS2 = 0 -> Primary peripheral module function is selected.
// PxPS1 = 1 and PxPS2 = 1 -> Secondary peripheral module function is selected.
void GPIOU_v_setChannelFunction(t_Port e_port, uint8 u_channel, t_FunctionSelect e_pinFunction)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      switch(e_pinFunction)
      {
        case Gpio:
          P1PS1 &= ~u_channel;
          P1PS2 &= ~u_channel;
          break;
        case Primary:
          P1PS1 |= u_channel;
          P1PS2 &= ~u_channel;
          break;
        case Secondary:
          P1PS1 |= u_channel;
          P1PS2 |= u_channel;
          break;
        default:
          break;
      }
      break;

    case Port2:
      switch(e_pinFunction)
      {
        case Gpio:
          P2PS1 &= ~u_channel;
          P2PS2 &= ~u_channel;
          break;
        case Primary:
          P2PS1 |= u_channel;
          P2PS2 &= ~u_channel;
          break;
        case Secondary:
          P2PS1 |= u_channel;
          P2PS2 |= u_channel;
          break;
        default:
          break;
      }
      break;

    default:
      // Do nothing
      break;
  }
}

void GPIOU_v_enableInternalRes(t_Port e_port, uint8 u_channel, t_ResistorType e_type)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      P1RE |= u_channel;
      if(e_type == PullUp)
      {
        P1OUT |= u_channel;
      } else
      {
        P1OUT &= u_channel;
      }
      break;

    case Port2:
      P2RE |= u_channel;
      if(e_type == PullUp)
      {
        P2OUT |= u_channel;
      } else
      {
        P2OUT &= u_channel;
      }
      break;

    default:
      // Do nothing
      break;
  }
}

void GPIOU_v_disableInternalRes(t_Port e_port, uint8 u_channel)
{
  // switch for selecting port
  switch(e_port)
  {
    case Port1:
      P1RE &= ~u_channel;
      break;

    case Port2:
      P2RE &= ~u_channel;
      break;

    default:
      // Do nothing
      break;
  }
}
