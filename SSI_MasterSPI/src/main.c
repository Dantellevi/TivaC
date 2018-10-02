#include "Main.h"

//----------------------------------------------
//! - SSI0 peripheral
//! - GPIO Port A peripheral (for SSI0 pins)
//! - SSI0Clk - PA2
//! - SSI0Fss - PA3
//! - SSI0Rx  - PA4
//! - SSI0Tx  - PA5
//----------------------------------------------

//---------------------------��������� LTC2664IUH-12-----------------------------
// ----------------Span Code----------------
#define WRITE_SPAN_CMD          0x06
#define FRAMES_0V_5V            0x00
#define FRAMES_0V_10V           0x01
#define FRAMES_M5V_5V           0x02
#define FRAMES_M10V_10V         0x03
#define FRAMES_M2_5V_2_5V       0x04

//---------------Analog Mux Control Codes---------------
#define MUX_DISABLED            00000b
#define MUX_MUXIN0              10000b
#define MUX_Vout0               10001b
#define MUX_Vout1               10010b
#define MUX_MUXIN1              10011b
#define MUX_MUXIN2              10100b
#define MUX_Vout2               10101b
#define MUX_Vout3               10110b
#define MUX_MUXIN3              10111b
#define MUX_REFLO               11000b
#define MUX_REF                 11001b
#define MUX_T_M                 11010b
#define MUX_V_PL                11011b
#define MUX_V_MN                11100b

//-------------------------------------------------------------------------------




/*******************������������� ���������*********************/
void InitPeripheral(void)
{
    //��������� ������������(��������� ����. ����������� 1,������������  ��������� ���� �� �����. ��� ������� ������������, ����. �����,�������)
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//���. ������������ ���������
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);//���. ������������ SSI

    GPIOPinConfigure(GPIO_PA2_SSI0CLK);//��������� ���� ������������ CLK
    GPIOPinConfigure(GPIO_PA3_SSI0FSS);//��������� ���� ������������ SS
    GPIOPinConfigure(GPIO_PA4_SSI0RX); //��������� ���� ������������ RX(MISO)
    GPIOPinConfigure(GPIO_PA5_SSI0TX); //��������� ���� ������������ TX(MOSI)
    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 |
                       GPIO_PIN_2);//��������� ����� SSI(SSI0,�������� �������� ������� MPU,��������� ������������ ����� CLK,�������� ��������, ������ ������)
    SSIConfigSetExpClk(SSI0_BASE,SysCtlClockGet(),SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER,1000000,8);
    SSIEnable(SSI0_BASE);//���.������ SSI


}


/****************����� ������*************************/
void SSI_GetValueSPI(uint32_t *buf)
{
    while(SSIDataGetNonBlocking(SSI0_BASE, buf))
    {

    }
}



/************************������� �������� ������(������)*********************/
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


/************************������� �������� ������(�����)*********************/
void SSI_SendSPI(uint32_t Byte)
{
    SSIDataPut(SSI0_BASE,Byte);
}

/************************������� �������� �����*********************/
void SendByteSPI(uint8_t B)
{
    SSIDataPut(SSI0_BASE,B);
}








void main(void)
{
    InitPeripheral();//��������� ���������

    while(1)
    {

    }
}





