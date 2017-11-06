/**
 * File: interrupts.c
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"
#include "tap_freq/include/main.h"

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void EXTI15_10_IRQHandler()
{
  __HAL_GPIO_EXTI_CLEAR_FLAG(GPIO_PIN_11);
  static uint32_t last_tick_ms = 0;
  static char first_tap = 1;

  if (first_tap == 1)
  {
    last_tick_ms = HAL_GetTick();
    first_tap = 0;
  }
  else
  {
    delay_ms = HAL_GetTick() - last_tick_ms;
    first_tap = 1;
  }
}
