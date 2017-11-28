/**
 * File: system.h
 * Author: Raghava Kumar
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include "hardware.h"

namespace system {

enum Source
{
  INTERNAL_OSC = 0,
  EXTERNAL_OSC = 1,
  EXTERNAL_CLK = 2
};

/**
 * @brief initialize the system (caches, clock, systick)
 * @param mhz desired core frequency
 **/
void init(int mhz);

/**
 * @brief specify which clock source to use for the PLL --
 *        only effective if called before system::init()
 * @param source clock source to use (enum)
 * @param mhz frequency of the source clock in MHz
 **/
void setSource(Source source, int mhz);

/**
 * @brief return the current core frequency in MHz
 **/
int getFrequency();

/**
 * @brief change the system clock frequency
 * @details can be called at any time after system::init()
 * @param desired core frequency
 **/
void setFrequency(int MHz);

/**
 * @brief delay for given number of ms
 **/
void delay(int ms);

/**
 * @brief get the number of milliseconds since program start
 **/
long millis();

}  // namespace system

#endif  // SYSTEM_H
