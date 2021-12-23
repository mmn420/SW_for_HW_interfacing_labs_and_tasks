#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
#define SET_2BITS(REG,BIT) (REG|=(1<<BIT*2))

int main(void) {
	GPIO_Init('B',3, INPUT, PUSH_PULL);
	SET_2BITS(GPIOB_PUPDR,3); // set input pin 3 as pull up resistor
	for (int i =5; i<=7; i++){
		 GPIO_Init('B', i, OUTPUT, PUSH_PULL);
	 }
	int color = 1;
  while (1) {
	  int button_state = GPIO_ReadPin('B', 3); // save the state of the push button
	  	 for (int i=0; i<1000; i++){} //delay
	  	 if (button_state && !(GPIO_ReadPin('B', 3))){ //check the state of the push button
	  		for (int i =5; i<=7; i++){
	  				 GPIO_WritePin('B', i, 0); 	  			//reset the pins
	  			 }
	  			if(color == 8){
	  				color = 0;
	  			}
	  			GPIO_WritePin('B', 5, color&1);
	  			GPIO_WritePin('B', 6, (color>>1)&1);
	  			GPIO_WritePin('B', 7, (color>>2)&1);
	  			color++;
	  	 }
	  }
  return 0;
}
