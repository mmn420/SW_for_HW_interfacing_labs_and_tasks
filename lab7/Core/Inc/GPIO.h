/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H

#include "stm32f401xc.h"

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

#define NVIC_ISER GPIO_REG (0xE000E100, 0x00)
#define RCC_APB2ENR GPIO_REG(0x40023800, 0x44)
#define SYSCFG_EXTICR1 GPIO_REG(0x40013800, 0x08)
#define EXTI_IMR GPIO_REG(0x40013C00, 0x00)
#define EXTI_RTSR GPIO_REG(0x40013C00, 0x08)
#define EXTI_FTSR GPIO_REG(0x40013C00, 0x0C)
#define EXTI_PR GPIO_REG(0x40013C00, 0x14)
#define GPIOA_ODR GPIO_REG(0x40020000, 0x14)


void GPIO_EnableClock(unsigned char PORT_ID);

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum);

#endif /* GPIO_H */
