/**
 * File: OTA5180.cpp
 * Author: Raghava Kumar
 */

#include "OTA5180.h"

void OTA5180::initialize()
{
  // Configure backlight
  __HAL_RCC_GPIOK_CLK_ENABLE();
  GPIOK->MODER |= 1 << 6; // Output
  GPIOK->OTYPER |= 1 << 3; // Open Drain

  initialized_ = true;
}

void OTA5180::backlight(bool on)
{
  if (on)
  {
    GPIOK->ODR |= 1 << 3;
  }
  else
  {
    GPIOK->ODR &= !(1 << 3);
  }
}
