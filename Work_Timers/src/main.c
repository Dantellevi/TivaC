//Пример демонстрации 16-разрядного таймера
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



//Флаг который регистрирует события прерывания
// произошло прерывание.
static volatile bool g_bIntFlag = false;



void Timer0BIntHandler(void)
{
    // Очистка флага прерывания таймера
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    //Установите флаг, указывающий на то, что произошло прерывание.
    g_bIntFlag = true;

}

/*
 *
 * Настройте Timer0B как 16-битный одноразовый счетчик с одним прерыванием через 1 мс.
 *
 *
 */

void main(void)
{


    //Включение тактирования(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактирования, внеш. кварц,частота)
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);
    //для работы таймера вкл. перифирию
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    //Конфигурация таймера(режим работы таймера,два таймера с половинной шириной,даймер с половинной шириной)
    TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_ONE_SHOT);
    //задание предделителя
    TimerPrescaleSet (TIMER0_BASE, TIMER_A, 16);
    //Set the Timer0B load value to 1ms.количество тактов до которых нужно досчитывать(1/FCu=6.25e-8,1ms/6.25e-8=16000)=>16000000/1000=16000
    TimerLoadSet(TIMER0_BASE,TIMER_B,SysCtlClockGet() / 1000);
    //
    // Enable processor interrupts.
    //
    IntMasterEnable();
    //
    // Configure the Timer0B interrupt for timer timeout.(полн. отсчет времени таймера о канал В)
    //
    TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    //
    // Enable the Timer0B interrupt on the processor (NVIC).
    //
    IntEnable(INT_TIMER0B);

    //вкл. Таймер
    TimerEnable(TIMER0_BASE,TIMER_B);


    while(1)
        {

        }
}
