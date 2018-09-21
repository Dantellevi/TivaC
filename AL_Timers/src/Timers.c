#include "Timers.h"



/******************Обработчик прерываний Таймера 0**************************/
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

/******************Обработчик прерываний Таймера 0**************************/
void Timer1BIntHandler(void)
{
    /// Очистка флага прерывания таймера
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


/******************Обработчик прерываний Таймера 0**************************/
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


/******************Обработчик прерываний Таймера 0**************************/
void Timer3BIntHandler(void)
{
    // Очистка флага прерывания таймера
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


/******************Обработчик прерываний Таймера 0**************************/
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


/******************Обработчик прерываний Таймера 0**************************/
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





/*********************Инициализация таймера ******************************/
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



/*********************Вкл/Откл таймера ******************************/
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



/*********************Вкл/Откл таймера ******************************/
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



/**********************Функция установки предделителя*****************/
void SetValuePresceler(TimerConfigDef *tim,uint32_t val)
{
    TimerPrescaleSet(tim->NameTimer,tim->Mode.param,val);
}


/*************************Функция задания количества отсчета*********/
void SetValueCount(TimerConfigDef *tim,uint32_t val)
{
    TimerLoadSet(tim->NameTimer,tim->Mode.param,val);
}


/************************Функция регистрации прерываний************/
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




























