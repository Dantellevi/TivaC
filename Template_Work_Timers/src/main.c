#include "Main.h"



void Timer0BIntHandler(void)
{
    // ������� ����� ���������� �������
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);


}






void main(void)
{

    //��������� ������������(��������� ����. ����������� 1,������������  ��������� ���� �� �����. ��� ������� ������������, ����. �����,�������)
      SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                           SYSCTL_XTAL_16MHZ);
        //��� ������ ������� ���. ���������
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
     //������������ �������(����� ������ ������� ��� ������� � ���������� �������,������ � ���������� �������)
    Timer_init(TIMER0_BASE,TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_ONE_SHOT);
    //���� ������� ������������
    SetPrescaler_TIM(TIMER0_BASE,TIMER_B, 16);
    //���� ������ ���������� �����
    //Set the Timer0B load value to 1ms.���������� ������ �� ������� ����� �����������(1/FCu=6.25e-8,1ms/6.25e-8=16000)=>16000000/1000=16000
    SetLoad_TIM(TIMER0_BASE,TIMER_B,SysCtlClockGet() / 1000);
    //
    // Enable processor interrupts.
    //
       IntMasterEnable();
       Innterupt_TIM(true,TIMER0_BASE,TIMER_TIMB_TIMEOUT);


    while(1)
    {

    }

}
