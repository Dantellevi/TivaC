/*
 * SPI.h
 *
 *  Created on: 10 окт. 2018 г.
 *      Author: Lepatenko
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_


#include "Main.h"



/***********************Функция получения значения из SPI**********************/
void SSI_GetValueSPI(uint32_t *buf, uint32_t def);
/*******************Отправда буффера в SPPI**********************/
void SSI_SendbufSPI(uint32_t *pBuf, uint32_t *count,uint32_t def);
/************************Отправка  пакета по SPI*********************/
void SSI_SendSPI(uint32_t Byte,uint32_t def);
void SendByteSPI(uint8_t B,uint32_t def);



#endif /* INC_SPI_H_ */
