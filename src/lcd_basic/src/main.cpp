/**
 * File: main.c
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"
#include "lcd_basic/include/main.h"
#include "OTA5180.h"

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
