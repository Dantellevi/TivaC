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

//flag interrupt handler
static volatile bool g_bIntFlag = false;


//handler Interrupt
void Timer0Isr(void)
{
    // Очистка флага прерывания таймера
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    //Toogle GPIO BITs

}



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



/*********************Config Timer**************************************/
void Timer_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    //Config(name_Timer,(configBits)(две половины длины таймера|половина длины таймера регистр B))
    TimerConfigure(TIMER0_BASE,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_ONE_SHOT);
    //задание предделителя
    TimerPrescaleSet(TIMER0_BASE,TIMER_B,16000);
    //задаем до какого числа будет считать таймер
    TimerLoadSet(TIMER0_BASE,TIMER_B,1000);
    //register Interrupt
    TimerIntRegister(TIMER0_BASE,TIMER_B,Timer0Isr);
    //вкл. прерываний таймера
    TimerIntEnable(TIMER0_BASE,TIMER_TIMB_TIMEOUT);
    IntEnable(INT_TIMER0B);
    //вкл. Таймер
    TimerEnable(TIMER0_BASE,TIMER_B);
}



void Timer_pwmInit(void)
{

}


void main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
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




