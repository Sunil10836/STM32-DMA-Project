/*
 * button.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#include "button.h"

void Button_Init(void)
{
	//PC13 --> User Button

	//1. Enable GPIOC Clock
	RCC->AHB1ENR |= (1 << GPIOCEN);

	//2. GPIOC13 Pin in Input Mode
	GPIOC->MODER &= ~(0x3 << 2 * 13);	//00 -> Input Mode

	//3.Enable Interrupt on PC13 Pin
	EXTI->IMR |= (1 << 13);

	//4. Enable the Clock for SYSCFG
	RCC->APB2ENR |= (1 << SYSCFGEN);

	//5. Configure SYSCFG EXTICR4
	SYSCFG->EXTICR[3] &= ~(0xF << 4);	//Clearing bits
	SYSCFG->EXTICR[3] |= (0x2 << 4);	//set => 0010 => 0x2 for PC13

	//6. Configure Edge Detection
	EXTI->FTSR |= (1 << 13);		//Falling Edge

	//7. Enable IRQ related to that GPIO pin in NVIC of the processor
	NVIC_EnableIRQ(EXTI15_10_IRQn);

}
