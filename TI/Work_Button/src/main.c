#include <stdint.h>
#include <stdbool.h>//�������� bool ��� ��
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"

/****************************������� ��������*****************************/
void Delay(void)
{
    volatile uint32_t uint32Counter;
    for(uint32Counter=0;uint32Counter<200000;uint32Counter++)
    {

    }
}

void main(void)
{
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);//��� ������������� ����� F ���� 1
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_2);//������������� ���� �� ����


    while(1)
    {
        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2)==0x02)
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0xFF);
        }
        else
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0);
        }
    }
}




