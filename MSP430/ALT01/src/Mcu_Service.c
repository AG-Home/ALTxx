/****************************************************************************
 * \file    MCU_Service.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   MCU Service layer for MSP430G2553
 ****************************************************************************/

#include <Mcu_Service.h>
#include <Mcu_User.h>
#include <Mcu_Types.h>

void MCUS_v_init(void)
{
    MCUU_v_confDCO(Clk1Mhz);
}
