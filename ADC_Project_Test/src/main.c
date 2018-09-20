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
    //Включение тактирования(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактирования, внеш. кварц,частота)
            SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);

            SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);//вкл прерывания от АЦП 0

            //настройка АЦП(канал,количество усреднений)
            ADCHardwareOversampleConfigure(ADC0_BASE,64);
            //Отключаем последовательность выборок
            ADCSequenceDisable(ADC0_BASE,1);
            //настройка source trigger  и установка приоритета , и кол. выборок
            ADCSequenceConfigure(ADC0_BASE,1,ADC_TRIGGER_PROCESSOR,0);
            //Настройте шаг примерной последовательности(Канал,кол.выборок,шаг,внутр.температурн.датчик|по окончанию прерывания|последний шаг в выборке)
            ADCSequenceStepConfigure(ADC0_BASE,1,0,ADC_CTL_CH0|ADC_CTL_IE|ADC_CTL_END);
            ADCSequenceStepConfigure(ADC0_BASE,1,1,ADC_CTL_CH1|ADC_CTL_IE|ADC_CTL_END);
            ADCSequenceStepConfigure(ADC0_BASE,1,2,ADC_CTL_CH2|ADC_CTL_IE|ADC_CTL_END);
            ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
            //вкл. выборку последовательности
            ADCSequenceEnable(ADC0_BASE,1);
            //вкл. прерывания АЦП
            ADCIntEnable(ADC0_BASE,1);
            //регистрируем  обработчик прерываний
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


