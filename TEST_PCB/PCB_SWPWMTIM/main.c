#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"


void Delay(void)
{
    volatile uint32_t uint32Counter;
    for(uint32Counter=0;uint32Counter<200000;uint32Counter++)
    {

    }
}


/*******************Set Output PIN************************/
void SetOutPutLED(void)
{
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_3);
}

/*******************Set Input PIN************************/
void SetInputSwitch(void)
{
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//pull-up
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//pull-up
}



void Timer_init(void)
{

}


void Timer_pwmInit(void)
{

}


void main(void)
{
    SetOutPutLED();
    SetInputSwitch();

    while(1)
    {
        uint32_t pinVal1=0;
        uint32_t pinVal2=0;
        pinVal1=GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0);
        pinVal2=GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
        if((pinVal1&GPIO_PIN_0)==0)
        {
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,1);
        }
        else
        {
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);
        }
        //----------------------------------------------
        if((pinVal2&GPIO_PIN_4)==0)
        {
           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,1);
        }
        else
        {
           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
        }

    }

}




