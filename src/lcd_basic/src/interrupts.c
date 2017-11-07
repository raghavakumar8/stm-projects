/**
 * File: interrupts.c
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"
#include "lcd_basic/include/main.h"

void SysTick_Handler(void)
{
  HAL_IncTick();
}
