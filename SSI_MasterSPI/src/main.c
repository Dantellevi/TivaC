#include "Main.h"

//----------------------------------------------
//! - SSI0 peripheral
//! - GPIO Port A peripheral (for SSI0 pins)
//! - SSI0Clk - PA2
//! - SSI0Fss - PA3
//! - SSI0Rx  - PA4
//! - SSI0Tx  - PA5
//----------------------------------------------

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
#define WRITE_CODE_N_POWER_UP_UPDATE_N      0b10110000
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




void InitPeripheral(void)
{
    //Настройка тактирования
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//подключения портов тактирование
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);//подключение тактирования SSI

    GPIOPinConfigure(GPIO_PA2_SSI0CLK);//конфигурирование CLK
    GPIOPinConfigure(GPIO_PA3_SSI0FSS);//конфигурирование CS
    GPIOPinConfigure(GPIO_PA4_SSI0RX); //   RX(MISO)
    GPIOPinConfigure(GPIO_PA5_SSI0TX); //  TX(MOSI)
    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 |
                       GPIO_PIN_2);
    //основные настройки SSI(SSI0, тактирование MPU,полярность  CLK,мастер, пропускная способность(скорость), делитель)
    SSIConfigSetExpClk(SSI0_BASE,SysCtlClockGet(),SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER,1000000,8);
    SSIEnable(SSI0_BASE);// включение SSI


}


/***********************Функция получения значения из SPI**********************/
void SSI_GetValueSPI(uint32_t *buf)
{
    while(SSIDataGetNonBlocking(SSI0_BASE, buf))
    {

    }
}



/*******************Отправда буффера в SPPI**********************/
void SSI_SendbufSPI(uint32_t *pBuf, uint32_t *count)
{
    uint32_t i;

    for(i=0;i<*count;i++)
    {
        SSIDataPut(SSI0_BASE,pBuf[i]);
    }
    while(SSIBusy(SSI0_BASE))
   {

   }
}


/************************Отправка  пакета по SPI*********************/
void SSI_SendSPI(uint32_t Byte)
{
    SSIDataPut(SSI0_BASE,Byte);
}


void SendByteSPI(uint8_t B)
{
    SSIDataPut(SSI0_BASE,B);
}




/*****************************Отправка данных в ЦАП*******************/
/*
 * Command: команда для отправки пример WRITE_CODE_N
 * Adsress: номер выхода ЦАП пример ADRESS_DAC3
 *  data: код для отправки в порт
 *
 *
 */
void LTC2664IUH_SendData(uint8_t Command,uint8_t Address,uint16_t data)
{
    uint32_t Bufcommand=0x0000000;//буффер для отправки в ЦАП
    uint8_t temp=Command|Address;   //формируем 8 бит типа :C3C2C1C0A3A2A1A0
    Bufcommand|=temp;//заносим данные 000000000000000000000000C3C2C1C0A3A2A1A0
    Bufcommand<<=16;// сдвигаем данные в определнную позицию 00000000C3C2C1C0A3A2A1A00000000000000000
    Bufcommand|=data;//заносим данные для ЦАП: xxxxxxxxC3C2C1C0A3A2A1A0d15d14d13d12d11d10d9d8d7d6d5d4d3d2d1d0
    SSI_SendSPI(Bufcommand<<8);//отправляем 24 битный кадр в ЦАП: C3C2C1C0A3A2A1A0d15d14d13d12d11d10d9d8d7d6d5d4d3d2d1d0

}


void LTC2664IUH_SendCommand(uint8_t TypeCommand,uint8_t MaskCom,uint8_t Address,uint16_t data)
{
    switch(TypeCommand)
    {
        case WRITE_SPAN_N:
        {
            //FORMAT: 0110A3A2A1A0XXXXXXXXXXXXXS2S1S0
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
            SSI_SendSPI(bufCom<<8);
            break;
        }

        case WRITE_SPAN_ALL:
        {
            uint32_t bufCom;
                       //WRITE_SPAN_ALL                      0b11100000
                       uint8_t temp=WRITE_SPAN_ALL;//0b11100000
                       bufCom=temp;//0b00000000000000000000000001100100
                       bufCom=bufCom<<16;  //0b00000000011001000000000000000000
                       data|=MaskCom;//0b0000001110100011          Data: 0b0000001110100000  MASK: M10V_P10V -0b00000011
                       bufCom|=data;//0b00000000011001000000001110100011
                       SSI_SendSPI(bufCom<<8);
                       break;
            break;
        }

        case ANALOG_MUX:
        {

            break;
        }
        case TOOGLE_SELECT:
        {

            break;
        }

        case GLOBAL_SELECT:
        {

            break;
        }
    }
}



void main(void)
{
    InitPeripheral();

    while(1)
    {

    }
}





