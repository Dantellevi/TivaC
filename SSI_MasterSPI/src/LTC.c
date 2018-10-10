#include "LTC2664IUH.h"




/*****************************Отправка данных в ЦАП по адресу*******************/
/*
 * Command: команда для отправки пример WRITE_CODE_N
 * Adsress: номер выхода ЦАП пример ADRESS_DAC3
 *  data: код для отправки в порт
 *
 *
 */
void LTC2664IUH_SendData(uint32_t SSI,uint8_t Address,uint16_t data)
{
    uint32_t Bufcommand=0x0000000;//буффер для отправки в ЦАП
    uint8_t temp=WRITE_CODE_N|Address;   //формируем 8 бит типа :C3C2C1C0A3A2A1A0
    Bufcommand|=temp;//заносим данные 000000000000000000000000C3C2C1C0A3A2A1A0
    Bufcommand<<=16;// сдвигаем данные в определнную позицию 00000000C3C2C1C0A3A2A1A00000000000000000
    Bufcommand|=data;//заносим данные для ЦАП: xxxxxxxxC3C2C1C0A3A2A1A0d15d14d13d12d11d10d9d8d7d6d5d4d3d2d1d0
    SSI_SendSPI(Bufcommand<<8,SSI);//отправляем 24 битный кадр в ЦАП: C3C2C1C0A3A2A1A0d15d14d13d12d11d10d9d8d7d6d5d4d3d2d1d0
}



/**********************************Функция отправки команды SPAN_N************************/
void LTC2664IUH_SendCom_SPAN_N(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data)
{
    //FORMAT:              0110A3A2A1A0XXXXXXXXXXXXXS2S1S0
                /*        |___|_______|____________|_____|
                 *          |       |           |       |
                 *          |       |           |       |
                 *WRITE SPAN COMMAND|           |       |
                 *                  |           |       |
                 *            ADDRESS           |       |
                 *               Data(DON'T CARE)       |
                 *                                  SPAN CODE
                 *                                  */
    uint32_t bufCom;
    //WRITE_SPAN_N=0110
    uint8_t temp=WRITE_SPAN_N;//0b01100000
    temp|=Address;//0b01100100              ADRESS_DAC2      0b00000100
    bufCom=temp;//0b00000000000000000000000001100100
    bufCom=bufCom<<16;  //0b00000000011001000000000000000000
    data|=MaskCom;//0b0000001110100011          Data: 0b0000001110100000  MASK: M10V_P10V -0b00000011
    bufCom|=data;//0b00000000011001000000001110100011
    SSI_SendSPI(bufCom<<8,SSI);
}



/**********************************Функция отправки команды SPAN_ALL************************/
void LTC2664IUH_SendCom_SPAN_ALL(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data)
{
    //FORMAT:              0110A3A2A1A0XXXXXXXXXXXXXS2S1S0
                /*        |___|_______|____________|_____|
                 *          |       |           |       |
                 *          |       |           |       |
                 *WRITE SPAN COMMAND|           |       |
                 *                  |           |       |
                 *            ADDRESS           |       |
                 *               Data(DON'T CARE)       |
                 *                                  SPAN CODE
                 *                                  */
    uint32_t bufCom;
    //WRITE_SPAN_N=0110
    uint8_t temp=WRITE_SPAN_ALL;//0b01100000
    temp|=Address;//0b01100100              ADRESS_DAC2      0b00000100
    bufCom=temp;//0b00000000000000000000000001100100
    bufCom=bufCom<<16;  //0b00000000011001000000000000000000
    data|=MaskCom;//0b0000001110100011          Data: 0b0000001110100000  MASK: M10V_P10V -0b00000011
    bufCom|=data;//0b00000000011001000000001110100011
    SSI_SendSPI(bufCom<<8,SSI);
}


/**********************************Функция отправки команды ANALOG_MUX************************/
void LTC2664IUH_SendCom_ANALOG_MUX(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data)
{
    //FORMAT:              1011XXXXXXXXXXXXXXXM4M3M2M1M0
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

                uint8_t temp=ANALOG_MUX;   //0b10110000
                uint32_t bufCom;
                uint32_t tempBuf;
                bufCom=temp;//0b00000000000000000000000010110000
                bufCom<<=16;            //0b00000000101100000000000000000000
                tempBuf=data; //0b00000000000000000000000000000011
                tempBuf<<=5;            //0b00000000000000000000000001100000
                bufCom|=tempBuf;        //0b00000000101100000000000001100000
                bufCom|=MaskCom;        //0b000000001011000000000000011M4M3M2M1M0
                SSI_SendSPI(bufCom<<8,SSI);
}




/**********************************Функция отправки команды ANALOG_MUX************************/
void LTC2664IUH_SendCom_TOGLE_SELECT(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data)
{
    /* ================Toggle Select Syntax====================
                * FORMAT: 1100XXXXXXXXXXXXXXXXT3T2T1T0
                *         |__|________________|_______|
                *           |          |           |
                *           |          |           |
                TOGGLE SELECT          |           |
                *        Data(DON'T CARE)          |
                          TOGGLE SELECT BITS(ONE FOR EACH CHANNEL)

               Write code channel 3 (code = 4096) to register A
               00000011 00010000 00000000   //command write N or update N
               2) Toggle Select (set bit T3)
               11000000 00000000 00001000 //toggle select
               3) Write code channel 3 (code = 4200) to register B
               00000011 00010000 01101000
               */
    LTC2664IUH_SendData(WRITE_CODE_N_POWER_UP_UPDATE_N,Address,data);
    uint8_t temp=TOOGLE_SELECT;   //0b11000000
    uint32_t bufCom;
    bufCom=temp;      //0b00000000000000000000000011000000
    bufCom<<=16;      //0b00000001100000000000000000000000

    uint8_t adr_mask;
    if(Address==ADRESS_DAC0)
    {
       adr_mask=0b00000001;
    }
    else if(Address==ADRESS_DAC1)
    {
      adr_mask=0b00000010;
    }
    else if(Address==ADRESS_DAC2)
    {
      adr_mask=0b00000100;
    }
    else if(Address==ADRESS_DAC3)
    {
     adr_mask=0b00001000;
    }
    bufCom|=adr_mask;
    bufCom|=data;
    SSI_SendSPI(bufCom<<8,SSI);

}






/**********************************Функция отправки команды ANALOG_MUX************************/
void LTC2664IUH_SendCom_GLOBAL_SELECT(uint32_t SSI,uint8_t MaskCom,uint8_t Address,uint16_t data)
{
    uint8_t temp=GLOBAL_SELECT;
    uint32_t bufCom;
    bufCom=temp;
    bufCom<<=16;
    data|=MaskCom;
    bufCom|=data;
    SSI_SendSPI(bufCom<<8,SSI);
}
















