#include "Controller_Oled_0_96Inch.h"
#include "debugkxn.h"

Controller_Oled_0_96Inch_Data::Controller_Oled_0_96Inch_Data()
{
  this->nameDevice = "Oled_0.96Inch";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  this->Add_HsCode(617);
  // Add your code here

}

Controller_Oled_0_96Inch_Data::~Controller_Oled_0_96Inch_Data()
{
  
}

bool Controller_Oled_0_96Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "Oled 0.96Inch is Running";
  
  return true;
}

bool Controller_Oled_0_96Inch_Data::init()
{
  deInit();

  this->quocOled096 = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  this->quocOled096->begin(SSD1306_SWITCHCAPVCC, 0x3C);

  this->quocOled096->display();

  delay(2000);

  // Add your code here
  
  return 1;
}

bool Controller_Oled_0_96Inch_Data::deInit()
{
  if(this->quocOled096 != NULL)
  {
    free(this->quocOled096);
    this->quocOled096 = NULL;
  }

  return 1;
}

Controller_Oled_0_96Inch_Data device_Controller_Oled_0_96Inch;