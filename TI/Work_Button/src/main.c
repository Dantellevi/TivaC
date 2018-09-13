#include <stdint.h>
#include <stdbool.h>//�������� bool ��� ��
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"

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
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);   // ��������� ������������
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  // ��������� ������������ ����� F
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);//��� ������������� ����� F ���� 1
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_2);//������������� ���� �� ����
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

    while(1)
    {
        uint32_t pinVal=0;
        pinVal=GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2);//��������� �������� � ����� �� ���� 2


        if((pinVal&GPIO_PIN_2)==0x02)
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,2);
        }
        else
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0);
        }
    }
}




