#ifndef AGH_DRIVER
#define AGH_DRIVER

#pragma once

#include <msp430g2553.h>
#include <stdint.h>
#include "Gpio_User.h"

#define ERROR_SENSOR_NOT_OK 0 
#define ERROR_SENSOR_NOT_OK_TOGGLE 1 

#define UP 0 
#define DOWN 1 

#define PUMP_ON 0
#define PUMP_IDLE 1
#define PUMP_OFF 2

uint8_t currentState;
uint8_t pumpUpStateType;
static uint8_t errorCounterTimer = 0;
static uint8_t u_error = 0;
static uint8_t u_errorType = 0;
uint8_t intFlagGpio;

enum STATE
{
    IDLE = 0,
    ERROR = 1,
    PUMPUP = 2,
    STARTUP = 3
};

void AGH_v_startUpState(void);

/// 
/// uint8_t u_error -> content of the error
/// uint8_t u_errorType -> type of error:
///     - Sensor not working [0]
void AGH_v_errorState(void);


void AGH_v_idleState(void);

void AGH_v_pumpUpState(void);

void AGH_v_machineStates(void);

#endif