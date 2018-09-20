#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_


#include "Main.h"
#include <stdint.h>



typedef enum
{
    PWM_Generation,
    Half_Size_TIM,
    FULL_Size_TIM,
    Capture_TIM


}NameModeDef;


typedef struct
{
    NameModeDef NameMode;
    uint32_t COnfigReg;
    uint32_t param;
    uint32_t par_Int;

}ModeTimerDef;


typedef struct
{
    uint32_t NameTimer;
    ModeTimerDef Mode;


}TimerConfigDef;



/*********************������������� ������� ******************************/
void TIM_Init(TimerConfigDef *tim);

/*********************���/���� ������� ******************************/
void TIM_ToggleStatus(TimerConfigDef *tim,bool sw);
/*********************���/���� ������� ******************************/
void ToggleInterrupt(TimerConfigDef *tim,bool sw);
/**********************������� ��������� ������������*****************/
void SetValuePresceler(TimerConfigDef *tim,uint32_t val);



#endif /* INC_TIMERS_H_ */