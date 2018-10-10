#include "Main.h"


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









void main(void)
{
    InitPeripheral();

    while(1)
    {

    }
}





