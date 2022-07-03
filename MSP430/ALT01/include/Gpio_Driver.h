/****************************************************************************
 * \file    Gpio_Driver.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Gpio MCAL for MSP430G2553
 ****************************************************************************/
#ifndef GPIO_DRIVER
#define GPIO_DRIVER

#define REG_8BITS(address) *(unsigned char* address) ///< De-refenrece for 8bits register

// Registers for port 1
#define P1_IN              REG_8BITS(0x20h) ///< Port1 Input
#define P1_OUT             REG_8BITS(0x21h) ///< Port1 Output 
#define P1_DIR             REG_8BITS(0x22h) ///< Port1 Direction
#define P1_IF              REG_8BITS(0x23h) ///< Port1 Interrupt Flag
#define P1_IES             REG_8BITS(0x24h) ///< Port1 Interrupt Edge Select
#define P1_IE              REG_8BITS(0x25h) ///< Port1 Interrupt Enable
#define P1_PS1             REG_8BITS(0x26h) ///< Port1 Port Select
#define P1_PS2             REG_8BITS(0x41h) ///< Port1 Port Select 2
#define P1_RE              REG_8BITS(0x27h) ///< Port1 Resistor Enable

// Registers for port 2
#define P2_IN              REG_8BITS(0x28h) ///< Port2 Input
#define P2_OUT             REG_8BITS(0x29h) ///< Port2 Output 
#define P2_DIR             REG_8BITS(0x2Ah) ///< Port2 Direction
#define P2_IF              REG_8BITS(0x2Bh) ///< Port2 Interrupt Flag
#define P2_IES             REG_8BITS(0x2Ch) ///< Port2 Interrupt Edge Select
#define P2_IE              REG_8BITS(0x2Dh) ///< Port2 Interrupt Enable
#define P2_PS1             REG_8BITS(0x2Eh) ///< Port2 Port Select
#define P2_PS2             REG_8BITS(0x42h) ///< Port2 Port Select 2
#define P2_RE              REG_8BITS(0x2Fh) ///< Port2 Resistor Enable

#endif
