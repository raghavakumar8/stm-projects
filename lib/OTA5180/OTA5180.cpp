/**
 * File: OTA5180.cpp
 * Author: Raghava Kumar
 */

#include "OTA5180.h"

void OTA5180::initialize()
{
  __HAL_RCC_GPIOK_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

  initialized_ = true;
}

void OTA5180::backlight(bool on)
{
  if (on)
  {
    HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_SET);
  }
  else
  {
    HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_RESET);
  }
}
