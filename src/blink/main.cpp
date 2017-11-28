/**
 * File: main.cpp
 * Author: Raghava Kumar
 */

#include "hardware.h"
#include "pin/pin.h"
#include "system/system.h"

int main(void)
{
  system::init(25);

  Pin led(GPIOI, 1);
  led.configure(OUTPUT, LOW, PUSH_PULL, NONE);

  while (1)
  {
    led.toggle();
    system::delay(100);
  }
}
