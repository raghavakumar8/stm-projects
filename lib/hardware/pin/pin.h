/**
 * File: pin.h
 * Author: Raghava Kumar
 */

#ifndef PIN_H
#define PIN_H

#include "hardware.h"

enum Mode
{
  INPUT = 0,
  OUTPUT = 1,
  ALTERNATE_FUNCTION = 2,
  ANALOG = 3
};

enum Signal
{
  PUSH_PULL = 0,
  OPEN_DRAIN = 1
};

enum Speed
{
  LOW = 0,
  MEDIUM = 1,
  HIGH = 2,
  VERY_HIGH = 3
};

enum Resistor
{
  NONE = 0,
  PULLUP = 1,
  PULLDOWN = 2
};

class Pin
{

public:
  Pin(GPIO_TypeDef *port, uint8_t pin)
    : port_(port)
    , pin_(pin)
    , mode_(INPUT)
    , speed_(LOW)
    , signal_(PUSH_PULL)
    , resistor_(NONE)
  {
  }

  ~Pin()
  {
  }

  /**
   * @brief configure pin characteristics
   **/
  void configure(Mode mode = INPUT, Speed speed = LOW, Signal signal = PUSH_PULL, Resistor resistor = NONE);

  /**
   * @brief read the (digital) pin value
   * @return true if HIGH, false if LOW
   **/
  bool read();

  /**
   * @brief set the pin state
   **/
  void write(bool value);

  /**
   * @brief configure the pin for an alternate function
   **/
  void setAlternateFunction(uint8_t af);

private:
  void enableClock();

  GPIO_TypeDef *port_;
  uint8_t pin_;

  Mode mode_;
  Speed speed_;
  Signal signal_;
  Resistor resistor_;
};

#endif // PIN_H
