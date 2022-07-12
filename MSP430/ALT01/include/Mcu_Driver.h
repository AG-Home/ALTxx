/****************************************************************************
 * \file    MCU_Driver.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Master Clock Unit for MSP430G2553
 ****************************************************************************/

#ifndef MCU_DRIVER_H
#define MCU_DRIVER_H

#define REG_8BITS(address)  *(unsigned char*)address    ///< De-reference for 8bits register
#define REG_16BITS(address) *(signed short int*)address ///< De-reference for 16bits register

// Basic Clock Module
#define DCOCTL  REG_8BITS(0x0056) ///< DCO control register
#define BCSCTL1 REG_8BITS(0x0057) ///< Basic clock system control 1
#define BCSCTL2 REG_8BITS(0x0058) ///< Basic clock system control 2
#define BCSCTL3 REG_8BITS(0x0053) ///< Basic clock system control 3

// Timer0_A3
#define TA0CTL   REG_16BITS(0x0160) ///< Timer0_A3 control
#define TA0CCTL0 REG_16BITS(0x0162) ///< Timer0_A3 capture/compare control 0
#define TA0CCTL1 REG_16BITS(0x0164) ///< Timer0_A3 capture/compare control 1
#define TA0CCTL2 REG_16BITS(0x0166) ///< Timer0_A3 capture/compare control 2
#define TA0R     REG_16BITS(0x0170) ///< Timer0_A3 counter
#define TA0CCR0  REG_16BITS(0x0172) ///< Timer0_A3 capture/compare 0
#define TA0CCR1  REG_16BITS(0x0174) ///< Timer0_A3 capture/compare 1
#define TA0CCR2  REG_16BITS(0x0176) ///< Timer0_A3 capture/compare 2

// Timer1_A3
#define TA1CTL   REG_16BITS(0x0180) ///< Timer1_A3 control
#define TA1CCTL0 REG_16BITS(0x0182) ///< Timer1_A3 capture/compare control 0
#define TA1CCTL1 REG_16BITS(0x0184) ///< Timer1_A3 capture/compare control 1
#define TA1CCTL2 REG_16BITS(0x0186) ///< Timer1_A3 capture/compare control 2
#define TA1R     REG_16BITS(0x0190) ///< Timer1_A3 counter
#define TA1CCR0  REG_16BITS(0x0192) ///< Timer1_A3 capture/compare 0
#define TA1CCR1  REG_16BITS(0x0194) ///< Timer1_A3 capture/compare 1
#define TA1CCR2  REG_16BITS(0x0196) ///< Timer1_A3 capture/compare 2

// Calibration Data
#define CALDCO_16MHZ REG_8BITS(0x10F8) ///< DCO 16MHz calibration
#define CALBC1_16MHZ REG_8BITS(0x10F9) ///< BC1 16MHz calibration
#define CALDCO_12MHZ REG_8BITS(0x10FA) ///< DCO 12MHz calibration
#define CALBC1_12MHZ REG_8BITS(0x10FB) ///< BC1 12MHz calibration
#define CALDCO_8MHZ  REG_8BITS(0x10FC) ///< DCO 8MHz calibration
#define CALBC1_8MHZ  REG_8BITS(0x10FD) ///< BC1 8MHz calibration
#define CALDCO_1MHZ  REG_8BITS(0x10FE) ///< DCO 1MHz calibration
#define CALBC1_1MHZ  REG_8BITS(0x10FF) ///< BC1 1MHz calibration

#endif
