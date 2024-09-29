#ifndef Controller_Oled_0_91Inch_H__
#define Controller_Oled_0_91Inch_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4


class Controller_Oled_0_91Inch_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  Adafruit_SSD1306 * quocOled091;
  
  Controller_Oled_0_91Inch_Data();
  ~Controller_Oled_0_91Inch_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_Oled_0_91Inch_Data device_Controller_Oled_0_91Inch;
#endif