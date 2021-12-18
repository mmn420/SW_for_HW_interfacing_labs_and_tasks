/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"

#include "Keypad.h"

unsigned char sevenSegHex[10] = {
  0x3F,
  0x06,
  0x5B,
  0x4F,
  0x66,
  0x6D,
  0x7D,
  0x07,
  0x7F,
  0x6F
};

void KeypadCallouts_KeyPressNotificaton() {
  unsigned char display = Keypad_GetKey();
  for (int i = 0; i < 10; i++) {
    if (sevenSegHex[i] == display) {
      for (int j = 0; j < 7; j++) {
        GPIO_WritePin('A', j, (sevenSegHex[i] & (1 << j)) >> j);
      }
    }
  }
}

int main(void) {
  GPIO_EnableClock('A');

  for (int i = 0; i < 7; i++) {
    GPIO_Init('A', i, OUTPUT, PUSH_PULL);
  }
  Keypad_init();
  while (1) {

    Keypad_manage();

  }
  return 0;

}
