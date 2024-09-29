#include "Controller_L3G4200D.h"
#include "debugkxn.h"

Controller_L3G4200D_Data::Controller_L3G4200D_Data()
{
  this->nameDevice = "L3G4200D";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x69);
  this->Add_HsCode(196);
  // Add your code here

}

Controller_L3G4200D_Data::~Controller_L3G4200D_Data()
{
  
}

bool Controller_L3G4200D_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice += String(l3g4200d.getGyroValuesX());
  this->valueDevice += ":";
  this->valueDevice += String(l3g4200d.getGyroValuesY());
  this->valueDevice += ":";
  this->valueDevice += String(l3g4200d.getGyroValuesZ());

  return true;
}

bool Controller_L3G4200D_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  l3g4200d.setupL3G4200D(2000);

  return 1;
}

bool Controller_L3G4200D_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_L3G4200D_Data device_Controller_L3G4200D;