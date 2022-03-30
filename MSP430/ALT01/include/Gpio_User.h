#ifndef GPIO_USER
#define GPIO_USER

#include <msp430g2553.h>
#include <stdint.h>

#define INPUT (uint8_t)0
#define ALL_OUTPUT (uint8_t)0xFF

void gpioInit(void);



#endif