#ifndef Controller_MKL_RTC_Quoc_H__
#define Controller_MKL_RTC_Quoc_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "RTClib.h" 

class Controller_MKL_RTC_Quoc_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  RTC_DS3231 rtc;

  Controller_MKL_RTC_Quoc_Data();
  ~Controller_MKL_RTC_Quoc_Data();
  
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_MKL_RTC_Quoc_Data device_Controller_MKL_RTC_Quoc;
#endif