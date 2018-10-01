#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"



/***********************Функция записи строки в UART******************************/
void SendStringUART(uint32_t nBase, char *str)
{
    while(*str!='\0')
    {
        if(UARTSpaceAvail(nBase))
        {
            while(!UARTCharPutNonBlocking(nBase,*str));
            str++;


        }
    }
}


/********************Прием данных**************************/
void URT0_RXHandler(void)
{
    char rcv_ch;
    uint32_t intStatus;
    intStatus=UARTIntStatus(UART0_BASE,true);//считываем статус прерывнаия
    UARTIntClear(UART0_BASE,intStatus);//очистка флага прерывания
    rcv_ch=UARTCharGetNonBlocking(UART0_BASE);//считываем символ из порта

    if((uint32_t)rcv_ch!=-1)//проверка
    {
        //формируем эхо ответ
        while(!UARTCharPutNonBlocking(UART0_BASE,rcv_ch));
    }


    /*
     *
     * while (i! = CHAR_COUNT)
     * {
        DataBuffer [i] = UARTCharGetNonBlocking (UART1_BASE);
        i ++;
       }
     *
     *
     *void
UARTIntHandler0(void)
{
    // Get the interrupt status.
    ulStatus0 = ROM_UARTIntStatus(UART0_BASE, true);

    // Clear the asserted interrupts
    ROM_UARTIntClear(UART0_BASE, ulStatus0);

    // Loop while there are characters in the receive FIFO.
    while(ROM_UARTCharsAvail(UART0_BASE))
    {
        // Grab a character
        var = (unsigned char)ROM_UARTCharGetNonBlocking(UART0_BASE);

        // Hold it
        ptr[i] = var;

        // Mirror it to GSM
        ROM_UARTCharPutNonBlocking(UART1_BASE, ptr[i]);

        // Proceed to next character
        i++;
    }
}
     *
     *
     */

}


void main(void)
{

    //Включение тактирования(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактирования, внеш. кварц,частота)
            SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);

            SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);//вкл. тактирование UART0

            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//вкл. тактирование порта А
            GPIOPinConfigure(GPIO_PA0_U0RX);//пин 0А на RxD
            GPIOPinConfigure(GPIO_PA1_U0TX);//пин 0А на TxD
            GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0|GPIO_PIN_1);

            IntDisable(INT_UART0);//откл. прерывания UART0
            UARTDisable(UART0_BASE);//откл. UART 0
            UARTClockSourceSet(UART0_BASE,UART_CLOCK_PIOSC);
            UARTConfigSetExpClk(UART0_BASE,16000000,115200,UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);//тактирование 16 МГц, скорость-115200, 8бит,1стопбит,без бита четности
            UARTFIFODisable(UART0_BASE);//откл. буффера
            UARTIntRegister(UART0_BASE,URT0_RXHandler);//регистрация обработчика событий
            UARTEnable(UART0_BASE);//разрешение работы UART
            IntEnable(INT_UART0);//разрешение прерываниям




    while(1)
    {
           UARTCharPut(UART0_BASE,'x');
           SysCtlDelay((SysCtlClockGet()/3000)*500);
           SendStringUART(UART0_BASE,"Hello World\r\n");



    }
}


