#include "Controller_SHT30.h"
#include "debugkxn.h"

Controller_SHT30_Data::Controller_SHT30_Data()
{
  this->nameDevice = "SHT3x";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x44);
  this->Add_HsCode(1582);
  // Add your code here

}

Controller_SHT30_Data::~Controller_SHT30_Data()
{
  
}

bool Controller_SHT30_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->sht->UpdateData();
  this->valueDevice += String(this->sht->GetTemperature());
  this->valueDevice += String(char(223));
  this->valueDevice += "C";
  this->valueDevice += String(this->sht->GetRelHumidity());
  this->valueDevice += "%";

  return true;
}

bool Controller_SHT30_Data::init()
{
  deInit();
  // Add your code here
  this->sht = new SHT3x();
  this->sht->Begin();

  
  return 1;
}

bool Controller_SHT30_Data::deInit()
{
  // Add your code here
  if(this->sht != NULL){
    free(this->sht);
    this->sht = NULL;
  }
  return 1;
}

Controller_SHT30_Data device_Controller_SHT30;