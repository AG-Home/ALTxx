/****************************************************************************
 * \file    Icu_User.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Interrupt Control Unit (ECU) for MSP430G2553
 ****************************************************************************/

#ifndef ICU_USER
#define ICU_USER

#include <Gpio_Types.h>
#include <Icu_Types.h>
#include <Std_Types.h>

void ICUU_v_enableGpioInt(t_Port e_port, uint8 u_channel);

void ICUU_v_disableGpioInt(t_Port e_port, uint8 u_channel);

void ICUU_v_setEdgeGpioInt(t_Port e_port, uint8 u_channel, t_EdgeSelect e_edgeType);

void ICUU_v_setGIESR(void);

void ICUU_v_cleanGIESR(void);

#endif
