#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/adc.h"



bool isAdcReadOK=false;


void Int_Adc(void)
{


    uint32_t AdcValues[4];
    uint32_t Temp;


    ADCIntClear(ADC0_BASE,1);
    ADCSequenceDataGet(ADC0_BASE,1,AdcValues);
    Temp=147.5-((75*(3.3)*AdcValues[3])/4096);
    isAdcReadOK=true;

}



void main(void)
{
    //��������� ������������(��������� ����. ����������� 1,������������  ��������� ���� �� �����. ��� ������� ������������, ����. �����,�������)
            SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);

            SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);//��� ���������� �� ��� 0

            //��������� ���(�����,���������� ����������)
            ADCHardwareOversampleConfigure(ADC0_BASE,64);
            //��������� ������������������ �������
            ADCSequenceDisable(ADC0_BASE,1);
            //��������� source trigger  � ��������� ���������� , � ���. �������
            ADCSequenceConfigure(ADC0_BASE,1,ADC_TRIGGER_PROCESSOR,0);
            //��������� ��� ��������� ������������������(�����,���.�������,���,�����.�����������.������|�� ��������� ����������|��������� ��� � �������)
            ADCSequenceStepConfigure(ADC0_BASE,1,0,ADC_CTL_CH0|ADC_CTL_IE|ADC_CTL_END);
            ADCSequenceStepConfigure(ADC0_BASE,1,1,ADC_CTL_CH1|ADC_CTL_IE|ADC_CTL_END);
            ADCSequenceStepConfigure(ADC0_BASE,1,2,ADC_CTL_CH2|ADC_CTL_IE|ADC_CTL_END);
            ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
            //���. ������� ������������������
            ADCSequenceEnable(ADC0_BASE,1);
            //���. ���������� ���
            ADCIntEnable(ADC0_BASE,1);
            //������������  ���������� ����������
            ADCIntRegister(ADC0_BASE,1,Int_Adc);
            IntEnable(INT_ADC0SS1);

    while(1)
    {
        ADCProcessorTrigger(ADC0_BASE,1);
        isAdcReadOK=false;
        while(!isAdcReadOK)
        {

        }

        SysCtlDelay(SysCtlClockGet()/6);
    }
}


