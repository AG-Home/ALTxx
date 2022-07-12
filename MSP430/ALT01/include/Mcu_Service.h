/****************************************************************************
 * \file    MCU_Service.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   MCU Service layer for MSP430G2553
 ****************************************************************************/

#ifndef MCU_SERVICE_H
#define MCU_SERVICE_H

/**
 *
 * MCUS_v_init
 * MCU initialization
 *
 */
void MCUS_v_init(void);

/**
 *
 * MCUS_v_gptConfig
 * General Purpouse Timer configuration
 *
 */
void MCUS_v_gptConfig(void);

#endif
