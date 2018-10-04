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


void SSI_GetValueSPI(uint32_t *buf)
{
    while(SSIDataGetNonBlocking(SSI0_BASE, buf))
    {

    }
}



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


void SSI_SendSPI(uint32_t Byte)
{
    SSIDataPut(SSI0_BASE,Byte);
}


void SendByteSPI(uint8_t B)
{
    SSIDataPut(SSI0_BASE,B);
}



void LTC2664IUH_SendData(uint8_t Command,uint8_t Address,uint16_t data)
{
    uint32_t Bufcommand=0x0000000;//буффер для отправки в ЦАП
    uint8_t temp=Command|Address;   //формируем 8 бит типа :C3C2C1C0A3A2A1A0
    Bufcommand|=temp;//заносим данные 000000000000000000000000C3C2C1C0A3A2A1A0
    Bufcommand<<=16;// сдвигаем данные в определнную позицию 00000000C3C2C1C0A3A2A1A00000000000000000
    Bufcommand|=data;//заносим данные для ЦАП: 00000000
    SSI_SendSPI(Bufcommand<<8);//отправляем 24 битный кадр в ЦАП: C3C2C1C0A3A2A1A0d15d14d13d12d11d10d9d8d7d6d5d4d3d2d1d0

}







void main(void)
{
    InitPeripheral();

    while(1)
    {

    }
}





