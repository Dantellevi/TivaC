#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_

#include "Main.h"
#include <stdint.h>


typedef enum
{

   TIM_OK=1,
   TIM_ERROR=0

}RESULT_TIM;


/**********************Функция инициализации таймера для заданного режима**********/
/*
 * Параметры:
 *              Timer-адрес таймера,
 *              Mode- режим работы таймера
 *
 *              Timer:
 *              TIMER0_BASE,
 *              TIMER1_BASE,
 *              TIMER2_BASE,
 *              TIMER3_BASE,
 *              TIMER4_BASE,
 *              TIMER4_BASE
 *              -----------------------------------------
 *              Mode:
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



 */
RESULT_TIM Timer_init(uint32_t Timer,uint32_t Mode);



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
RESULT_TIM Innterupt_TIM(bool en,uint32_t Timer,uint32_t ModeInt);



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
RESULT_TIM SetPrescaler_TIM(uint32_t Tim,uint32_t channel,uint32_t value);


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
RESULT_TIM SetLoad_TIM(uint32_t Tim,uint32_t channel,uint32_t value);








#endif /* INC_TIMERS_H_ */
