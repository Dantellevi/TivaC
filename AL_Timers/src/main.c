#include "Main.h"

TimerConfigDef atim0;
TimerConfigDef atim1;


void AL_TIM(void)
{
    atim0.NameTimer=TIMER0_BASE;//работает с нулевым таймером
    atim0.Mode.NameMode=Half_Size_TIM;//половинный размер
    atim0.Mode.COnfigReg=(TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT_UP);//задание регистра
    atim0.Mode.param=TIMER_A;
    atim0.Mode.par_Int=TIMER_TIMB_TIMEOUT;
    TIM_Init(&atim0);
    //----------------------------------------------------------------------------
    atim1.NameTimer=TIMER1_BASE;//работаем с первым таймером
    atim1.Mode.NameMode=FULL_Size_TIM;//полный размер
    atim1.Mode.COnfigReg=TIMER_CFG_ONE_SHOT;//один отсчет
    atim1.Mode.param=TIMER_BOTH;
    TIM_Init(&atim1);

}


void main(void)
{
    //¬ключение тактировани€(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактировани€, внеш. кварц,частота)
        SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                           SYSCTL_XTAL_16MHZ);

    AL_TIM();
    //
   // Enable processor interrupts.
   //
    IntMasterEnable();
    ToggleInterrupt(&atim0,atim0.Mode.par_Int);
    TIM_ToggleStatus(&atim0,atim0.Mode.param);

    ToggleInterrupt(&atim1,atim1.Mode.par_Int);
    TIM_ToggleStatus(&atim1,atim1.Mode.param);



    while(1)
    {

    }

}
