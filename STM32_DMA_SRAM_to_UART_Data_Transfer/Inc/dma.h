/*
 * dma.h
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#ifndef DMA_H_
#define DMA_H_

#include "stm32f446xx.h"

#define DMA1EN				21

//DMA1 Interrupts
#define DMEIE				1
#define TEIE				2
#define HTIE				3
#define TCIE				4

void DMA1_Init(void);
void DMA1_Stream6_Enable(void);
void DMA1_Interrupt_Config(void);

#endif /* DMA_H_ */
