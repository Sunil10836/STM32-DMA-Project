/*
 * main.h
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f446xx.h"
#include "button.h"
#include "uart.h"
#include "dma.h"

extern char data[50];

//Callbacks
void DMA_Half_Transfer_Complete_Callback(void);
void DMA_Full_Transfer_Complete_Callback(void);
void DMA_Transfer_Error_Callback(void);
void DMA_Direct_Mode_Error_Callback(void);
void DMA_FIFO_Error_Callback(void);


#endif /* MAIN_H_ */
