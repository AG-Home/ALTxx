/****************************************************************************
 * \file    Icu_Driver.h
 * \version 1.1
 * \author  Marco Aguilar
 * \brief   Interrupt Control Unit for MSP430G2553
 ****************************************************************************/

#ifndef ICU_DRIVER
#define ICU_DRIVER

#include <intrinsics.h>

#define REG_8BITS(address) *(unsigned char*)address ///< De-reference for 8bits register

#define BIC_SR(x)          __bic_SR_register(x) ///< clear Bit in Status Register
#define BIS_SR(x)          __bis_SR_register(x) ///< set Bit in Status Register

#define GIE                (0x08) ///< General interrupt enable

// Registers for port 1
#define P1IF  REG_8BITS(0x23) ///< Port1 Interrupt Flag
#define P1IES REG_8BITS(0x24) ///< Port1 Interrupt Edge Select
#define P1IE  REG_8BITS(0x25) ///< Port1 Interrupt Enable

// Registers for port 2
#define P2IF  REG_8BITS(0x23) ///< Port2 Interrupt Flag
#define P2IES REG_8BITS(0x24) ///< Port2 Interrupt Edge Select
#define P2IE  REG_8BITS(0x25) ///< Port2 Interrupt Enable

// Registers TIMER
#define TA0IV REG_8BITS(0x012E) //< Timer0_A3 interrupt vector
#define TA1IV REG_8BITS(0x011E) //< Timer1_A3 interrupt vector

#endif
