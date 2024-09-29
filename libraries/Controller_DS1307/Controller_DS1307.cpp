#include "Controller_DS1307.h"
#include "debugkxn.h"

Controller_DS1307_Data::Controller_DS1307_Data()
{
  this->nameDevice = "DS1307";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  this->Add_HsCode(1518);
  // Add your code here

}

Controller_DS1307_Data::~Controller_DS1307_Data()
{
  
}

bool Controller_DS1307_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  DateTime now = rtc.now();

  this->valueDevice += String(now.hour(), DEC);
  this->valueDevice += ":";
  this->valueDevice += String(now.minute(), DEC);
  this->valueDevice += ":";
  this->valueDevice += String(now.second(), DEC); 

  // Serial.print(now.hour(), DEC);
  // Serial.print(':');
  // Serial.print(now.minute(), DEC);
  // Serial.print(':');
  // Serial.print(now.second(), DEC);
  // Serial.println();
  return true;
}

bool Controller_DS1307_Data::init()
{
  deInit();
  // Add your code here
  rtc.begin();

  return 1;
}

bool Controller_DS1307_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_DS1307_Data device_Controller_DS1307;