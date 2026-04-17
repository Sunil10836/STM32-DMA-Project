/*
 * main.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */


#include "main.h"

char data[] = "Hello World\r\n";

int main()
{
	Button_Init();
	UART2_Init();
	DMA1_Init();
	DMA1_Interrupt_Config();
	DMA1_Stream6_Enable();

	UART_SendString(data);

	while(1)
	{

	}

	return 0;
}

//Callbacks
void DMA_Half_Transfer_Complete_Callback(void)
{

}

void DMA_Full_Transfer_Complete_Callback(void)
{
	USART_TypeDef *pUART2;
	pUART2 = USART2;

	DMA_Stream_TypeDef *pSTREAM6;
	pSTREAM6 = DMA1_Stream6;

	//Program Number of Data Items to send
	uint32_t len = sizeof(data);
	pSTREAM6->NDTR = len;

	// Clear USART2_Tx DMA Request to DMA1 Controller
	pUART2->CR3 &= ~(1 << 7);

	//Enable DMA1 Stream6
	DMA1_Stream6_Enable();

	//Send USART2_Tx DMA Request to DMA1 Controller
	//pUART2->CR3 |= (1 << 7);
}

void DMA_Transfer_Error_Callback(void)
{
	while(1);
}

void DMA_Direct_Mode_Error_Callback(void)
{
	while(1);
}

void DMA_FIFO_Error_Callback(void)
{
	while(1);
}

