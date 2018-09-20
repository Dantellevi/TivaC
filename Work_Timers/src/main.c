//������ ������������ 16-���������� �������
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



//���� ������� ������������ ������� ����������
// ��������� ����������.
static volatile bool g_bIntFlag = false;



void Timer0BIntHandler(void)
{
    // ������� ����� ���������� �������
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    //���������� ����, ����������� �� ��, ��� ��������� ����������.
    g_bIntFlag = true;

}

/*
 *
 * ��������� Timer0B ��� 16-������ ����������� ������� � ����� ����������� ����� 1 ��.
 *
 *
 */

void main(void)
{


    //��������� ������������(��������� ����. ����������� 1,������������  ��������� ���� �� �����. ��� ������� ������������, ����. �����,�������)
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);
    //��� ������ ������� ���. ���������
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    //������������ �������(����� ������ �������,��� ������� � ���������� �������,������ � ���������� �������)
    TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_ONE_SHOT);
    //������� ������������
    TimerPrescaleSet (TIMER0_BASE, TIMER_A, 16);
    //Set the Timer0B load value to 1ms.���������� ������ �� ������� ����� �����������(1/FCu=6.25e-8,1ms/6.25e-8=16000)=>16000000/1000=16000
    TimerLoadSet(TIMER0_BASE,TIMER_B,SysCtlClockGet() / 1000);
    //
    // Enable processor interrupts.
    //
    IntMasterEnable();
    //
    // Configure the Timer0B interrupt for timer timeout.(����. ������ ������� ������� � ����� �)
    //
    TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    //
    // Enable the Timer0B interrupt on the processor (NVIC).
    //
    IntEnable(INT_TIMER0B);

    //���. ������
    TimerEnable(TIMER0_BASE,TIMER_B);


    while(1)
        {

        }
}
