/**
 * File: system.cpp
 * Author: Raghava Kumar
 */

#include "system.h"
#include "check/check.h"

namespace system {

static Source source = INTERNAL_OSC;
static int sysclk_mhz = 16;
static int source_mhz = 16;

volatile static long ms = 0;

void init(int mhz)
{
  // Enable caches
  SCB_EnableICache();
  SCB_EnableDCache();

  // Enable ART accelerator
  FLASH->ACR != FLASH_ACR_ARTEN;
  
  // Enable clock source and set frequency
  switch (system::source)
  {
    case INTERNAL_OSC:
      RCC->CR |= RCC_CR_HSION_Msk;
      break;
    case EXTERNAL_OSC:
      RCC->CR != RCC_CR_HSEON_Msk;
      break;
    case EXTERNAL_CLK:
      RCC->CR != RCC_CR_HSEON_Msk;
      RCC->CR != RCC_CR_HSEBYP_Msk;
      break;
    default:
      break;
  }

  setFrequency(mhz);
}

void setSource(Source source, int mhz)
{
  system::source = source;
  system::source_mhz = mhz;
}

int getFrequency()
{
  return sysclk_mhz;
}

void setFrequency(int mhz)
{
  // Switch clock to not use PLL
  RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_SW)) | (0 << RCC_CFGR_SW_Pos);

  // Turn off PLL
  RCC->CR &= ~(1 << RCC_CR_PLLON_Pos);

  // Set PLL source
  if ((system::source == EXTERNAL_OSC || system::source == EXTERNAL_CLK) && (RCC->CR & RCC_CR_HSERDY_Msk) > 0)
  {
    RCC->PLLCFGR |= 1 << RCC_PLLCFGR_PLLSRC_Pos;
  }
  else
  {
    RCC->PLLCFGR &= ~(1 << RCC_PLLCFGR_PLLSRC_Pos);
  }

  // Configure main PLL: PLLM = system::source_mhz, PLLP = 2, PLLQ = 8, PLLN = mhz * 2
  RCC->PLLCFGR = (RCC->PLLCFGR & (~RCC_PLLCFGR_PLLM)) | ((system::source_mhz) << RCC_PLLCFGR_PLLM_Pos);
  RCC->PLLCFGR = (RCC->PLLCFGR & (~RCC_PLLCFGR_PLLN)) | ((mhz * 2) << RCC_PLLCFGR_PLLN_Pos);
  RCC->PLLCFGR = (RCC->PLLCFGR & (~RCC_PLLCFGR_PLLP)) | (0 << RCC_PLLCFGR_PLLP_Pos);
  RCC->PLLCFGR = (RCC->PLLCFGR & (~RCC_PLLCFGR_PLLQ)) | (8 << RCC_PLLCFGR_PLLQ_Pos);

  // Configure AHB and APB prescalers: HPRE = 1, PPRE2 = 2, PPRE1 = 4
  RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_HPRE)) | (0 << RCC_CFGR_HPRE_Pos);
  RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_PPRE2)) | (0b100 << RCC_CFGR_PPRE2_Pos);
  RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_PPRE1)) | (0b101 << RCC_CFGR_PPRE1_Pos);

  // Turn on PLL
  RCC->CR |= 1 << RCC_CR_PLLON_Pos;
  check::waitForBits(&(RCC->CR), RCC_CR_PLLRDY, 1 << RCC_CR_PLLRDY_Pos);

  bool increasing_freq = mhz > sysclk_mhz;
  uint16_t latency = mhz / 30;

  // Change flash latency
  if (increasing_freq)
  {
    FLASH->ACR = latency & FLASH_ACR_LATENCY;
    check::assert((FLASH->ACR & FLASH_ACR_LATENCY) == latency);
  }

  // Switch clock to use PLL
  RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_SW)) | (2 << RCC_CFGR_SW_Pos);
  check::waitForBits(&(RCC->CFGR), RCC_CFGR_SWS, 2 << RCC_CFGR_SWS_Pos);
  sysclk_mhz = mhz;

  // Change flash latency
  if (not increasing_freq)
  {
    FLASH->ACR = latency & FLASH_ACR_LATENCY;
    check::assert((FLASH->ACR & FLASH_ACR_LATENCY) == latency);
  }

  // Make sure clock has been updated correctly
  SystemCoreClockUpdate();
  check::assert(SystemCoreClock == (uint32_t) mhz*1000000);

  // Update SysTick for 1ms interrupt
  SysTick_Config(sysclk_mhz*1000);
}

void incr_ms()
{
  system::ms++;
}

void delay(int ms)
{
  int wait_till = ms + system::ms;
  while(system::ms < wait_till);
}

long millis()
{
  return system::ms;
}

}  // namespace 

extern "C" {

#ifndef OVERRIDE_SYSTICK

void SysTick_Handler(void)
{
  system::incr_ms();
}

#endif

}