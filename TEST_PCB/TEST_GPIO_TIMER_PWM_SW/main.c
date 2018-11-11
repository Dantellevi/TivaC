#include <stdbool.h>
#include <stdint.h>
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"


void Delay(void)
{
    volatile uint32_t uint32Counter;
       for(uint32Counter=0;uint32Counter<200000;uint32Counter++)
       {

       }
}


void Setting_GPIO_OUT_LED(void)
{
    //GPIOPinTypeGPIOOutput(GPIOF_BASE,);
}



void main(void)
{
    while(1)
    {

    }
}



