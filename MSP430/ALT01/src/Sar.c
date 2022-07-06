/****************************************************************************
 * \file    Sar.c
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   Start Aplication Routine (pre-appl) module for MSP430G2553
 ****************************************************************************/

#include <Gpio_Service.h>
#include <Icu_Service.h>

void SAR_v_startUp(void)
{
    GPIOS_v_init();

    GPIOS_v_config();

    ICUS_v_init();
}

