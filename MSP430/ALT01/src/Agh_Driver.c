#include "Agh_Driver.h"
#include "Interrupt_User.h"
#include "Clock_User.h"


void AGH_v_startUpState(void)
{
    uint8_t index = 4;
    const uint8_t PORT1 = 1;
    uint8_t sensors[4] = {0, 0, 0, 0};
    uint16_t last = 0;
    uint8_t retVal = 0;

    while(index > 0)
    {
        switch (index)
        {
        case 4:
            sensors[3] = gpioReadBit(SENSOR4,PORT1);
            sensors[3] ^= SENSOR4;  //! invert valor because is inverted in HW
            if(sensors[3] == SENSOR4)
            {
                last = 1;
                P2OUT |= LED4;
            }
            index -= 1; 
            break;
        case 3:
            sensors[2] = gpioReadBit(SENSOR3, PORT1);
            sensors[2] ^= SENSOR3;                       //! invert valor because is inverted in HW
            if(last == 1 && sensors[2] == 0)
            {
                retVal |= SENSOR3;
            }
            if(sensors[2] == SENSOR3)
            {
                last = 1;
                P2OUT |= LED3;
            }
            index -= 1;
            break;
        case 2:
            sensors[1] = gpioReadBit(SENSOR2, PORT1);
            sensors[1] ^= SENSOR2;                       //! invert valor because is inverted in HW
            if(last == 1 && sensors[1] == 0)
            {
                retVal |= SENSOR2;
            }
            if(sensors[1] == SENSOR2)
            {
                last = 1;
                P2OUT |= LED2;
            }
            index -= 1;
            break;
        case 1:
            sensors[0] = gpioReadBit(SENSOR1, PORT1);
            sensors[0] ^= SENSOR1;                      //! invert valor because is inverted in HW
            if(last == 1 && sensors[0] == 0)
            {
                retVal |= SENSOR1;
            }
            if(sensors[0] == SENSOR1)
            {
                P2OUT |= LED1;
            }
            index -= 1;
            break;
        default:
            break;
        }
    }

    if(retVal != 0) // An error occurs
    {
        currentState = ERROR;
        u_error = retVal;
        u_errorType = ERROR_SENSOR_NOT_OK;
    }
    else
    {
        // If tank is empty
        if(sensors[0] == 0)
        {
            currentState = PUMPUP;
            INT_v_gpioIntEn(UP);
        }
        else
        {
            currentState = IDLE;
            INT_v_gpioIntEn(DOWN);
        }
        P2OUT |= LEDG;
    }
}

void AGH_v_errorState(void)
{
    switch (u_errorType)
    {
    case ERROR_SENSOR_NOT_OK:
        // clear Sensor LEDS 
        P2OUT &= ~LED1 & ~LED2 & ~LED3 & ~LED4;

        // Show LEDs indicators for this error
        P2OUT |= LEDG;
        P2OUT |= LEDR;
        u_errorType = ERROR_SENSOR_NOT_OK_TOGGLE;
        break;

    case ERROR_SENSOR_NOT_OK_TOGGLE:
        counterErrorToggle++;
        if(counterErrorToggle == MS_500)
        {
            INT_v_toggleTimerError(u_error);
        }
    default:
        break;
    }

}

void AGH_v_idleState(void)
{
    if(intFlagGpio != 0)
    {
        P2OUT &= ~(intFlagGpio);
        intFlagGpio = 0;
        if(intFlagGpio == SENSOR1)
        {
            currentState = PUMPUP;
            INT_v_gpioIntEn(UP);
        }
    }
}

void pumpUpState(void)
{
    // TODO set SSR output as 1

    // TODO CHECK if an error occurs

    // TODO go to IDLE STATE after interrrupt in Sensor 4 occurs 
}

void AGH_v_machineStates(void)
{
    switch (currentState)
    {
    case IDLE:
        AGH_v_idleState();
        break;
    case ERROR:
        AGH_v_errorState();
        break;
    case PUMPUP:
        break;  
    case STARTUP:
        AGH_v_startUpState();
        break;    
    default:
        break;
    }
}
