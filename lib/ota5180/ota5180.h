/**
 * File: OTA5180.h
 * Author: Raghava Kumar
 */

#ifndef OTA5180_H
#define OTA5180_H

#include "hardware.h"
#include "pin/pin.h"
#include "i2c/i2c.h"

class OTA5180
{
  
public:
  OTA5180()
   : initialized_(false)
   , backlight_(GPIOK, 3)
  {
  }

  ~OTA5180()
  {
  }

  /**
   * @brief initialize peripheral modules
   **/
  void initialize();

  /**
   * @brief turn backlight on or off
   **/
  void backlight(bool on);

private:
  bool initialized_;

  Pin backlight_;
};

#endif // OTA5180_H
