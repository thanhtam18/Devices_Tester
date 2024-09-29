#include "Controller_Oled_0_91Inch.h"
#include "debugkxn.h"

Controller_Oled_0_91Inch_Data::Controller_Oled_0_91Inch_Data()
{
  this->nameDevice = "Oled 0.91Inch";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  this->Add_HsCode(947);
  // Add your code here

}

Controller_Oled_0_91Inch_Data::~Controller_Oled_0_91Inch_Data()
{
  
}

bool Controller_Oled_0_91Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "Running!";
  
  return true;
}

bool Controller_Oled_0_91Inch_Data::init()
{
  deInit();
  // Add your code here
  this->quocOled091 = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  this->quocOled091->begin(SSD1306_SWITCHCAPVCC, 0x3C);

  this->quocOled091->display();

  delay(2000);

  return 1;
}

bool Controller_Oled_0_91Inch_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_Oled_0_91Inch_Data device_Controller_Oled_0_91Inch;