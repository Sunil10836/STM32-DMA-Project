/*
 * dma.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#include "dma.h"
#include "main.h"

void DMA1_Init(void)
{
	DMA_Stream_TypeDef *pSTREAM6;
	pSTREAM6 = DMA1_Stream6;

	USART_TypeDef *pUART2;
	pUART2 = USART2;

	//1. Enable DMA Clock
	RCC->AHB1ENR |= (1 << DMA1EN);

	//2. Identify DMA Channel and Stream for UART Peripheral
	// Channel 4 and Stream 6
	pSTREAM6->CR &= ~(0x7 << 25);	//clearing
	pSTREAM6->CR |= (0x4 << 25);	//channel 4

	//3. Program Source Address
	pSTREAM6->M0AR = (uint32_t) data;

	//4. Program Destination Address
	pSTREAM6->PAR = (uint32_t) &pUART2->DR;

	//5. Program Number of Data Items to send
	uint32_t len = sizeof(data);
	pSTREAM6->NDTR = len;

	//6. The direction of data transfer : p2m or m2m or m2p => m2p (DMA_SxCR) bit 6 and 7
	pSTREAM6->CR |= (1 << 6);
	pSTREAM6->CR &= ~(1 << 7);	//optional

	//7. Program the src and dest data width
	pSTREAM6->CR &= ~(0x3 << 13);			//optional
	pSTREAM6->CR &= ~(0x3 << 11);			//optional

	//7.1 Enable Memory auto Increment
	pSTREAM6->CR |= (1 << 10);

	//8. Select DMA Mode : Direct or FIFO Mode => FIFO Mode
	pSTREAM6->FCR |= (1 << 2);

	//9. Select the FIFO threshold
	pSTREAM6->FCR &= ~(0x3 << 0);		//clearing
	pSTREAM6->FCR |= (0x3 << 0);		//set threshold : full fifo

	//10. Enable or Disable DMA Circular Mode : by default disabled

	//11. Single transfer or burst transfer => Single transfer -> by default

	//12. Configure Stream Priority Level : Low : 00

}

void DMA1_Stream6_Enable(void)
{
	DMA_Stream_TypeDef *pSTREAM6;
	pSTREAM6 = DMA1_Stream6;

	//Enable the DMA Steam
	pSTREAM6->CR |= (1 << 0);
}

void DMA1_Interrupt_Config(void)
{
	DMA_Stream_TypeDef *pSTREAM6;
	pSTREAM6 = DMA1_Stream6;

	//1. Enable Half Transfer interrupt(HTIE)
	pSTREAM6->CR |= (1 << HTIE);

	//2. Enable Transfer Complete interrupt(TCIE)
	pSTREAM6->CR |= (1 << TCIE);

	//3. Enable Transfer Error interrupt(TEIE)
	pSTREAM6->CR |= (1 << TEIE);

	//4. Enable  Direct mode error interrupt
	pSTREAM6->CR |= (1 << DMEIE);

	//5. Enable FIFO Overrun/Underrun Error Interrupt
	pSTREAM6->FCR |= (1 << 7);

	//6. Enable IRQ for DMA1 Stream6 Global Interrupt in NVIC
	NVIC_EnableIRQ(DMA1_Stream6_IRQn);

}
