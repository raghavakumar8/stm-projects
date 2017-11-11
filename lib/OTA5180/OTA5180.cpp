/**
 * File: OTA5180.cpp
 * Author: Raghava Kumar
 */

#include "ota5180.h"

void OTA5180::initialize()
{
  backlight_.configure(OUTPUT, LOW, PUSH_PULL, NONE);
  initialized_ = true;
}

void OTA5180::backlight(bool on)
{
  if (!initialized_) return;

  backlight_.write(on);
}
