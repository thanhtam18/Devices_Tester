#ifndef Controller_DS18B20_H__
#define Controller_DS18B20_H__
#include "dataAdapter.h"

// include your Libraries here
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 7

class Controller_DS18B20_Data: public Data_Adapter{
  public:
  // Add your declare here
  // OneWire oneWire;
  // DallasTemperature sensor;

  Controller_DS18B20_Data();
  virtual ~Controller_DS18B20_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_DS18B20_Data DS18B20_Device;
#endif