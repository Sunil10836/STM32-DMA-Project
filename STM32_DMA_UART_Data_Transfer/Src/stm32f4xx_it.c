/*
 * stm32f4xx_it.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */


#include "stm32f446xx.h"

#define is_Half_Transfer_IT()			( DMA1->HISR & (1 << 20) )
#define is_Full_Transfer_IT()			( DMA1->HISR & (1 << 21) )
#define is_Transfer_Error_IT()			( DMA1->HISR & (1 << 19) )
#define is_Direct_Mode_Error_IT()		( DMA1->HISR & (1 << 16) )
#define is_FIFO_Error_IT()				( DMA1->HISR & (1 << 18) )

//Callbacks
extern void DMA_Half_Transfer_Complete_Callback(void);
extern void DMA_Full_Transfer_Complete_Callback(void);
extern void DMA_Transfer_Error_Callback(void);
extern void DMA_Direct_Mode_Error_Callback(void);
extern void DMA_FIFO_Error_Callback(void);

void clear_exit_pending_bit(void)
{
	if(EXTI->PR & (1 << 13))
	{
		//Clear Pending bit
		EXTI->PR |= (1 << 13);
	}
}

void EXTI15_10_IRQHandler(void)
{
	USART_TypeDef *pUART2;
	pUART2 = USART2;

	//Send USART2_Tx DMA Request to DMA1 Controller
	pUART2->CR3 |= (1 << 7);

	//Clear Pending Bit
	clear_exit_pending_bit();

}


//IRQ Handler for DMA1 Stream6 Global Interrupt
void DMA1_Stream6_IRQHandler(void)
{
	if(is_Half_Transfer_IT())
	{
		//Clear Interupt flag
		DMA1->HIFCR |= (1 << 20);

		DMA_Half_Transfer_Complete_Callback();
	}
	else if(is_Full_Transfer_IT())
	{
		//Clear Interupt flag
		DMA1->HIFCR |= (1 << 21);

		DMA_Full_Transfer_Complete_Callback();
	}
	else if(is_Transfer_Error_IT())
	{
		//Clear Interupt flag
		DMA1->HIFCR |= (1 << 19);

		DMA_Transfer_Error_Callback();
	}
	else if(is_Direct_Mode_Error_IT())
	{
		//Clear Interupt flag
		DMA1->HIFCR |= (1 << 18);

		DMA_Direct_Mode_Error_Callback();
	}
	else if(is_FIFO_Error_IT())
	{
		//Clear Interupt flag
		DMA1->HIFCR |= (1 << 16);

		DMA_FIFO_Error_Callback();
	}
}

