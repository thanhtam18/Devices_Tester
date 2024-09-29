#ifndef Controller_Oled_1_3Inch_H__
#define Controller_Oled_1_3Inch_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 5

class Controller_Oled_1_3Inch_Data: public Model_I2C_Device{
  public:

  // Add your declare here
  Adafruit_SH1106 * quocOled;

  Controller_Oled_1_3Inch_Data();
  ~Controller_Oled_1_3Inch_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_Oled_1_3Inch_Data device_Controller_Oled_1_3Inch;
#endif