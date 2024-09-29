#include "Controller_DS18B20.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

Controller_DS18B20_Data::Controller_DS18B20_Data()
{
  this->nameDevice = "DS18B20";
  this->timeInterval = 100;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_DS18B20_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  sensor.requestTemperatures();
  this->valueDevice += String(sensor.getTempCByIndex(0));
  this->valueDevice += String(char(223));
  this->valueDevice += "C";

  return true;
}

bool Controller_DS18B20_Data::init()
{
  deInit();
  // Add your code here
  // OneWire oneWire(ONE_WIRE_BUS);
  // DallasTemperature sensor(&oneWire);
  // this->sensor = new DallasTemperature(&oneWire);
  // sensor.begin();
  sensor.begin();
  
  return 1;
}

bool Controller_DS18B20_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_DS18B20_Data DS18B20_Device;