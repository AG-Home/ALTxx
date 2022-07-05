/****************************************************************************
 * \file    Gpio_Driver.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Gpio MCAL for MSP430G2553
 ****************************************************************************/
#ifndef GPIO_DRIVER
#define GPIO_DRIVER

#define REG_8BITS(address) *(unsigned char*) address ///< De-refenrece for 8bits register

// Registers for port 1
#define P1IN              REG_8BITS(0x20) ///< Port1 Input
#define P1OUT             REG_8BITS(0x21) ///< Port1 Output 
#define P1DIR             REG_8BITS(0x22) ///< Port1 Direction
#define P1PS1             REG_8BITS(0x26) ///< Port1 Port Select
#define P1PS2             REG_8BITS(0x41) ///< Port1 Port Select 2
#define P1RE              REG_8BITS(0x27) ///< Port1 Resistor Enable

// Registers for port 2
#define P2IN              REG_8BITS(0x28) ///< Port2 Input
#define P2OUT             REG_8BITS(0x29) ///< Port2 Output 
#define P2DIR             REG_8BITS(0x2A) ///< Port2 Direction
#define P2PS1             REG_8BITS(0x2E) ///< Port2 Port Select
#define P2PS2             REG_8BITS(0x42) ///< Port2 Port Select 2
#define P2RE              REG_8BITS(0x2F) ///< Port2 Resistor Enable

#endif
