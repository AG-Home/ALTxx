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

/**
 *
 * ICUU_v_enableGpioInt
 * Enable GPIO interrupt
 *
 * \param [in] e_port:    Port 1 or 2 of MSP430g2553 \n
 *                        data_type  = t_Port (0-255) \n
 *                        resolution = 1 -> port 1, 2 -> port2
 * \param [in] u_channel: Bit of the port \n
 *                        data_type  = uint8 (0-255) \n
 *                        resolution = Bit0 to Bit7
 *
 */
void ICUU_v_enableGpioInt(t_Port e_port, uint8 u_channel);

/**
 *
 * ICUU_v_disableGpioInt
 * Disable GPIO interrupt
 *
 * \param [in] e_port:    Port 1 or 2 of MSP430g2553 \n
 *                        data_type  = t_Port (0-255) \n
 *                        resolution = 1 -> port 1, 2 -> port2
 * \param [in] u_channel: Bit of the port \n
 *                        data_type  = uint8 (0-255) \n
 *                        resolution = Bit0 to Bit7
 *
 */
void ICUU_v_disableGpioInt(t_Port e_port, uint8 u_channel);

/**
 *
 * ICUU_v_setEdgeGpioInt
 * Set if falling or rising edge
 *
 * \param [in] e_port:     Port 1 or 2 of MSP430g2553 \n
 *                         data_type  = t_Port (0-255) \n
 *                         resolution = 1 -> port 1, 2 -> port2
 * \param [in] u_channel:  Bit of the port \n
 *                         data_type  = uint8 (0-255) \n
 *                         resolution = Bit0 to Bit7
 * \param [in] e_edgeType: Edge type \n
 *                         data_type  = t_EdgeSelect \n
 *                         resolution = Falling / Rising edge
 *
 */
void ICUU_v_setEdgeGpioInt(t_Port e_port, uint8 u_channel, t_EdgeSelect e_edgeType);

/**
 *
 * ICUU_v_setGIESR
 * Set GIE bit into SR
 *
 */
void ICUU_v_setGIESR(void);

/**
 *
 * ICUU_v_setGIESR
 * Clean GIE bit into SR
 *
 */
void ICUU_v_cleanGIESR(void);

#endif
