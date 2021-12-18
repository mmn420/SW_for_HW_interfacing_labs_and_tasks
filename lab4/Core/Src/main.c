#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	for (int i=0; i<=8; i++){
		GPIO_Init('A', i , OUTPUT, PUSH_PULL);
	}
  while (1) {
	  //0
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 0);


	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //1
	  GPIO_WritePin('A', 0, 0);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 0);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 0);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //2
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 0);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //3
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //4
	  GPIO_WritePin('A', 0, 0);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 0);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //5
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 0);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //6
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 0);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //7
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 0);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 0);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //8
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //9
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
  }
  return 0;
}
