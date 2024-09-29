#include "Controller_ADXL345.h"
#include "debugkxn.h"

Controller_ADXL345_Data::Controller_ADXL345_Data()
{
  this->nameDevice = "ADXL345";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x53);
  this->Add_HsCode(143);
  // Add your code here

}

Controller_ADXL345_Data::~Controller_ADXL345_Data()
{
  
}

bool Controller_ADXL345_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  Z_out = Z_out/256;

  this->valueDevice += String(X_out, 2);
  this->valueDevice += ":";
  this->valueDevice += String(Y_out, 2);
  this->valueDevice += ":";
  this->valueDevice += String(Z_out, 2);
  return true;
}

bool Controller_ADXL345_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  return 1;
}

bool Controller_ADXL345_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_ADXL345_Data device_Controller_ADXL345;