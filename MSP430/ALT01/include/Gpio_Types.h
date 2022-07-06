/****************************************************************************
 * \file    Gpio_Types.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Data types based on GPIO module for MSP430G2553
 ****************************************************************************/

#ifndef GPIO_TYPES
#define GPIO_TYPES

#include <Std_Types.h>

typedef enum Port
{
  Port1 = 1,
  Port2
} t_Port;

typedef enum
{
  High = True,
  Low  = False
} t_ChannelState;

typedef enum
{
  Input  = 0x00u,
  Output = 0xFFu
} t_DirState;

typedef enum
{
  Gpio      = 0u,
  Primary   = 1u,
  Secondary = 2u
} t_FunctionSelect;

typedef enum
{
  PullUp   = 0,
  PullDown = 1
} t_ResistorType;

#endif
