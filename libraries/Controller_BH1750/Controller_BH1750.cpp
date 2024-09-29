#include "Controller_BH1750.h"
#include "debugkxn.h"

Controller_BH1750_Data::Controller_BH1750_Data()
{
  this->nameDevice = "BH1750";
  this->timeInterval = 100;
  this->valueDevice = "No device";
  this->Add_AddressList(0x23);
  this->Add_HsCode(159);
  // Add your code here

}

Controller_BH1750_Data::~Controller_BH1750_Data()
{
  
}

bool Controller_BH1750_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  
  float lux = lightMeter.readLightLevel();

  this->valueDevice += String(lux, 2);
  this->valueDevice += "lux";
  return true;
}

bool Controller_BH1750_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  lightMeter.begin();

  return 1;
}

bool Controller_BH1750_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_BH1750_Data device_Controller_BH1750;