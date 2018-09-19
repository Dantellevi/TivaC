#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_

#include "Main.h"
#include <stdint.h>


typedef enum
{

   TIM_OK=1,
   TIM_ERROR=0

}RESULT_TIM;


/**********************������� ������������� ������� ��� ��������� ������**********/
/*
 * ���������:
 *              Timer-����� �������,
 *              Mode- ����� ������ �������
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



 */
RESULT_TIM Timer_init(uint32_t Timer,uint32_t Mode);



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
RESULT_TIM Innterupt_TIM(bool en,uint32_t Timer,uint32_t ModeInt);



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
RESULT_TIM SetPrescaler_TIM(uint32_t Tim,uint32_t channel,uint32_t value);


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
RESULT_TIM SetLoad_TIM(uint32_t Tim,uint32_t channel,uint32_t value);








#endif /* INC_TIMERS_H_ */
