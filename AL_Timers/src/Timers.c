#include "Timers.h"



/******************���������� ���������� ������� 0**************************/
void Timer0BIntHandler(void)
{
    // ������� ����� ���������� �������
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_DMA);
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_DMA);
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_MATCH);
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_MATCH);
    TimerIntClear(TIMER0_BASE, TIMER_RTC_MATCH);
    TimerIntClear(TIMER0_BASE, TIMER_CAPA_EVENT);
    TimerIntClear(TIMER0_BASE, TIMER_CAPB_EVENT);
    TimerIntClear(TIMER0_BASE, TIMER_CAPA_MATCH);
    TimerIntClear(TIMER0_BASE, TIMER_CAPB_MATCH);

}

/******************���������� ���������� ������� 0**************************/
void Timer1BIntHandler(void)
{
    /// ������� ����� ���������� �������
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
    TimerIntClear(TIMER1_BASE, TIMER_TIMB_TIMEOUT);
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_DMA);
    TimerIntClear(TIMER1_BASE, TIMER_TIMB_DMA);
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_MATCH);
    TimerIntClear(TIMER1_BASE, TIMER_TIMB_MATCH);
    TimerIntClear(TIMER1_BASE, TIMER_RTC_MATCH);
    TimerIntClear(TIMER1_BASE, TIMER_CAPA_EVENT);
    TimerIntClear(TIMER1_BASE, TIMER_CAPB_EVENT);
    TimerIntClear(TIMER1_BASE, TIMER_CAPA_MATCH);
    TimerIntClear(TIMER1_BASE, TIMER_CAPB_MATCH);



}


/******************���������� ���������� ������� 0**************************/
void Timer2BIntHandler(void)
{
    // ������� ����� ���������� �������
    // ������� ����� ���������� �������
        TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
        TimerIntClear(TIMER2_BASE, TIMER_TIMB_TIMEOUT);
        TimerIntClear(TIMER2_BASE, TIMER_TIMA_DMA);
        TimerIntClear(TIMER2_BASE, TIMER_TIMB_DMA);
        TimerIntClear(TIMER2_BASE, TIMER_TIMA_MATCH);
        TimerIntClear(TIMER2_BASE, TIMER_TIMB_MATCH);
        TimerIntClear(TIMER2_BASE, TIMER_RTC_MATCH);
        TimerIntClear(TIMER2_BASE, TIMER_CAPA_EVENT);
        TimerIntClear(TIMER2_BASE, TIMER_CAPB_EVENT);
        TimerIntClear(TIMER2_BASE, TIMER_CAPA_MATCH);
        TimerIntClear(TIMER2_BASE, TIMER_CAPB_MATCH);



}


/******************���������� ���������� ������� 0**************************/
void Timer3BIntHandler(void)
{
    // ������� ����� ���������� �������
    // ������� ����� ���������� �������
        TimerIntClear(TIMER3_BASE, TIMER_TIMA_TIMEOUT);
        TimerIntClear(TIMER3_BASE, TIMER_TIMB_TIMEOUT);
        TimerIntClear(TIMER3_BASE, TIMER_TIMA_DMA);
        TimerIntClear(TIMER3_BASE, TIMER_TIMB_DMA);
        TimerIntClear(TIMER3_BASE, TIMER_TIMA_MATCH);
        TimerIntClear(TIMER3_BASE, TIMER_TIMB_MATCH);
        TimerIntClear(TIMER3_BASE, TIMER_RTC_MATCH);
        TimerIntClear(TIMER3_BASE, TIMER_CAPA_EVENT);
        TimerIntClear(TIMER3_BASE, TIMER_CAPB_EVENT);
        TimerIntClear(TIMER3_BASE, TIMER_CAPA_MATCH);
        TimerIntClear(TIMER3_BASE, TIMER_CAPB_MATCH);



}


