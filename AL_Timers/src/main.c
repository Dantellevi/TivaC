#include "Main.h"





/***************************Общая функция инициализации*************************/
void AL_TIM(void)
{
    TimerConfigDef atim0;
    TimerConfigDef atim0b;
    TimerConfigDef atim1;
    TimerConfigDef atim2;


    /**************Инициализация таймера 0 с половинной шириной канал А**********************/
    atim0.NameTimer=TIMER0_BASE;//работает с нулевым таймером
    atim0.Mode.NameMode=Half_Size_TIM;//половинный размер
    atim0.Mode.COnfigReg=(TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT_UP);//задание регистра
    atim0.Mode.param=TIMER_A;
    atim0.Mode.par_Int=TIMER_TIMB_TIMEOUT;
    atim0.Mode.param_EnInt=INT_TIMER0A;
    TIM_Init(&atim0);
    /**************************************************************************/
    /**************Инициализация таймера 0 с половинной шириной канал В(шим)**********************/
    atim0b.NameTimer=TIMER0_BASE;//работает с нулевым таймером
    atim0b.Mode.NameMode=Half_Size_TIM;//половинный размер
    atim0b.Mode.COnfigReg=(TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);//задание регистра
    atim0b.Mode.param=TIMER_B;
    TIM_Init(&atim0b);
    /**************************************************************************/




    //----------------------------------------------------------------------------
    atim1.NameTimer=TIMER1_BASE;//работаем с первым таймером
    atim1.Mode.NameMode=FULL_Size_TIM;//полный размер
    atim1.Mode.COnfigReg=TIMER_CFG_RTC;//RTC
    atim1.Mode.param=TIMER_BOTH;
    atim1.Mode.par_Int=TIMER_RTC_MATCH;
    TIM_Init(&atim1);
    /************************Инициализация таймера 2 в режиме Capture*********/
    atim2.NameTimer=TIMER2_BASE;//работаем с первым таймером
    atim2.Mode.NameMode=Capture_TIM;//полный размер
    atim2.Mode.COnfigReg=(TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_CAP_COUNT);//режим захвата таймер2  канал А
    atim2.Mode.param=TIMER_A;
    atim2.Mode.par_Int=TIMER_CAPA_EVENT;
    atim2.Mode.param_EnInt=INT_TIMER2A;
    TIM_Init(&atim2);



    ToggleInterrupt(&atim0,true);
    RegisterInterrupt(&atim0);
    TIM_ToggleStatus(&atim0,true);

    ToggleInterrupt(&atim1,true);
    RegisterInterrupt(&atim1);
    TIM_ToggleStatus(&atim1,true);

    ToggleInterrupt(&atim2,true);
    RegisterInterrupt(&atim2);
    TIM_ToggleStatus(&atim2,true);

}


void main(void)
{
    //Включение тактирования(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактирования, внеш. кварц,частота)
        SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                           SYSCTL_XTAL_16MHZ);


    //
   // Enable processor interrupts.
   //
    IntMasterEnable();
    AL_TIM();





    while(1)
    {

    }

}
