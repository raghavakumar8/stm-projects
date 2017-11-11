/**
 * File: interrupts.c
 * Author: Raghava Kumar
 */

#include "lcd_basic/include/main.h"

void SysTick_Handler(void)
{
  HAL_IncTick();
}
