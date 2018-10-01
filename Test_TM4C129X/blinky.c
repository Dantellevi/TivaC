//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2013-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.4.178 of the EK-TM4C129EXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
/* Defines the Port/Pin Mapping */
#include "driverlib/pin_map.h"
/* Defines and Macros for Timers */
#include "inc/hw_timer.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

/* Defines boolean and integer data types */
#include <stdbool.h>
#include <stdint.h>
/* Defines the base address of the memories and peripherals */
#include "inc/hw_memmap.h"
/* Defines the common types and macros */
#include "inc/hw_types.h"
/* Defines and Macros for Timers */
#include "inc/hw_timer.h"
#include "driverlib/timer.h"
/* Defines of the interrupts */
#include "inc/hw_ints.h"
/* Defines and Macros for GPIO API */
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
/* Prototypes for the system control driver */
#include "driverlib/sysctl.h"
/* Defines the Port/Pin Mapping */
#include "driverlib/pin_map.h"

#include "blinky.h"
//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
#endif

//*****************************************************************************
//
// Blink the on-board LED.
//

volatile uint32_t ui32Loop, Count, A=0;

volatile uint32_t Flag=0;



//*****************************************************************************
int
main(void)
{





                SysCtlClockSet(SYSCTL_XTAL_25MHZ| SYSCTL_USE_PLL |SYSCTL_SYSDIV_2_5);   // Частота 80 МГц. // Наконец-то!!!!!

                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);    // РАзрешение порта D
                GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);

                                while( !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD) )    // Ждем пока включится переферия порта....// Check if the peripheral access is enabled.
                                {

                                }

                                //
                                SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);   /* The TIMER0 and TIMER1 peripheral must be enabled for use.*/

                                                                                    /* Configuring PORTF pin0 as timer pins */
                                                                              //      GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_0);
                                                                              //      GPIOPinConfigure(GPIO_PD0_WT2CCP0);

                        //        TIMER_CFG_SPLIT_PAIR |
                                TimerConfigure(WTIMER2_BASE,  TIMER_CFG_A_PERIODIC_UP);   /* Configuring the WTIMER2 */ // TIMER_CFG_A_PERIODIC   TIMER_CFG_A_PWM

                                TimerLoadSet(WTIMER2_BASE, TIMER_A, 8000000);     /* Set the Load value of the Timers */

                        //        TimerMatchSet(WTIMER2_BASE, TIMER_A, 500000);   /* Set the Match value of the Timers */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                TimerEnable(WTIMER2_BASE, TIMER_A);  /* Enable the Timers */

                   //             IntMasterEnable(); //разрешаем прерывания вообще


                                TimerIntEnable(WTIMER2_BASE, TIMER_TIMA_TIMEOUT);   // TIMER_CAPA_MATCH TIMER_TIMA_TIMEOUT        TIMER_CAPA_EVENT

                                TimerIntRegister(WTIMER2_BASE, TIMER_A, Int_);      // Назначаем функцию-обработчик прерывания








                                           //           GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
                                                        GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);  // нулевой пин разрешаем как выход



    // Loop forever.

   Count=1;

    while(1)
    {

/*
        while(Count<=799999 )
        {



            Count++;

            for(ui32Loop = 0; ui32Loop < 50; ui32Loop++)
            {

            }

            TimerMatchSet(WTIMER2_BASE, TIMER_A,Count );

        }

        while(Count>=1 )
                {
                    Count--;

                    for(ui32Loop = 0; ui32Loop < 50; ui32Loop++)
                    {

                    }

                    TimerMatchSet(WTIMER2_BASE, TIMER_A,Count );

                }






                                                //
                                                // Turn on the LED.
                                                //
                                                GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);

                                                //
                                                // Delay for a bit.
                                                //
                                                for(ui32Loop = 0; ui32Loop < Count; ui32Loop++)
                                                {

                                                }

                                                //
                                                // Turn off the LED.
                                                //
                                                GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);


                                                //
                                                // Delay for a bit.
                                                //
                                                for(ui32Loop = 0; ui32Loop < Count; ui32Loop++)
                                                {

                                                }

                                                Count++;
                                                if (Count==101)
                                                {
                                                    Count=1;
                                                }



 */

    }


}

void Int_()
{

    A=100;

    if (Flag==0)
    {
        Flag=1;
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);
    }
    if (Flag==1)
    {
        Flag=0;
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);
    }
}

