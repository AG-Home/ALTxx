/****************************************************************************
 * \file    Gpio_User.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   GPIO ECU Abstraction layer
 ****************************************************************************/

#include <Gpio_Driver.h>
#include <Gpio_User.h>

enum Port
{
  Port1 = 1,
  Port2
};

void GPIOU_v_init(void)
{
  // Reset All GPIO's
  // Set as Output to avoid unused pin issue
  P1DIR = ALL_BITS;
  P2DIR = ALL_BITS;
  P1OUT = 0;
  P2OUT = 0;
}

void gpioConf(void)
{
  //* set all P2 as output
  P2DIR = ALL_BITS;
  P2PS1 = 0;
  P2PS2 = 0;
  P2OUT = 0;

  //* set P1.0-P1.3 as input
  P1DIR &= ~SENSOR1;
  P1DIR &= ~SENSOR2;
  P1DIR &= ~SENSOR3;
  P1DIR &= ~SENSOR4;
  // Pullup/pulldown resistor disabled
  P1RE |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;
}

/// uint_t u_bit
/// for bit n u_bit = 2^n
/// ex
/// for bit 0 u_bit = 1
/// for bit 1 u_bit = 2
/// for bit 2 u_bit = 4
uint8 gpioReadBit(uint8 u_bit, uint8 u_port)
{
  uint8 retValue = 0;
  switch(u_port)
  {
    case 1:
      /* code */
      retValue = u_bit & P1IN;
      break;
    case 2:
      /* code */
      retValue = u_bit & P2IN;
      break;
    default:
      retValue = u_bit & P1IN;
      break;
  }

  return retValue;
}

uint8 GPIOU_u_readChannel(uint8 u_port, uint8 u_channel)
{
  uint8 retValue;

  // switch for selecting port
  switch(u_port)
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

void GPIOU_v_writeChannel(uint8 u_port, uint8 u_channel, t_GpioState e_state)
{
  // switch for selecting port
  switch(u_port)
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