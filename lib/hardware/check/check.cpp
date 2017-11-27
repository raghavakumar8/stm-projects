/**
 * File: check.cpp
 * Author: Raghava Kumar
 */

#include "check.h"
#include "pin/pin.h"

namespace check{

void assert(bool condition)
{
  if (not condition)
  {
    Pin led(GPIOI, 1);
    led.configure(OUTPUT, LOW, PUSH_PULL, NONE);

    led.write(true);
    while(true);
  }
}

void waitForBits(volatile uint32_t* reg, uint32_t mask, uint32_t value)
{
  while ((*reg & mask) != (value & mask));
}

}