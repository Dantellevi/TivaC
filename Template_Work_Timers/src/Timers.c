#include "Timers.h"




/**********************������� ������������� ������� ��� ��������� ������**********/
/*
 * ���������:
 *              Timer-����� �������,
 *              Mode- ����� ������ �������
 */
RESULT_TIM Timer_init(uint32_t Timer,uint32_t Mode)
{
    switch(Timer)
    {
        case TIMER0_BASE:
        {
            TimerConfigure(Timer,Mode);
            break;
        }

        case TIMER1_BASE:
        {
          TimerConfigure(Timer,Mode);
          break;
        }

        case TIMER2_BASE:
        {
          TimerConfigure(Timer,Mode);
          break;
        }

        case TIMER3_BASE:
        {
          TimerConfigure(Timer,Mode);
          break;
        }
        case TIMER4_BASE:
        {
          TimerConfigure(Timer,Mode);
          break;
        }
        case TIMER5_BASE:
        {
          TimerConfigure(Timer,Mode);
          break;
        }
        default:
            return TIM_ERROR;



    }

    return TIM_OK;
}




/**********************������� ���/����. ���������� �������**********/
/*
 * ���������:
 *              en-���� ���/����. ����������,
 *              Timer-����� ������� ��� ������ � ������������
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 *
 *              ModeInt-�������� ���������� ������� ����� ��� ��� ����.
 *              TIMER_TIMB_DMA - Timer B uDMA complete
                TIMER_TIMA_DMA - Timer A uDMA complete
                TIMER_CAPB_EVENT - Capture B event interrupt
                TIMER_CAPB_MATCH - Capture B match interrupt
                TIMER_TIMB_TIMEOUT - Timer B timeout interrupt
                TIMER_RTC_MATCH - RTC interrupt mask
                TIMER_CAPA_EVENT - Capture A event interrupt
                TIMER_CAPA_MATCH - Capture A match interrupt
                TIMER_TIMA_TIMEOUT - Timer A timeout interrupt
 */
RESULT_TIM Innterupt_TIM(bool en,uint32_t Timer,uint32_t ModeInt)
{
    if(Timer!=TIMER0_BASE ||Timer!=TIMER1_BASE ||Timer!=TIMER2_BASE||Timer!=TIMER3_BASE||Timer!=TIMER4_BASE||Timer!=TIMER5_BASE)
    {
        return TIM_ERROR;
    }
    else
    {
      if(en)//���. ����������
      {
          TimerIntEnable(Timer, ModeInt);
      }
      else  //����. ����������
      {
          TimerIntDisable(Timer, ModeInt);
      }

      return TIM_OK;
    }
}



/*************************������� ������� ������������ ������� �������***********************/
/*
 * ��������:
 * Tim-����� �������
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * channel-����������� ������ �� �����������
 *              TIMER_A
 *              TIMER_B
 * value-�������� ������������
 *
 *
 */
RESULT_TIM SetPrescaler_TIM(uint32_t Tim,uint32_t channel,uint32_t value)
{
    if(Tim!=TIMER0_BASE ||Tim!=TIMER1_BASE ||Tim!=TIMER2_BASE||Tim!=TIMER3_BASE||Tim!=TIMER4_BASE||Tim!=TIMER5_BASE||channel!=TIMER_A||channel!=TIMER_B)
        {
            return TIM_ERROR;
        }

    else
        {
            TimerPrescaleSet (Tim, channel, 16);
            return TIM_OK;
        }
}







/*************************������� ������� ���������� ����� ��� ����������***********************/
/*
 * ��������:
 * Tim-����� �������
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * channel-����������� ������ �� �����������
 *              TIMER_A
 *              TIMER_B
 * value-�������� �����
 *
 *
 */
RESULT_TIM SetLoad_TIM(uint32_t Tim,uint32_t channel,uint32_t value)
{
    {
        if(Tim!=TIMER0_BASE ||Tim!=TIMER1_BASE ||Tim!=TIMER2_BASE||Tim!=TIMER3_BASE||Tim!=TIMER4_BASE||Tim!=TIMER5_BASE||channel!=TIMER_A||channel!=TIMER_B)
            {
                return TIM_ERROR;
            }

        else
            {
                TimerLoadSet (Tim, channel, value);
                return TIM_OK;
            }
    }
}














