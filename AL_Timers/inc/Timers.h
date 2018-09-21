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
    uint32_t param_EnInt;

}ModeTimerDef;


typedef struct
{
    uint32_t NameTimer;
    ModeTimerDef Mode;


}TimerConfigDef;



typedef enum
{
    TIM_ERROR,
    TIM_OK
}RESULT_TIMDef;



/*********************Инициализация таймера ******************************/
void TIM_Init(TimerConfigDef *tim);

/*********************Вкл/Откл таймера ******************************/
void TIM_ToggleStatus(TimerConfigDef *tim,bool sw);
/*********************Вкл/Откл таймера ******************************/
void ToggleInterrupt(TimerConfigDef *tim,bool sw);
/**********************Функция установки предделителя*****************/
void SetValuePresceler(TimerConfigDef *tim,uint32_t val);
/************************Функция регистрации прерываний************/
void RegisterInterrupt(TimerConfigDef *tim);



#endif /* INC_TIMERS_H_ */
