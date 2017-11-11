/**
 * File: pin.cpp
 * Author: Raghava Kumar
 */

#include "pin.h"

void Pin::configure(Mode mode, Speed speed, Signal signal, Resistor resistor)
{
  enableClock();

  // Write registers
  port_->MODER |= mode << (pin_ << 1);
  port_->OTYPER |= signal << pin_;
  port_->OSPEEDR |= speed << (pin_ << 1);
  port_->PUPDR |= resistor << (pin_ << 1);

  // Update fields
  mode_ = mode;
  speed_ = speed;
  signal_ = signal;
  resistor_ = resistor;
}

bool Pin::read()
{
  return (port_->IDR & (1 << pin_)) > 0;
}

void Pin::write(bool value)
{
  if (value) port_->ODR |= 1 << pin_;
  else port_->ODR &= !(1 << pin_);
}

void Pin::setAlternateFunction(uint8_t af)
{
  if (pin_ < 8) port_->AFR[0] |= (af & 0xf) << (pin_ << 2);
  else port_->AFR[1] |= (af & 0xf) << (pin_ << 2);
}

void Pin::enableClock()
{
  if (port_ == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
  else if (port_ == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
  else if (port_ == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
  else if (port_ == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
  else if (port_ == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
  else if (port_ == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE();
  else if (port_ == GPIOG) __HAL_RCC_GPIOG_CLK_ENABLE();
  else if (port_ == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE();
  else if (port_ == GPIOI) __HAL_RCC_GPIOI_CLK_ENABLE();
  else if (port_ == GPIOJ) __HAL_RCC_GPIOJ_CLK_ENABLE();
  else if (port_ == GPIOK) __HAL_RCC_GPIOK_CLK_ENABLE();
}
