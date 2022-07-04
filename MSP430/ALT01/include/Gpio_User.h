/****************************************************************************
 * \file    Gpio_User.h
 * \version 1.0
 * \author  Marco Aguilar
 * \brief   GPIO ECU Abstraction layer
 ****************************************************************************/
#ifndef GPIO_USER
#define GPIO_USER

#include <Std_Types.h>

#define INPUT    (uint8)0x00u
#define ALL_BITS (uint8)0xFFu
#define LED1     (uint8)0x01u
#define LED2     (uint8)0x02u
#define LED3     (uint8)0x04u
#define LED4     (uint8)0x08u
#define SSR      (uint8)0x10u
#define LEDR     (uint8)0x20u
#define LEDG     (uint8)0x40u
#define BUZZR    (uint8)0x80u
#define SENSOR1  (uint8)0x01u
#define SENSOR2  (uint8)0x02u
#define SENSOR3  (uint8)0x04u
#define SENSOR4  (uint8)0x08u

typedef enum
{
  High = True,
  Low  = False
} t_GpioState;

void  GPIOU_v_init(void);

void  gpioConf(void);

uint8 gpioReadBit(uint8 u_bit, uint8 u_port);

/**
 *
 * GPIOU_u_readChannel
 * Read channel for each port
 *
 * \param [in] u_port:    Port 1 or 2 of MSP430g2553 \n
 *                        data_type  = uint8 (0-255) \n
 *                        resolution = 1 -> port 1, 2 -> port2
 * \param [in] u_channel: Bit of the port \n
 *                        data_type  = uint8 (0-255) \n
 *                        resolution = Bit0 to Bit7 \n
 *
 *  \return retValue: Return True or False
 */
uint8 GPIOU_u_readChannel(uint8 u_port, uint8 u_channel);

/**
 *
 * GPIOU_v_writeChannel
 * Read channel for each port
 *
 * \param [in] u_port:    Port 1 or 2 of MSP430g2553 \n
 *                        data_type  = uint8 (0-255) \n
 *                        resolution = 1 -> port 1, 2 -> port2
 * \param [in] u_channel: Bit of the port \n
 *                        data_type  = uint8 (0-255) \n
 *                        resolution = Bit0 to Bit7
 * \param [in] e_state:   State of bit to write \n
 *                        data_type  = t_GpioState (True / False) \n
 *                        resolution = True/False
 *
 */
void  GPIOU_v_writeChannel(uint8 u_port, uint8 u_channel, t_GpioState e_state);

#endif
