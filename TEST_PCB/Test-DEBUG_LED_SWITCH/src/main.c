#include "Main.h"



void Delay(void)
{
    volatile uint32_t uint32Counter;
    for(uint32Counter=0;uint32Counter<200000;uint32Counter++)
    {

    }
}


void SettingGPIO(void)
{
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1);//pin 1 out
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);//pin 2 out
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_3);//pin 3 out


}



void main(void)
{
    //set clock(del|used osciliator as selected|use an external crystal or oscillator|Freq)
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);


    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0xFF);
    }
}


