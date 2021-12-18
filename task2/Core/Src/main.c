#include "stm32f401cc_interface.h"

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

#define SET_2BITS(REG,BIT) (REG|=(1<<BIT*2))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define CLEAR_2BITS(REG,BIT) (REG&=(~(3<<BIT*2)))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

int main(void) {
	SET_BIT(RCC_AHB1ENR,1);
	CLEAR_2BITS(GPIOB_MODER,3); //set pin 3 as input
	SET_2BITS(GPIOB_MODER,5); //set pin 5 as output
	SET_2BITS(GPIOB_MODER,6); //set pin 6 as output
	SET_2BITS(GPIOB_MODER,7); // set pin 7 as output
	SET_2BITS(GPIOB_PUPDR,3); // set input pin 3 as pull up resistor
	CLEAR_BIT(GPIOB_OTYPER,5); // set output pin 5 as push-pull
	CLEAR_BIT(GPIOB_OTYPER,6);
	CLEAR_BIT(GPIOB_OTYPER,7);
	int color = 1;

  while (1) {
	 int button_state = GPIOB_IDR & (1<<3); // save the state of the push button
	 for (int i=0; i<10000; i++){} //delay
	 if (button_state && BIT_IS_CLEAR(GPIOB_IDR,3)){ //check the state of the push button
		 	GPIOB_ODR&=(~(7<<5)); //reset the ODR
			if(color == 8){
				color = 0;
			}
			GPIOB_ODR |= color <<5; //set the color to the ODR
			color++;
	 }

}
  return 0;
}
