#include "Timers.h"




/**********************Функция инициализации таймера для заданного режима**********/
/*
 * Параметры:
 *              Timer-адрес таймера,
 *              Mode- режим работы таймера
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




/**********************Функция вкл/откл. прерываний таймера**********/
/*
 * Параметры:
 *              en-флаг вкл/откл. прерываний,
 *              Timer-адрес таймера для работы с прерываниями
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 *
 *              ModeInt-Источник прерываний который будет вкл или выкл.
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
      if(en)//вкл. прерывания
      {
          TimerIntEnable(Timer, ModeInt);
      }
      else  //откл. прерывания
      {
          TimerIntDisable(Timer, ModeInt);
      }

      return TIM_OK;
    }
}



/*************************Функция задания предделителя частоты таймера***********************/
/*
 * Параметы:
 * Tim-адрес таймера
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * channel-индификатор одного из подтаймеров
 *              TIMER_A
 *              TIMER_B
 * value-значение предделителя
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







/*************************Функция задания количество тиков для прерывания***********************/
/*
 * Параметы:
 * Tim-адрес таймера
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * channel-индификатор одного из подтаймеров
 *              TIMER_A
 *              TIMER_B
 * value-значение тиков
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




/*==================================================2-Вариант==============================================*/


RESULT_TIM TIM_Initilize(uint8_t N_tim,uint8_t Mode,uint8_t channel,uint8_t HalfMode)
{
    /*
    (N_Tim!=TIM0||N_Tim!=TIM1||N_Tim!=TIM2||N_Tim!=TIM3||N_Tim!=TIM4||N_Tim!=TIM5)||(Mode)

    if()
    {
        return TIM_ERROR;
    }
    else
    {

        return TIM_OK;
    }
    */

    return TIM_OK;
}














