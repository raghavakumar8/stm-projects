/**
 * File: check.h
 * Author: Raghava Kumar
 */

#ifndef CHECK_H
#define CHECK_H

#include "hardware.h"

namespace check {

/**
 * @brief check if the condition is true
 * @details if true, do nothing. if false, stall
 * @param condition to check for
 **/
void assert(bool condition);

/**
 * @brief wait until the bits equal the value
 * @param reg pointer to the register containing the bits
 * @param mask the bits to compare
 * @param value expected value of the register
 **/
void waitForBits(volatile uint32_t* reg, uint32_t mask, uint32_t value);

}  // namespace check

#endif  // CHECK_H
