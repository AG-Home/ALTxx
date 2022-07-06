/****************************************************************************
 * \file    MCU_User.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   MCU ECU layer for MSP430G2553
 ****************************************************************************/

#ifndef MCU_USER_H
#define MCU_USER_H

#include <Mcu_Types.h>

/**
 *
 * MCUU_v_confDCO
 * set Frecuence for DCO CLK
 *
 * \param [in] e_frequence: Set frequence for DCO clk \n
 *                          data_type  = t_Freq  \n
 *                          resolution = Clk16Mhz/Clk12Mhz/Clk8Mhz/Clk1Mhz
 *
 */
void MCUU_v_confDCO(t_Freq e_frequence);

/**
 *
 * MCUU_v_confBCO2
 * Configure BCO2
 *
 * \param [in] e_selm: Set frequence for DCO clk \n
 *                     data_type  = t_Selm  \n
 *                     resolution = SelmDcoClk/SelmXt2Clk/SelmLFxt1Clk
 * \param [in] e_divm: Set frequence for DCO clk \n
 *                     data_type  = t_Divm  \n
 *                     resolution = DivmOne/DivmTwo/DivmFour/DivmEight
 * \param [in] e_sels: Set frequence for DCO clk \n
 *                     data_type  = t_Sels  \n
 *                     resolution = SelsDcoClk/SelsXt2Clk
 * \param [in] e_divs: Set frequence for DCO clk \n
 *                     data_type  = t_Divs  \n
 *                     resolution = DivsOne/DivsTwo/DivsFour/DivsEight
 * \param [in] e_dcor: Set frequence for DCO clk \n
 *                     data_type  = t_Dcor  \n
 *                     resolution = InternalRes/ExternalRes
 *
 */
void MCUU_v_confBCO2(t_Selm e_selm, t_Divm e_divm, t_Sels e_sels, t_Divs e_divs, t_Dcor e_dcor);

/**
 *
 * MCUU_v_confControlTimerA0
 * Configure TimerA
 *
 * \param [in] e_tassel: Set frequence for DCO clk \n
 *                       data_type  = t_Tassel  \n
 *                       resolution = TasselTAClk/TasselAClk/TasselSMClk/TasselINClk
 * \param [in] e_id:     Set frequence for DCO clk \n
 *                       data_type  = t_Id  \n
 *                       resolution = IdOne/IdTwo/IdFour/IdEight
 * \param [in] e_mc:     Set frequence for DCO clk \n
 *                       data_type  = t_Mc  \n
 *                       resolution = StopMode/UpMode/ContinuousMode/UpDownMode
 * \param [in] e_taclr:  Set frequence for DCO clk \n
 *                       data_type  = t_Taclr  \n
 *                       resolution = Taclrclear/Taclrset
 *
 */
void MCUU_v_confControlTimerA0(t_Tassel e_tassel, t_Id e_id, t_Mc e_mc, t_Taclr e_taclr);

#endif
