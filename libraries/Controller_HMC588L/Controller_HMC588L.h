#ifndef Controller_HMC588L_H__
#define Controller_HMC588L_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "HMC5883L.h"

class Controller_HMC588L_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  MPU6050 * accelgyro1;
  HMC5883L * mag;
  TwoWire * pWire1;

  int16_t mx, my, mz;

  Controller_HMC588L_Data();
  ~Controller_HMC588L_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_HMC588L_Data device_Controller_HMC588L;
#endif