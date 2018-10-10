/*
 * LTC2664IUH.h
 *
 *  Created on: 10 окт. 2018 г.
 *      Author: Lepatenko
 */

#ifndef INC_LTC2664IUH_H_
#define INC_LTC2664IUH_H_

#include "Main.h"


//--------------------------- LTC2664IUH-12-----------------------------
#define ADRESS_DAC0      0b00000000
#define ADRESS_DAC1      0b00000010
#define ADRESS_DAC2      0b00000100
#define ADRESS_DAC3      0b00000110

/*******************COMMAND*******************************/
#define WRITE_CODE_N                        0b00000000
#define WRITE_CODE_ALL                      0b10000000
#define WRITE_SPAN_N                        0b01100000
#define WRITE_SPAN_ALL                      0b11100000
#define POWER_UP_UPDATE_N                   0b00010000
#define POWER_UP_UPDATE_ALL                 0b10010000
#define WRITE_CODE_N_POWER_UP_UPDATE_N      0b00110000
#define WRITE_CODE_N_POWER_UP_UPDATE_ALL    0b00100000
#define WRITE_CODE_ALL_POWER_UP_UPDATE_ALL  0b10100000
#define POWER_DOWN_N                        0b01000000
#define POWER_DOWN_CHIP                     0b01010000
#define ANALOG_MUX                          0b10110000
#define TOOGLE_SELECT                       0b11000000
#define GLOBAL_SELECT                       0b11010000
#define CONFIG                              0b01110000
#define NO_OP                               0b11110000


/****************************SoftSpan Operation **************************/
/*********************************SPAN CODE************************************************/
                                                            // Internal REFERENCE   |EXTERNAL REFERENCE
#define P0V_5V                              0b00000000          //0V to 5V          |0V to 2Vref
#define P0V_10V                             0b00000001          //0V to 10V         |0V to 4Vref
#define M5V_P5V                             0b00000010          //+-5V              |+-2Vref
#define M10V_P10V                           0b00000011          //+-10V             |+-4Vref
#define M2_5V_P2_5V                         0b00000100          //+-2.5V            |+-Vref
                                                 /*|||
                                                  S2||
                                                   S1|
                                                     S0
                                                   *
                                                 */

//FORMAT: 0110A3A2A1A0XXXXXXXXXXXXXS2S1S0
/*        |___|_______|____________|_____|
 *          |       |           |       |
 *          |       |           |       |
 *WRITE SPAN COMMAND|           |       |
 *                  |           |       |
 *            ADDRESS           |       |
 *               Data(DON'T CARE)       |
 *                                  SPAN CODE
 *
 */
//----------------------------------------------------------------------
/*********************************Analog Mux***************************/
#define DISABLE_Hi_Z        0b00000000
#define MUXIN0              0b00010000
#define VOUT0               0b00010001
#define VOUT1               0b00010010
#define MUXIN1              0b00010011
#define MUXIN2              0b00010100
#define VOUT2               0b00010101
#define VOUT3               0b00010110
#define MUXIN3              0b00010111
#define REFLO               0b00011000
#define REF                 0b00011001
#define TEMP_MONITOR        0b00011010
#define V_P                 0b00011011
#define V_N                 0b00011100


//FORMAT: 1011XXXXXXXXXXXXXXXM4M3M2M1M0
/*        |___|______________|_________|
 *          |       |           |
 *          |       |           |
 MUX COMMAND|       |           |
 *                  |           |
 *   Data(DON'T CARE)           |
 *                     MUX CONTROL CODE
 *
 *
 */


//=============================Toggle Operations===========================
/*
 * Имеется два выходных регистра А и В. По команде данные будут выставляться либо из А регистра либо из В.
 *
 * ================Toggle Select Syntax====================
 * FORMAT: 1100XXXXXXXXXXXXXXXXT3T2T1T0
 *         |__|________________|_______|
 *           |          |           |
 *           |          |           |
 TOGGLE SELECT          |           |
 *        Data(DON'T CARE)          |
           TOGGLE SELECT BITS(ONE FOR EACH CHANNEL)

Write code channel 3 (code = 4096) to register A
00000011 00010000 00000000
2) Toggle Select (set bit T3)
11000000 00000000 00001000
3) Write code channel 3 (code = 4200) to register B
00000011 00010000 01101000

=========================Global Toggle Syntax=====================

FORMAT: 1101XXXXXXXXXXXXXXXXXXXXTGB
        |__|____________________|__|
          |             |         |
   GLOBAL               |         |
TOGGLE COMMAND          |         |
          Data(DON'T CARE)        |
                              GLOBAL
                              TOGGLE
                              BIT


*/
//----------------------------------------------------------------------

/*****************************Отправка данных в ЦАП по адресу*******************/
/*
 * Command: команда для отправки пример WRITE_CODE_N
 * Adsress: номер выхода ЦАП пример ADRESS_DAC3
 *  data: код для отправки в порт
 *
 *
 */
void LTC2664IUH_SendData(uint32_t SSI,uint8_t Address,uint16_t data);



/**********************************Функция отправки команды SPAN_N************************/
void LTC2664IUH_SendCom_SPAN_N(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data);



/**********************************Функция отправки команды SPAN_ALL************************/
void LTC2664IUH_SendCom_SPAN_ALL(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data);

/**********************************Функция отправки команды ANALOG_MUX************************/
void LTC2664IUH_SendCom_ANALOG_MUX(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data);

/**********************************Функция отправки команды ANALOG_MUX************************/
void LTC2664IUH_SendCom_ANALOG_MUX(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data);
/**********************************Функция отправки команды ANALOG_MUX************************/
void LTC2664IUH_SendCom_GLOBAL_SELECT(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data);




#endif /* INC_LTC2664IUH_H_ */
