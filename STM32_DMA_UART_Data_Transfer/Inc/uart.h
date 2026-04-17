/*
 * uart.h
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f446xx.h"

#define USART2EN			17
#define USART_TE			3
#define USART_UE			13

#define USART2_SR_TXE		7
#define USART2_SR_RXNE		5

void UART2_GPIO_PinConfig();
void UART2_Init(void);
void UART_SendChar(char ch);
void UART_SendString(char *str);

#endif /* UART_H_ */
