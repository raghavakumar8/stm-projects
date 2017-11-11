/**
 * File: i2c.h
 * Author: Raghava Kumar
 */

#ifndef I2C_H
#define I2C_H

#include "hardware.h"

class I2C
{
  
public:
  I2C(I2C_TypeDef* i2c)
   : i2c_(i2c)
   , initialized_(false)
  {
  }

  ~I2C()
  {
  }

  /**
   * @brief initialize peripheral registers
   **/
  void initialize();

private:
  I2C_TypeDef* i2c_;
  bool initialized_;

};

#endif // I2C_H
