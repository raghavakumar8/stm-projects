/**
 * File: main.c
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"
#include "tap_freq/include/main.h"

volatile uint32_t delay_ms = 1000;

int main(void)
{
  HAL_Init();

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
    HAL_Delay(delay_ms);
  }
}
