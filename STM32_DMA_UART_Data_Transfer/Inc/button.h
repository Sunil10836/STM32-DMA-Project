/*
 * button.h
 *
 *  Created on: Apr 17, 2026
 *      Author: Sunil Sutar
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "stm32f446xx.h"

#define GPIOAEN				0
#define GPIOCEN				2
#define SYSCFGEN			14

void Button_Init(void);

#endif /* BUTTON_H_ */
