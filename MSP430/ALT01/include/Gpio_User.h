#ifndef GPIO_USER
#define GPIO_USER

#include <msp430g2553.h>
#include <stdint.h>

#define INPUT (uint8_t)0
#define ALL_BITS (uint8_t)0xFF
#define LED1 (uint8_t)BIT0
#define LED2 (uint8_t)BIT1
#define LED3 (uint8_t)BIT2
#define LED4 (uint8_t)BIT3
#define SSR (uint8_t)BIT4
#define LEDR (uint8_t)BIT5
#define LEDG (uint8_t)BIT6
#define BUZZR (uint8_t)BIT7
#define SENSOR1 (uint8_t)BIT0
#define SENSOR2 (uint8_t)BIT1
#define SENSOR3 (uint8_t)BIT2
#define SENSOR4 (uint8_t)BIT3

void gpioInit(void);

void gpioConf(void);

uint8_t gpioReadBit(uint8_t u_bit, uint8_t u_port);


#endif
