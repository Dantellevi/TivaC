#include "Timers.h"



/******************Обработчик прерываний Таймер0**************************/
void Timer0BIntHandler(void)
{

        // Очистка флага прерывания таймера
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


/******************Обработчик прерываний Таймер1**************************/
void Timer1BIntHandler(void)
{
    // Очистка флага прерывания таймера
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

/******************Обработчик прерываний Таймер2**************************/
void Timer2BIntHandler(void)
{
    // Очистка флага прерывания таймера
    // Очистка флага прерывания таймера
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


/******************Обработчик прерываний Таймер3**************************/
void Timer3BIntHandler(void)
{
    // Очистка флага прерывания таймера
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


/******************Обработчик прерываний Таймер3**************************/
void Timer4BIntHandler(void)
{
    // Очистка флага прерывания таймера
    // Очистка флага прерывания таймера
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


/******************Обработчик прерываний Таймер3**************************/
void Timer5BIntHandler(void)
{
    // Очистка флага прерывания таймера
    // Очистка флага прерывания таймера
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
RESULT_TIM Innterupt_TIM(bool en,uint32_t Timer,uint32_t ModeInt,uint32_t vectorInterrupt)
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
          IntEnable(vectorInterrupt);
      }
      else  //откл. прерывания
      {
          TimerIntDisable(Timer, ModeInt);
          IntDisable(vectorInterrupt);
      }

      return TIM_OK;
    }
}


/************************Регистрация обработчика события********************/
/*
 * * Параметы:
 * Tim-адрес таймера
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * RegisrationIntHandler(TIMER0_BASE)
 *
 */
RESULT_TIM RegisrationIntHandler(uint32_t Timer,uint32_t channel)
{
    if(Timer!=TIMER0_BASE ||Timer!=TIMER1_BASE ||Timer!=TIMER2_BASE||Timer!=TIMER3_BASE||Timer!=TIMER4_BASE||Timer!=TIMER5_BASE)
           {
               return TIM_ERROR;
           }

       else
           {
           switch(Timer)
                       {
                           case TIMER0_BASE:
                           {

                              TimerIntRegister (Timer, channel, Timer0BIntHandler);
                               break;
                           }

                           case TIMER1_BASE:
                           {

                               TimerIntRegister (Timer, channel, Timer1BIntHandler);
                             break;
                           }

                           case TIMER2_BASE:
                           {

                             TimerIntRegister (Timer, channel, Timer2BIntHandler);
                             break;
                           }

                           case TIMER3_BASE:
                           {

                             TimerIntRegister (Timer, channel, Timer3BIntHandler);
                             break;
                           }
                           case TIMER4_BASE:
                           {

                             TimerIntRegister (Timer, channel, Timer4BIntHandler);
                             break;
                           }
                           case TIMER5_BASE:
                           {


                             TimerIntRegister (Timer, channel, Timer5BIntHandler);
                             break;
                           }
                           default:
                               return TIM_ERROR;
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
 *              TIMER_BOTH
 * value-значение предделителя
 * Example:
 *  SetPrescaler_TIM(TIMER0_BASE,TIMER_B,26)
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
                    switch(Tim)
                               {
                                   case TIMER0_BASE:
                                   {


                                       TimerPrescaleSet (TIMER0_BASE, channel, value);
                                       break;
                                   }

                                   case TIMER1_BASE:
                                   {


                                     TimerPrescaleSet (TIMER1_BASE, channel, value);
                                     break;
                                   }

                                   case TIMER2_BASE:
                                   {


                                     TimerPrescaleSet (TIMER2_BASE, channel, value);
                                     break;
                                   }

                                   case TIMER3_BASE:
                                   {


                                     TimerPrescaleSet (TIMER3_BASE, channel, value);
                                     break;
                                   }
                                   case TIMER4_BASE:
                                   {


                                     TimerPrescaleSet (TIMER4_BASE, channel, value);
                                     break;
                                   }
                                   case TIMER5_BASE:
                                   {

                                     TimerPrescaleSet (TIMER5_BASE, channel, value);
                                     break;
                                   }
                                   default:
                                       return TIM_ERROR;
                         }


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
 *              TIMER_BOTH
 * value-значение тиков
 * Example:
 *SetLoad_TIM(TIMER0_BASE,TIMER_A,1234);
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
            switch(Tim)
                                           {
                                               case TIMER0_BASE:
                                               {


                                                   TimerLoadSet (TIMER0_BASE, channel, value);
                                                   break;
                                               }

                                               case TIMER1_BASE:
                                               {


                                                   TimerLoadSet (TIMER1_BASE, channel, value);
                                                   break;
                                               }

                                               case TIMER2_BASE:
                                               {


                                                   TimerLoadSet (TIMER2_BASE, channel, value);
                                                   break;
                                               }

                                               case TIMER3_BASE:
                                               {


                                                   TimerLoadSet (TIMER3_BASE, channel, value);
                                                   break;
                                               }
                                               case TIMER4_BASE:
                                               {

                                                   ;
                                                   TimerLoadSet (TIMER4_BASE, channel, value);
                                                   break;
                                               }
                                               case TIMER5_BASE:
                                               {

                                                   TimerLoadSet (TIMER5_BASE,channel, value);
                                                   break;
                                               }
                                               default:
                                                   return TIM_ERROR;
                                     }


                return TIM_OK;
            }
    }
}



































/*==================================================2-Вариант==============================================*/


/*************************************Второй вариант инициализации**********************/
RESULT_TIM TIM_Initilize(uint32_t N_tim,uint8_t Mode,uint8_t channel,uint8_t HalfMode,uint8_t full_Mode,uint8_t cap_Mode)
{



    if((N_tim!=TIMER0_BASE||N_tim!=TIMER1_BASE||N_tim!=TIMER2_BASE||N_tim!=TIMER3_BASE||N_tim!=TIMER4_BASE||N_tim!=TIMER5_BASE)||(Mode!=TIM_PWM||Mode!=TIM_HalfMode ||Mode!=TIM_FullMode||Mode!=TIM_CaptureMode))
    {
        return TIM_ERROR;
    }
    else
    {

        switch(Mode)
        {
        //---------------------------ШИМ--------------------------
            case TIM_PWM:
            {
                if(channel==CHANNEL_A)
                {
                    TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
                }
                else if(channel==CHANNEL_B)
                {
                    TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
                }
                else
                {
                    return TIM_ERROR;
                }
                break;
            }
            //----------------------------------------------------
            //---------------------------режим полуразмерности--------------------------
            case TIM_HalfMode:
            {

                if(channel==CHANNEL_A)
                {
                   switch(HalfMode)
                   {
                       case A_ONE_SHOT:
                       {

                           TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT);
                           break;
                       }
                       case A_ONE_SHOT_UP:
                       {
                           TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT_UP);
                           break;
                       }
                       case A_PERIODIC:
                       {
                           TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC);
                           break;
                       }

                       case A_PERIODIC_UP:
                       {
                           TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC_UP);
                           break;
                       }

                       default:
                       {
                           return TIM_ERROR;
                       }


                   }
                }
                else if(channel==CHANNEL_B)
                {
                    switch(HalfMode)
                    {
                      case B_ONE_SHOT:
                       {
                           TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_ONE_SHOT);
                          break;
                        }
                      case B_ONE_SHOT_UP:
                        {
                            TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_ONE_SHOT_UP);
                          break;
                        }
                      case B_PERIODIC:
                        {
                            TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC);
                           break;
                        }

                      case B_PERIODIC_UP:
                        {
                          TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC_UP);
                          break;
                        }

                      default:
                         {
                           return TIM_ERROR;
                         }

                     }
                }
                else
                {
                    return TIM_ERROR;
                }

                break;
            }
            //--------------------------------------------------------------------------

            case TIM_FullMode:
            {
                switch(full_Mode)
                {
                    case FULL_ONE_SHOT:
                    {
                        TimerConfigure(N_tim,TIMER_CFG_ONE_SHOT);
                        break;
                    }
                    case FULL_ONE_SHOT_UP:
                    {
                        TimerConfigure(N_tim,TIMER_CFG_ONE_SHOT_UP);
                        break;
                    }
                    case FULL_ONE_PERIODIC:
                    {
                        TimerConfigure(N_tim,TIMER_CFG_PERIODIC);
                        break;
                    }
                    case FULL_ONE_PERIODIC_UP:
                    {
                        TimerConfigure(N_tim,TIMER_CFG_PERIODIC_UP);
                        break;
                    }
                    case FULL_ONE_RTC:
                    {
                        TimerConfigure(N_tim,TIMER_CFG_RTC);
                        break;
                    }
                    default:
                    {
                        return TIM_ERROR;
                    }
                }
                break;
            }
            //-----------------------------------------------------------


            case TIM_CaptureMode:
            {
                if(channel==CHANNEL_A)
                 {

                    switch(cap_Mode)
                    {
                        case CAP_COUNT:
                        {
                            TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_CAP_COUNT);
                            break;
                        }

                        case CAP_COUNT_UP:
                        {
                            TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_CAP_COUNT_UP);
                            break;
                        }

                        case CAP_TIME:
                        {
                            TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_CAP_TIME);
                            break;
                        }

                        case CAP_TIME_UP:
                        {
                            TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_CAP_TIME_UP);
                            break;
                        }


                        default:
                        {
                            return TIM_ERROR;
                        }
                    }

                   TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
                 }
                else if(channel==CHANNEL_B)
                 {
                    switch(cap_Mode)
                                        {
                                            case CAP_COUNT:
                                            {
                                                TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_CAP_COUNT);
                                                break;
                                            }

                                            case CAP_COUNT_UP:
                                            {
                                                TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_CAP_COUNT_UP);
                                                break;
                                            }

                                            case CAP_TIME:
                                            {
                                                TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_CAP_TIME);
                                                break;
                                            }

                                            case CAP_TIME_UP:
                                            {
                                                TimerConfigure(N_tim,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_CAP_TIME_UP);
                                                break;
                                            }


                                            default:
                                            {
                                                return TIM_ERROR;
                                            }

                                        }



                 }
                 else
                 {
                    return TIM_ERROR;
                 }
                break;
            }





        }


        return TIM_OK;
    }

}














