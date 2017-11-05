/**
 * File: main.c
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"

#define LED_PIN                GPIO_PIN_1
#define LED_GPIO_PORT          GPIOI
#define LED_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOI_CLK_ENABLE()

int main(void)
{
  HAL_Init();

  LED_GPIO_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

  while (1)
  {
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
    HAL_Delay(1000);
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}
