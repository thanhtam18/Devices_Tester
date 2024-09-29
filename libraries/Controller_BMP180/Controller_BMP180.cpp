#include "Controller_BMP180.h"
#include "debugkxn.h"

Controller_BMP180_Data::Controller_BMP180_Data()
{
  this->nameDevice = "BMP180";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x77);
  this->Add_HsCode(152);
  // Add your code here

}

Controller_BMP180_Data::~Controller_BMP180_Data()
{
  
}

bool Controller_BMP180_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  //int x = int(this->bmp->readTemperature());
  this->valueDevice += String(bmp.readTemperature(),2);
  this->valueDevice += String(char(223));
  this->valueDevice += "C";
  this->valueDevice += String(bmp.readPressure());
  this->valueDevice += "Pa";

  return true;
}

bool Controller_BMP180_Data::init()
{
  deInit();

  // this->bmp = new Adafruit_BMP085();

  bmp.begin();
  // Add your code here
  
  return 1;
}

bool Controller_BMP180_Data::deInit()
{
  // if(this->bmp != NULL)
  // {
  //   free(this->bmp);
  //   this->bmp = NULL;
  // }

  return 1;
}

Controller_BMP180_Data device_Controller_BMP180;