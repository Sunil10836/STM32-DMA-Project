/*
 * uart.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#include "uart.h"
#include "button.h"

/*
 * PA2 => USART2_Tx
 * PA3 => USART2_Rx
 * AF  => AF7
 */

void UART2_GPIO_PinConfig()
{
	//1. Enable GPAIOA Clock
	RCC->AHB1ENR |= (1 << GPIOAEN);

	//2. Configure PA2 as USART2_Tx Pin
	//2.1 Set PA2 in Alt Fun Mode
	GPIOA->MODER &= ~(0x3 << 2 * 2);		//clearing
	GPIOA->MODER |= (0x2 << 2 * 2);			//Alt Fun Mode

	//2.2 Select AF7 for PA2 as USART2_Tx
	GPIOA->AFR[0] &= ~(0xF << 4 * 2);		//Clearing
	GPIOA->AFR[0] |= (0x7 << 4 * 2);		//AF7

	//3. Configure PA3 as USART2_Rx Pin
	//3.1 Set PA3 in Alt Fun Mode
	GPIOA->MODER &= ~(0x3 << 2 * 3);		//clearing
	GPIOA->MODER |= (0x2 << 2 * 3);			//Alt Fun Mode

	//3.2 Select AF7 for PA3 as USART2_Rx
	GPIOA->AFR[0] &= ~(0xF << 4 * 3);		//Clearing
	GPIOA->AFR[0] |= (0x7 << 4 * 3);		//AF7

	//4. Enable or Disable Pull-up
	GPIOA->PUPDR |= (0x1 << 2 * 2);			//enable pull-up for PA2
	GPIOA->PUPDR |= (0x1 << 2 * 3);			//enable pull-up for PA3

}

void UART2_Init(void)
{
	/**** UART2 GPIO Pin Configuration ********/
	UART2_GPIO_PinConfig();

	/**** UART2  Configuration ***************/
	//1. Enable Clock for UART2
	RCC->APB1ENR |= (1 << USART2EN);

	//2. Configure Baudrate
	USART2->BRR = 0x8B;			//115200 Buadrate

	//3. Configure Data width and number of stop bits
	//no configuration needed we use default values

	//4. Enable USART2_Tx in UART CR
	USART2->CR1 |= (1 << USART_TE);

	//5. Enable UART Peripheral
	USART2->CR1 |= (1 << USART_UE);

}

void UART_SendChar(char ch)
{
	//Wait until TXE Flag in USART_SR Register set
	while(! (USART2->SR & (1 << USART2_SR_TXE)));

	USART2->DR = (ch & 0xFF);
}

void UART_SendString(char *str)
{
	while(*str)
	{
		UART_SendChar(*str++);
	}
}
