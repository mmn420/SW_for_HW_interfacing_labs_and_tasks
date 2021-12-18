/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"

unsigned char keypad_lut[4][3] = {
  {
    0x06,
    0x5B,
    0x4F
  },
  {
    0x66,
    0x6D,
    0x7D
  },
  {
    0x07,
    0x7F,
    0x6F
  },
  {
    0x3F,
    0x3F,
    0x3F
  }
};
unsigned char is_pressed = 0;
unsigned char key;
void delay30ms() {
  unsigned int i;
  for (i = 0; i < 30000; i++) {}
}
void Keypad_init() {
  GPIO_EnableClock('B');
  for (int i = 0; i < 4; i++) {
    GPIO_Init('B', i, INPUT, PULL_UP);

  }
  for (int i = 4; i <= 6; i++) {
    GPIO_Init('B', i, OUTPUT, PUSH_PULL);
    GPIO_WritePin('B', i, 1);
  }
}
void Keypad_manage() {
  if (is_pressed == 0) {
    for (int i = 4; i <= 6; i++) {
      GPIO_WritePin('B', i, 0);
      for (int j = 0; j < 4; j++) {
        if (GPIO_ReadPin('B', j) == 0) {
          delay30ms();
          if (GPIO_ReadPin('B', j) == 0) {
            is_pressed = 1;
            key = keypad_lut[j][i - 4];
            KeypadCallouts_KeyPressNotificaton();
          }
        }

      }
      GPIO_WritePin('B', i, 1);

    }
  }
}

unsigned char Keypad_GetKey() {
  if (is_pressed == 1) {
    is_pressed = 0;
    return key;
  } else
    return -1;
}