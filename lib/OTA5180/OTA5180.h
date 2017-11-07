/**
 * File: OTA5180.h
 * Author: Raghava Kumar
 */

#include "stm32f7xx_hal.h"

class OTA5180
{
  
public:
  OTA5180()
   : initialized_(false)
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

};
