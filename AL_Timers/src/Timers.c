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



/*********************Вкл/Откл таймера ******************************/
/*
 *
 * Параметры :
 *  tim-Структура с хранимыми настройками  таймера
 *  sw-флаг отвечающий за состояния вкл./выкл.
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



/**********************Функция установки предделителя*****************/
/*
 *
 *  Параметры :
 *  tim-Структура с хранимыми настройками  таймера
 *  val-значение для предделителя
 *
 *
 */
void SetValuePresceler(TimerConfigDef *tim,uint32_t val)
{
    TimerPrescaleSet(tim->NameTimer,tim->Mode.param,val);
}


/*************************Функция задания количества отсчета*********/
/*
 *
 *  *  Параметры :
 *  tim-Структура с хранимыми настройками  таймера
 *  val-значение счетчика таймера
 *
 *
 */
void SetValueCount(TimerConfigDef *tim,uint32_t val)
{
    TimerLoadSet(tim->NameTimer,tim->Mode.param,val);
}


/************************Функция регистрации прерываний************/
/*
 *
 * Параметры:
 *
 * tim-Структура с хранимыми настройками  таймера
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



/*****************************Функция настройки таймера***********************************/
/*
 * Параметры:
 * nameTIM-
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER5_BASE
 * Mode-
 *              TIMER_CFG_ONE_SHOT-режим полноразмерной работы таймера с одной выборкой
                TIMER_CFG_ONE_SHOT_UP- режим полноразмерной работы таймера  с подсчетам в верх вместо вниз с одной выборкой
                TIMER_CFG_PERIODIC- Полноразмерный периодический таймер
                TIMER_CFG_PERIODIC_UP- полноразмерный периодический таймер с подсчетом вверх
                TIMER_CFG_RTC-конфигурация часов реального времени
                TIMER_CFG_SPLIT_PAIR- два таймера по половине ширины подсчета(разбитие Таймер А и Таймер В)
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                Дополнительные режимы для таймеров:
                TIMER_CFG_A_ONE_SHOT-вкл. Режим таймера с половинной шириной таймер А
                IMER_CFG_A_ONE_SHOT_UP- вкл. Режим таймера с половинной шириной таймер А
                                                                         С подсчетом вверх
                TIMER_CFG_A_PERIODIC-периодический таймер с половинной шириной
                TIMER_CFG_A_PERIODIC_UP- периодический таймер с половинной шириной с подсчетом вверх
                TIMER_CFG_A_CAP_COUNT- режим таймера с половинной шириной с захватом
                TIMER_CFG_A_CAP_COUNT_UP- режим таймера с половинной шириной с захватом и подсчетом
                TIMER_CFG_A_CAP_TIME-захват времени в режиме половинной ширины
                TIMER_CFG_A_CAP_TIME_UP- захват времени в режиме половинной ширины и подсчетом вверх
                TIMER_CFG_A_PWM-ШИМ таймер А
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                Дополнительные конфигурации для таймера в режиме половинной ширины(Таймер A):
                TIMER_CFG_A_ACT_TOINTD - маскирует тайм-аут прерывания таймера A.
                TIMER_CFG_A_ACT_NONE – бездействие при таймауте таймера А.
                TIMER_CFG_A_ACT_TOGGLE – переключение CCP регистр на таймауте таймера А
                TIMER_CFG_A_ACT_SETTO – установить CCP на таймауте таймера А.
                TIMER_CFG_A_ACT_CLRTO – очистить CCP регистр на таймауте таймера А.
                TIMER_CFG_A_ACT_SETTOGTO – Мгновенно установить значение в регистр CCP и затем переключите его на таймаут таймера А.
                TIMER_CFG_A_ACT_CLRTOGTO - немедленно очистить CCP, а затем переключить его на тайм-аут
                таймера A
                .TIMER_CFG_A_ACT_SETCLRTO - немедленно установите CCP, а затем очистите его
                таймер A
                TIMER_CFG_A_ACT_CLRSETTO - немедленно очистите CCP, а затем установите его на тайм-аут
                таймер A
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                Дополнительные конфигурации для таймера в режиме половинной ширины(Таймер B):

                TIMER_CFG_B_ACT_TOINTD - маскирует тайм-аут прерывания таймера B.
                TIMER_CFG_B_ACT_NONE – бездействие при таймауте таймера B.
                TIMER_CFG_B_ACT_TOGGLE – переключение CCP регистр на таймауте таймера B
                TIMER_CFG_B_ACT_SETTO – установить CCP на таймауте таймера B.
                TIMER_CFG_B_ACT_CLRTO – очистить CCP регистр на таймауте таймера B.
                TIMER_CFG_B_ACT_SETTOGTO – Мгновенно установить значение в регистр CCP и затем переключите его на таймаут таймера B.
                TIMER_CFG_B_ACT_CLRTOGTO - немедленно очистить CCP, а затем переключить его на тайм-аут
                таймера B
                .TIMER_CFG_B_ACT_SETCLRTO - немедленно установите CCP, а затем очистите его таймер B
                TIMER_CFG_B_ACT_CLRSETTO - немедленно очистите CCP, а затем установите его на тайм-аут
                таймер B

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
    G_I-        Назначение прерываний
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
                   Возращаем структуру через указатель для работы с функциями задания прерываний,вкл/выкл. таймера и др.

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

































