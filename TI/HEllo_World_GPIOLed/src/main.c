#include <stdint.h>
#include <stdbool.h>//поддерка bool для си
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"



/****************************Функция задержки*****************************/
void Delay(void)
{
    volatile uint32_t uint32Counter;
    for(uint32Counter=0;uint32Counter<200000;uint32Counter++)
    {

    }
}


/*******************************Главная****************************/
void main(void)
{


    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);//для инициализации порта F пина 1 и 2 на выход
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0xFF);//первый пин High
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);//второй пин Low
        Delay();
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0xFF);//первый пин High
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);//второй пин Low
        Delay();


    }
}
