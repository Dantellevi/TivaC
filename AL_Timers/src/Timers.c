#include "Timers.h"




/*********************������������� ������� ******************************/
void TIM_Init(TimerConfigDef *tim)
{
    switch(tim->NameTimer)
    {
        case TIMER0_BASE:
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
            break;
        }

        case TIMER1_BASE:
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
            break;
        }
        case TIMER2_BASE:
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
            break;
        }

        case TIMER3_BASE:
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
            break;
        }
        case TIMER4_BASE:
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);
            break;
        }
        case TIMER5_BASE:
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER5);
            break;
        }
    }

    TimerConfigure(tim->NameTimer,tim->Mode.COnfigReg);
}



/*********************���/���� ������� ******************************/
void TIM_ToggleStatus(TimerConfigDef *tim,bool sw)
{
    if(sw)
    {
        TimerEnable(tim->NameTimer,tim->Mode.param);
    }
    else if(!sw)
    {
        TimerDisable(tim->NameTimer,tim->Mode.param);
    }
}



/*********************���/���� ������� ******************************/
void ToggleInterrupt(TimerConfigDef *tim,bool sw)
{
    if(sw)
        {
            TimerEnable(tim->NameTimer,tim->Mode.par_Int);
        }
        else if(!sw)
        {
            TimerDisable(tim->NameTimer,tim->Mode.par_Int);
        }
}



/**********************������� ��������� ������������*****************/
void SetValuePresceler(TimerConfigDef *tim,uint32_t val)
{
    TimerPrescaleSet(tim->NameTimer,tim->Mode.param,val);
}


/*************************������� ������� ���������� �������*********/
void SetValueCount(TimerConfigDef *tim,uint32_t val)
{
    TimerLoadSet(tim->NameTimer,tim->Mode.param,val);
}


/******************���������� ���������� ������� 0**************************/
void Timer0BIntHandler(void)
{
    // ������� ����� ���������� �������
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);

}

























