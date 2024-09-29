#include "Controller_MS5611.h"
#include "debugkxn.h"

Controller_MS5611_Data::Controller_MS5611_Data()
{
  this->nameDevice = "MS5611";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x77);
  this->Add_HsCode(1518);
  // Add your code here

}

Controller_MS5611_Data::~Controller_MS5611_Data()
{
  
}

bool Controller_MS5611_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  this->hbqMS5611->read();
  // Serial.print("Temperature: ");
  // Serial.print(MS5611.getTemperature(), 2);
  // Serial.print("\tPressure: ");
  // Serial.print(MS5611.getPressure(), 2);
  // Serial.println();
  // delay(1000);

  this->valueDevice += String(this->hbqMS5611->getTemperature(), 2);
  this->valueDevice += String(char(223));
  this->valueDevice += "C";
  this->valueDevice += String(this->hbqMS5611->getPressure(), 2);
  this->valueDevice += "mb";

  
  return true;
}

bool Controller_MS5611_Data::init()
{
  deInit();
  // Add your code here
  this->hbqMS5611 = new MS5611(0x77);

  this->hbqMS5611->begin();

  return 1;
}

bool Controller_MS5611_Data::deInit()
{
  // Add your code here
  if(this->hbqMS5611 != NULL){
    free(this->hbqMS5611);
    this->hbqMS5611 = NULL;
  }
  return 1;
}

Controller_MS5611_Data device_Controller_MS5611;