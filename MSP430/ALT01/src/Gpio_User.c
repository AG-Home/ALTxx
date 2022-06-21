#include "Gpio_User.h"

void gpioInit(void)
{
  //* Reset All GPIO's
  //* Set as Output to avoid unused pin issue
  P1DIR = ALL_BITS;
  P2DIR = ALL_BITS;
  P3DIR = ALL_BITS;
  P1OUT = 0;
  P2OUT = 0;
  P3OUT = 0;
}

void gpioConf(void)
{
  //* set all P2 as output
  P2DIR  = ALL_BITS;
  P2SEL  = 0;
  P2SEL2 = 0;
  P2OUT  = 0;

  //* set P1.0-P1.3 as input
  P1DIR &= ~SENSOR1;
  P1DIR &= ~SENSOR2;
  P1DIR &= ~SENSOR3;
  P1DIR &= ~SENSOR4;
  // Pullup/pulldown resistor disabled
  P1REN |= SENSOR1 | SENSOR2 | SENSOR3 | SENSOR4;
}

/// uint_t u_bit
/// for bit n u_bit = 2^n
/// ex
/// for bit 0 u_bit = 1
/// for bit 1 u_bit = 2
/// for bit 2 u_bit = 4
uint8_t gpioReadBit(uint8_t u_bit, uint8_t u_port)
{
  uint8_t retValue = 0;
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
    case 3:
      /* code */
      retValue = u_bit & P3IN;
      break;
    default:
      retValue = u_bit & P1IN;
      break;
  }

  return retValue;
}
