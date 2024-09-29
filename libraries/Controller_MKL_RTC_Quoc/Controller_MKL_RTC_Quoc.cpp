#include "Controller_MKL_RTC_Quoc.h"
#include "debugkxn.h"

Controller_MKL_RTC_Quoc_Data::Controller_MKL_RTC_Quoc_Data()
{
  this->nameDevice = "QuocRTC";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  this->Add_HsCode(1518);
  // Add your code here

}

Controller_MKL_RTC_Quoc_Data::~Controller_MKL_RTC_Quoc_Data()
{
  
}

bool Controller_MKL_RTC_Quoc_Data::getData()
{
  // Add your code here
  DateTime now = rtc.now();

  this->valueDevice = "";

    this->valueDevice += String(now.hour(), DEC);
    this->valueDevice += ":";
    this->valueDevice += String(now.minute(), DEC);
    this->valueDevice += ":";
    this->valueDevice += String(now.second(), DEC);
    // Serial.println();

  return true;
}

bool Controller_MKL_RTC_Quoc_Data::init()
{
  deInit();
  // Add your code here
  
  if (! rtc.begin()) {
    abort();
  }

  if (rtc.lostPower()) {
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  return 1;
}

bool Controller_MKL_RTC_Quoc_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_MKL_RTC_Quoc_Data device_Controller_MKL_RTC_Quoc;