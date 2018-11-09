#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"

void Delay(void)
{
    volatile uint32_t uint32Counter;
    for(uint32Counter=0;uint32Counter<200000;uint32Counter++)
    {

    }
}


void main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);   // Включение тактирования
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  // включение тактирования порта F
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);//для инициализации порта F пина 1
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);//для инициализации порта F пина 1
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);//для инициализации порта F пина 1
    //GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_2);//инициализация пина на вход
    //GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

    while(1)
    {

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0xFF);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0xFF);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0xFF);

            Delay();
            Delay();
            Delay();
            Delay();
                        Delay();
                        Delay();
                        Delay();
                                    Delay();
                                    Delay();
                                    Delay();
                                                Delay();
                                                Delay();
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0xFF);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0xFF);
            Delay();
            Delay();
            Delay();
                        Delay();
                        Delay();
                        Delay();
                                    Delay();
                                    Delay();
                                    Delay();
                                                Delay();
                                                Delay();
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0xFF);
            Delay();
            Delay();
            Delay();
    }
}


