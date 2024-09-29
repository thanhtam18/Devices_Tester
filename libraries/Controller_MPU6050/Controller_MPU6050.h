#ifndef Controller_MPU6050_H__
#define Controller_MPU6050_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

#define OUTPUT_READABLE_ACCELGYRO

class Controller_MPU6050_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  MPU6050 * accelgyro;
  TwoWire * pWire;
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  bool blinkState = false;

  
  Controller_MPU6050_Data();
  ~Controller_MPU6050_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_MPU6050_Data device_Controller_MPU6050;
#endif