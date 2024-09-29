#include "Controller_LSM303DLHC.h"
#include "debugkxn.h"

Controller_LSM303DLHC_Data::Controller_LSM303DLHC_Data()
{
  this->nameDevice = "LSM303DLHC";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x1E);
  this->Add_HsCode(1518);
  // Add your code here

}

Controller_LSM303DLHC_Data::~Controller_LSM303DLHC_Data()
{
  
}

bool Controller_LSM303DLHC_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  cmps.read();
  
  float heading = cmps.heading();

  this->valueDevice += "Heading:";
  this->valueDevice += String(heading);
  

  return true;
}

bool Controller_LSM303DLHC_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  cmps.init();
  cmps.enableDefault();
  cmps.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  cmps.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
  return 1;
}

bool Controller_LSM303DLHC_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_LSM303DLHC_Data device_Controller_LSM303DLHC;