#include "GPIO.h"
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int counter = 0;
void Decrement_Interrupt(void){
	counter--;
		if (counter < 0){
			counter = 9;
		}
		*EXTI_PR |= 2;
}

void Increment_Interrupt (void){
	counter++;
	if (counter >= 10){
		counter = 0;
	}
	*EXTI_PR |= 1;
}
int main(void) {
  GPIO_EnableClock(0);
  GPIO_EnableClock(1);
  GPIO_Init(0, 0, INPUT, PULL_UP);
  GPIO_Init(0, 1, INPUT, PULL_UP);
  for (int i = 0; i<7; i++){
	  GPIO_Init(1,i, OUTPUT, PUSH_PULL);
  }
  *RCC_APB2ENR |= (1<<14);
  *SYSCFG_EXTICR1 &= ~(0X0F);
  *SYSCFG_EXTICR1 &= ~(0X0F<<4);
  *EXTI_IMR |= 3;
  *EXTI_FTSR |= 3;
  *NVIC_ISER = (3<<6);
  int race_count;
  while (1) {
	  *NVIC_ICER = (3<<6); //disable the ISR before asigning the value of the counter
	  race_count = counter;
	  *NVIC_ISER = (3<<6); //re-enable the ISR
	  for (unsigned char i=0; i<7; i++){
	  				GPIO_WritePin(1, i, (sevenSegHex[race_count] & (1 << i)) >> i);
	  			}


  }
  return 0;

}
