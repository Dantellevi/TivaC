#include "SPI.h"

/***********************Функция получения значения из SPI**********************/
void SSI_GetValueSPI(uint32_t *buf, uint32_t def)
{
    while(SSIDataGetNonBlocking(def, buf));

}



/*******************Отправда буффера в SPPI**********************/
void SSI_SendbufSPI(uint32_t *pBuf, uint32_t *count,uint32_t def)
{
    uint32_t i;

    for(i=0;i<*count;i++)
    {
        SSIDataPut(def,pBuf[i]);
    }
    while(SSIBusy(def));

}


/************************Отправка  пакета по SPI*********************/
void SSI_SendSPI(uint32_t Byte,uint32_t def)
{
    SSIDataPut(def,Byte);
}


void SendByteSPI(uint8_t B,uint32_t def)
{
    SSIDataPut(def,B);
}



