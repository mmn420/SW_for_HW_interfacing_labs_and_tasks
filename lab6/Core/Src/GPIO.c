/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */

#include "GPIO.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

#define RCC_AHB1ENR GPIO_REG(0x40023800, 0x30)

#define GPIOA_MODER GPIO_REG(0x40020000, 0x00)
#define GPIOA_IDR GPIO_REG(0x40020000, 0x10)
#define GPIOA_ODR GPIO_REG(0x40020000, 0x14)
#define GPIOA_OTYPER GPIO_REG(0x40020000, 0x04)
#define GPIOA_PUPDR GPIO_REG(0x40020000, 0x0C)


#define GPIOB_MODER GPIO_REG(0x40020400, 0x00)
#define GPIOB_IDR GPIO_REG(0x40020400, 0x10)
#define GPIOB_ODR GPIO_REG(0x40020400, 0x14)
#define GPIOB_OTYPER GPIO_REG(0x40020400, 0x04)
#define GPIOB_PUPDR GPIO_REG(0x40020400, 0x0C)

unsigned int *GPIO_lut[2][5] = {{GPIOA_MODER,GPIOA_IDR, GPIOA_ODR, GPIOA_OTYPER, GPIOA_PUPDR},
		{GPIOB_MODER,GPIOB_IDR, GPIOB_ODR, GPIOB_OTYPER,GPIOB_PUPDR} };



void GPIO_EnableClock(unsigned char PORT_ID) {

	  *RCC_AHB1ENR |= (0x01 << PORT_ID);
  }

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {
      // Configure moder register for pin direction
      *GPIO_lut[PORT_ID][0] &= ~(0x03 << 2 * PinNum);
      *GPIO_lut[PORT_ID][0] |= PinMode << 2 * PinNum;

      *GPIO_lut[PORT_ID][3] &= ~(1 << PinNum);
      *GPIO_lut[PORT_ID][3] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      *GPIO_lut[PORT_ID][4] &= ~(0x03 << 2 * PinNum);
      *GPIO_lut[PORT_ID][4] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
  }

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;
      if (((*GPIO_lut[PORT_ID][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
        	*GPIO_lut[PORT_ID][2] |= (1 << PinNum);
        } else {
        	*GPIO_lut[PORT_ID][2] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
  return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char data = 0;
      data = (*GPIO_lut[PORT_ID][1] & (1 << PinNum)) >> PinNum;
  return data;
}
