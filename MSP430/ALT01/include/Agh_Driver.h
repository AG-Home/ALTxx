#ifndef AGH_DRIVER
#define AGH_DRIVER

#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"

#define ERROR_SENSOR_NOT_OK 0 

uint8_t startUpState(void);

/// 
/// uint8_t u_error -> content of the error
/// uint8_t u_errorType -> type of error:
///     - Sensor not working [0]
uint8_t errorTask(uint8_t u_error, uint8_t u_errorType);

void idleState(void);

#endif