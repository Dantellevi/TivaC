#include "Main.h"






void main(void)
{

    //Включение тактирования(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактирования, внеш. кварц,частота)
      SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                           SYSCTL_XTAL_16MHZ);
        //для работы таймера вкл. перифирию
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
     //Конфигурация таймера(режим работы таймера два таймера с половинной шириной,таймер с половинной шириной)
    Timer_init(TIMER0_BASE,TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_ONE_SHOT);
    //либо задание предделителя
    SetPrescaler_TIM(TIMER0_BASE,TIMER_B, 16);
    //либо задаем количество тиков
    //Set the Timer0B load value to 1ms.количество тактов до которых нужно досчитывать(1/FCu=6.25e-8,1ms/6.25e-8=16000)=>16000000/1000=16000
    SetLoad_TIM(TIMER0_BASE,TIMER_B,SysCtlClockGet() / 1000);
    //
    // Enable processor interrupts.
    //
       IntMasterEnable();
       Innterupt_TIM(true,TIMER0_BASE,TIMER_TIMB_TIMEOUT,INT_TIMER0B);
       //вкл. Таймер
       TimerEnable(TIMER0_BASE,TIMER_B);

    while(1)
    {

    }

}
