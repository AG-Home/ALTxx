/****************************************************************************
 * \file    MCU_User.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   MCU ECU layer for MSP430G2553
 ****************************************************************************/

#ifndef MCU_USER_H
#define MCU_USER_H

#include <Mcu_Types.h>

void MCUU_v_confDCO(t_Freq e_frequence);

void MCUU_v_confBCO2(t_Selm e_selm, t_Divm e_divm, t_Sels e_sels, t_Divs e_divs, t_Dcor e_dcor);

void MCUU_v_confControlTimerA0(t_Tassel e_tassel, t_Id e_id, t_Mc e_mc, t_Taclr e_taclr);

#endif
