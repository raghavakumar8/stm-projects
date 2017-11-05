/**
 * File: main.c
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"

volatile uint32_t delay_ms = 1000;
volatile uint32_t last_tick_ms = 0;
volatile char first_tap = 1;

int main(void)
{
  HAL_Init();

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
    HAL_Delay(delay_ms);
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void HAL_MspInit(void)
{
  __HAL_RCC_GPIOI_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  // Set up LED
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  // Set up Pushbutton
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler()
{
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

  __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_All);
  __HAL_GPIO_EXTI_CLEAR_FLAG(GPIO_PIN_All);
}