/******************���������� ���������� ������� 0**************************/
void Timer4BIntHandler(void)
{
    // ������� ����� ���������� �������
    // ������� ����� ���������� �������
        TimerIntClear(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
        TimerIntClear(TIMER4_BASE, TIMER_TIMB_TIMEOUT);
        TimerIntClear(TIMER4_BASE, TIMER_TIMA_DMA);
        TimerIntClear(TIMER4_BASE, TIMER_TIMB_DMA);
        TimerIntClear(TIMER4_BASE, TIMER_TIMA_MATCH);
        TimerIntClear(TIMER4_BASE, TIMER_TIMB_MATCH);
        TimerIntClear(TIMER4_BASE, TIMER_RTC_MATCH);
        TimerIntClear(TIMER4_BASE, TIMER_CAPA_EVENT);
        TimerIntClear(TIMER4_BASE, TIMER_CAPB_EVENT);
        TimerIntClear(TIMER4_BASE, TIMER_CAPA_MATCH);
        TimerIntClear(TIMER4_BASE, TIMER_CAPB_MATCH);



}


/******************���������� ���������� ������� 0**************************/
void Timer5BIntHandler(void)
{
    // ������� ����� ���������� �������
    // ������� ����� ���������� �������
        TimerIntClear(TIMER5_BASE, TIMER_TIMA_TIMEOUT);
        TimerIntClear(TIMER5_BASE, TIMER_TIMB_TIMEOUT);
        TimerIntClear(TIMER5_BASE, TIMER_TIMA_DMA);
        TimerIntClear(TIMER5_BASE, TIMER_TIMB_DMA);
        TimerIntClear(TIMER5_BASE, TIMER_TIMA_MATCH);
        TimerIntClear(TIMER5_BASE, TIMER_TIMB_MATCH);
        TimerIntClear(TIMER5_BASE, TIMER_RTC_MATCH);
        TimerIntClear(TIMER5_BASE, TIMER_CAPA_EVENT);
        TimerIntClear(TIMER5_BASE, TIMER_CAPB_EVENT);
        TimerIntClear(TIMER5_BASE, TIMER_CAPA_MATCH);
        TimerIntClear(TIMER5_BASE, TIMER_CAPB_MATCH);



}





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
/*
 *
 *
 *
 *
 *
 */
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
/*
 *
 * ��������� :
 *  tim-��������� � ��������� �����������  �������
 *  sw-���� ���������� �� ��������� ���./����.
 *
 */
void ToggleInterrupt(TimerConfigDef *tim,bool sw)
{
    if(sw)
        {
            TimerIntEnable(tim->NameTimer, tim->Mode.par_Int);
            IntEnable(tim->Mode.param_EnInt);
        }
        else if(!sw)
        {
            TimerIntDisable(tim->NameTimer, tim->Mode.par_Int);
            IntDisable(tim->Mode.param_EnInt);
        }
}



/**********************������� ��������� ������������*****************/
/*
 *
 *  ��������� :
 *  tim-��������� � ��������� �����������  �������
 *  val-�������� ��� ������������
 *
 *
 */
void SetValuePresceler(TimerConfigDef *tim,uint32_t val)
{
    TimerPrescaleSet(tim->NameTimer,tim->Mode.param,val);
}


/*************************������� ������� ���������� �������*********/
/*
 *
 *  *  ��������� :
 *  tim-��������� � ��������� �����������  �������
 *  val-�������� �������� �������
 *
 *
 */
void SetValueCount(TimerConfigDef *tim,uint32_t val)
{
    TimerLoadSet(tim->NameTimer,tim->Mode.param,val);
}


/************************������� ����������� ����������************/
/*
 *
 * ���������:
 *
 * tim-��������� � ��������� �����������  �������
 *
 *
 *
 */
void RegisterInterrupt(TimerConfigDef *tim)
{

    switch(tim->NameTimer)
    {
        case TIMER0_BASE:
        {
            TimerIntRegister (tim->NameTimer, tim->Mode.param, Timer0BIntHandler);
            break;
        }

        case TIMER1_BASE:
       {
           TimerIntRegister (tim->NameTimer, tim->Mode.param, Timer1BIntHandler);
            break;
       }

        case TIMER2_BASE:
         {
             TimerIntRegister (tim->NameTimer, tim->Mode.param, Timer2BIntHandler);
            break;
         }

        case TIMER3_BASE:
         {
             TimerIntRegister (tim->NameTimer, tim->Mode.param, Timer3BIntHandler);
            break;
         }

        case TIMER4_BASE:
         {
             TimerIntRegister (tim->NameTimer, tim->Mode.param, Timer4BIntHandler);
            break;
         }

        case TIMER5_BASE:
          {
              TimerIntRegister (tim->NameTimer, tim->Mode.param, Timer5BIntHandler);
             break;
          }
    }

}



/*****************************������� ��������� �������***********************************/
/*
 * ���������:
 * nameTIM-
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * Mode-
 *              TIMER_CFG_ONE_SHOT-����� �������������� ������ ������� � ����� ��������
                TIMER_CFG_ONE_SHOT_UP- ����� �������������� ������ �������  � ��������� � ���� ������ ���� � ����� ��������
                TIMER_CFG_PERIODIC- �������������� ������������� ������
                TIMER_CFG_PERIODIC_UP- �������������� ������������� ������ � ��������� �����
                TIMER_CFG_RTC-������������ ����� ��������� �������
                TIMER_CFG_SPLIT_PAIR- ��� ������� �� �������� ������ ��������(�������� ������ � � ������ �)
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                �������������� ������ ��� ��������:
                TIMER_CFG_A_ONE_SHOT-���. ����� ������� � ���������� ������� ������ �
                IMER_CFG_A_ONE_SHOT_UP- ���. ����� ������� � ���������� ������� ������ �
                                                                         � ��������� �����
                TIMER_CFG_A_PERIODIC-������������� ������ � ���������� �������
                TIMER_CFG_A_PERIODIC_UP- ������������� ������ � ���������� ������� � ��������� �����
                TIMER_CFG_A_CAP_COUNT- ����� ������� � ���������� ������� � ��������
                TIMER_CFG_A_CAP_COUNT_UP- ����� ������� � ���������� ������� � �������� � ���������
                TIMER_CFG_A_CAP_TIME-������ ������� � ������ ���������� ������
                TIMER_CFG_A_CAP_TIME_UP- ������ ������� � ������ ���������� ������ � ��������� �����
                TIMER_CFG_A_PWM-��� ������ �
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                �������������� ������������ ��� ������� � ������ ���������� ������(������ A):
                TIMER_CFG_A_ACT_TOINTD - ��������� ����-��� ���������� ������� A.
                TIMER_CFG_A_ACT_NONE � ����������� ��� �������� ������� �.
                TIMER_CFG_A_ACT_TOGGLE � ������������ CCP ������� �� �������� ������� �
                TIMER_CFG_A_ACT_SETTO � ���������� CCP �� �������� ������� �.
                TIMER_CFG_A_ACT_CLRTO � �������� CCP ������� �� �������� ������� �.
                TIMER_CFG_A_ACT_SETTOGTO � ��������� ���������� �������� � ������� CCP � ����� ����������� ��� �� ������� ������� �.
                TIMER_CFG_A_ACT_CLRTOGTO - ���������� �������� CCP, � ����� ����������� ��� �� ����-���
                ������� A
                .TIMER_CFG_A_ACT_SETCLRTO - ���������� ���������� CCP, � ����� �������� ���
                ������ A
                TIMER_CFG_A_ACT_CLRSETTO - ���������� �������� CCP, � ����� ���������� ��� �� ����-���
                ������ A
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                �������������� ������������ ��� ������� � ������ ���������� ������(������ B):

                TIMER_CFG_B_ACT_TOINTD - ��������� ����-��� ���������� ������� B.
                TIMER_CFG_B_ACT_NONE � ����������� ��� �������� ������� B.
                TIMER_CFG_B_ACT_TOGGLE � ������������ CCP ������� �� �������� ������� B
                TIMER_CFG_B_ACT_SETTO � ���������� CCP �� �������� ������� B.
                TIMER_CFG_B_ACT_CLRTO � �������� CCP ������� �� �������� ������� B.
                TIMER_CFG_B_ACT_SETTOGTO � ��������� ���������� �������� � ������� CCP � ����� ����������� ��� �� ������� ������� B.
                TIMER_CFG_B_ACT_CLRTOGTO - ���������� �������� CCP, � ����� ����������� ��� �� ����-���
                ������� B
                .TIMER_CFG_B_ACT_SETCLRTO - ���������� ���������� CCP, � ����� �������� ��� ������ B
                TIMER_CFG_B_ACT_CLRSETTO - ���������� �������� CCP, � ����� ���������� ��� �� ����-���
                ������ B

   specfies-
                TIMER_A
 *              TIMER_B
 *              TIMER_BOTH
 *
 * sp_IE-
 *              TIMER_TIMB_DMA - Timer B uDMA complete
                TIMER_TIMA_DMA - Timer A uDMA complete
                TIMER_CAPB_EVENT - Capture B event interrupt
                TIMER_CAPB_MATCH - Capture B match interrupt
                TIMER_TIMB_TIMEOUT - Timer B timeout interrupt
                TIMER_RTC_MATCH - RTC interrupt mask
                TIMER_CAPA_EVENT - Capture A event interrupt
                TIMER_CAPA_MATCH - Capture A match interrupt
                TIMER_TIMA_TIMEOUT - Timer A timeout interrupt
    G_I-        ���������� ����������
                #define INT_TIMER0B             INT_CONCAT(INT_TIMER0B_, INT_DEVICE_CLASS)
                #define INT_TIMER1A             INT_CONCAT(INT_TIMER1A_, INT_DEVICE_CLASS)
                #define INT_TIMER1B             INT_CONCAT(INT_TIMER1B_, INT_DEVICE_CLASS)
                #define INT_TIMER2A             INT_CONCAT(INT_TIMER2A_, INT_DEVICE_CLASS)
                #define INT_TIMER2B             INT_CONCAT(INT_TIMER2B_, INT_DEVICE_CLASS)
                #define INT_TIMER3A             INT_CONCAT(INT_TIMER3A_, INT_DEVICE_CLASS)
                #define INT_TIMER3B             INT_CONCAT(INT_TIMER3B_, INT_DEVICE_CLASS)
                #define INT_TIMER4A             INT_CONCAT(INT_TIMER4A_, INT_DEVICE_CLASS)
                #define INT_TIMER4B             INT_CONCAT(INT_TIMER4B_, INT_DEVICE_CLASS)
                #define INT_TIMER5A             INT_CONCAT(INT_TIMER5A_, INT_DEVICE_CLASS)
                #define INT_TIMER5B             INT_CONCAT(INT_TIMER5B_, INT_DEVICE_CLASS)
                #define INT_TIMER6A             INT_CONCAT(INT_TIMER6A_, INT_DEVICE_CLASS)
                #define INT_TIMER6B             INT_CONCAT(INT_TIMER6B_, INT_DEVICE_CLASS)
                #define INT_TIMER7A             INT_CONCAT(INT_TIMER7A_, INT_DEVICE_CLASS)
                #define INT_TIMER7B             INT_CONCAT(INT_TIMER7B_, INT_DEVICE_CLASS)

       hT-
                   ��������� ��������� ����� ��������� ��� ������ � ��������� ������� ����������,���/����. ������� � ��.

 *
 *
 *
 *
 */

RESULT_TIMDef Timer_Config(uint32_t nameTIM,uint32_t Mode,uint32_t specfies,uint32_t sp_IE,uint32_t G_I,TimerConfigDef *hT)
{
    TimerConfigDef htim;

    if(nameTIM!=TIMER0_BASE||nameTIM!=TIMER1_BASE||nameTIM!=TIMER2_BASE
            ||nameTIM!=TIMER3_BASE ||nameTIM!=TIMER4_BASE||nameTIM!=TIMER5_BASE)
    {

        return TIM_ERROR;
    }
    else
    {   htim.NameTimer=nameTIM;
        htim.Mode.COnfigReg=Mode;
        htim.Mode.param=specfies;
        htim.Mode.par_Int=sp_IE;
        htim.Mode.param_EnInt=G_I;
        hT=&htim;
        TIM_Init(hT);
        RegisterInterrupt(hT);

        return TIM_OK;
    }


}

































