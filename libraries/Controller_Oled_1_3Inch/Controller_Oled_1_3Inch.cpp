#include "Controller_Oled_1_3Inch.h"
#include "debugkxn.h"

Controller_Oled_1_3Inch_Data::Controller_Oled_1_3Inch_Data()
{
  this->nameDevice = "Oled_1.3Inch";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  this->Add_HsCode(618);
  // Add your code here

}

Controller_Oled_1_3Inch_Data::~Controller_Oled_1_3Inch_Data()
{
  
}

bool Controller_Oled_1_3Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "Oled 1.3Inch is Running";
  
  return true;
}

bool Controller_Oled_1_3Inch_Data::init()
{
  deInit();

  this->quocOled = new Adafruit_SH1106(OLED_RESET);

  this->quocOled->begin(SH1106_SWITCHCAPVCC, 0x3C);

  this->quocOled->display();

  delay(2000);
  // Add your code here
  
  return 1;
}

bool Controller_Oled_1_3Inch_Data::deInit()
{
  if(this->quocOled != NULL)
  {
    free(this->quocOled);
    this->quocOled = NULL;
  }

  return 1;
}

Controller_Oled_1_3Inch_Data device_Controller_Oled_1_3Inch;