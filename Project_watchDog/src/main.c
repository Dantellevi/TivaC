#include "main.h"

bool clearWatchDog=false;


void Watch_Interrupt(void)
{
    if(clearWatchDog)
    {
        clearWatchDog=false;
        WatchdogIntClear(WATCHDOG0_BASE);
        WatchdogReloadSet(WATCHDOG0_BASE,SysCtlClockGet());
    }
}


void main(void)
{
    //¬ключение тактировани€(указываем сист. пределитель 1,использовать  выбранный один из осцил. как систему тактировани€, внеш. кварц,частота)
            SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);
            GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
            GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD);
            GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD_WPU);
            SysCtlPeripheralEnable(SYSCTL_PERIPH_WDOG0);
            WatchdogReloadSet(WATCHDOG0_BASE,SysCtlClockGet());
            WatchdogResetEnable(WATCHDOG0_BASE);
            WatchdogIntRegister(WATCHDOG0_BASE,Watch_Interrupt);
            SysCtlDelay(SysCtlClockGet()/6);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,!GPIO_PIN_2);

    while(1)
    {
        clearWatchDog=true;
        SysCtlDelay((SysCtlClockGet()/3)*2);
        while(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4));
    }
}
