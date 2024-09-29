#include "Controller_AHT20.h"
#include "debugkxn.h"

Controller_AHT20_Data::Controller_AHT20_Data()
{
  this->nameDevice = "AHT20";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x38);
  this->Add_HsCode(1437);
  // Add your code here

}

Controller_AHT20_Data::~Controller_AHT20_Data()
{
  
}

bool Controller_AHT20_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  this->valueDevice += String(temp.temperature);
  this->valueDevice += String(char(223));
  this->valueDevice += "C";
  this->valueDevice += ";";
  this->valueDevice += String(humidity.relative_humidity);
  this->valueDevice += "%";
  
  return true;
}

bool Controller_AHT20_Data::init()
{
  deInit();
  // Add your code here
  aht.begin();

  return 1;
}

bool Controller_AHT20_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_AHT20_Data device_Controller_AHT20;