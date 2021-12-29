/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
void Blink_Interrupt (void){
	*GPIOA_ODR ^= (1<<1);
	*EXTI_PR |= 1;
}
int main(void) {
  GPIO_EnableClock(0);
  GPIO_Init(0, 0, INPUT, PULL_UP);
  GPIO_Init(0, 1, OUTPUT, PUSH_PULL);
  *RCC_APB2ENR |= (1<<14);
  *SYSCFG_EXTICR1 &= ~(0X0F);
  *EXTI_IMR |= 1;
  *EXTI_FTSR |= 1;
  *NVIC_ISER |= (1<<6);


  while (1) {


  }
  return 0;

}
