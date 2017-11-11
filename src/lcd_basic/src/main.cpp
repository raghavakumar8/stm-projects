/**
 * File: main.c
 * Author: Raghava Kumar
 */

#include "lcd_basic/include/main.h"
#include "ota5180.h"

int main(void)
{
  HAL_Init();

  OTA5180 lcd;
  lcd.initialize();
  lcd.backlight(false);

  while (1)
  {
  }
}
