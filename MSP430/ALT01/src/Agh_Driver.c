#include "Agh_Driver.h"


uint8_t startUpState(void)
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
            if(sensors[3] == SENSOR4)
            {
                last = 1;
            }
            index -= 1; 
            break;
        case 3:
            sensors[2] = gpioReadBit(SENSOR3, PORT1);
            if(last == 1 && sensors[2] == 0)
            {
                retVal |= SENSOR3;
            }
            if(sensors[2] == SENSOR3)
            {
                last = 1;
            }
            index -= 1;
            break;
        case 2:
            sensors[1] = gpioReadBit(SENSOR2, PORT1);
            if(last == 1 && sensors[1] == 0)
            {
                retVal |= SENSOR2;
            }
            if(sensors[1] == SENSOR2)
            {
                last = 1;
            }
            index -= 1;
            break;
        case 1:
            sensors[0] = gpioReadBit(SENSOR1, PORT1);
            if(last == 1 && sensors[0] == 0)
            {
                retVal |= SENSOR1;
            }
            index -= 1;
            break;
        default:
            break;
        }
    }

    return retVal;
}