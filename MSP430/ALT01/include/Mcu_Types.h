/****************************************************************************
 * \file    MCU_Types.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Master Clock Unit for MSP430G2553
 ****************************************************************************/

#ifndef MCU_TYPES_H
#define MCU_TYPES_H

typedef enum
{
  Clk16Mhz = 0,
  Clk12Mhz,
  Clk8Mhz,
  Clk1Mhz
} t_Freq;

typedef enum
{
  SelmDcoClk   = 0b00000000,
  SelmXt2Clk   = 0b10000000,
  SelmLFxt1Clk = 0b11000000
} t_Selm;

typedef enum
{
  DivmOne   = 0b00000000,
  DivmTwo   = 0b00010000,
  DivmFour  = 0b00100000,
  DivmEight = 0b00110000
} t_Divm;

typedef enum
{
  SelsDcoClk = 0b00000000,
  SelsXt2Clk = 0b00001000
} t_Sels;

typedef enum
{
  DivsOne   = 0b00000000,
  DivsTwo   = 0b00000010,
  DivsFour  = 0b00000100,
  DivsEight = 0b00000110
} t_Divs;

typedef enum
{
  InternalRes = 0b00000000,
  ExternalRes = 0b00000001
} t_Dcor;

typedef enum
{
  TasselTAClk = 0b0000000000,
  TasselAClk  = 0b0100000000,
  TasselSMClk = 0b1000000000,
  TasselINClk = 0b1100000000
} t_Tassel;

typedef enum
{
  IdOne   = 0b0000000000,
  IdTwo   = 0b0001000000,
  IdFour  = 0b0010000000,
  IdEight = 0b0011000000
} t_Id;

typedef enum
{
  StopMode       = 0b0000000000,
  UpMode         = 0b0000010000,
  ContinuousMode = 0b0000100000,
  UpDownMode     = 0b0000110000
} t_Mc;

typedef enum
{
  Taclrclear = 0b0000000000,
  Taclrset   = 0b0000000100
} t_Taclr;

#endif
