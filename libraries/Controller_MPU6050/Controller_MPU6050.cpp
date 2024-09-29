#include "Controller_MPU6050.h"
#include "debugkxn.h"

Controller_MPU6050_Data::Controller_MPU6050_Data()
{
  this->nameDevice = "MPU6050";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  this->Add_HsCode(142);
  // Add your code here

}

Controller_MPU6050_Data::~Controller_MPU6050_Data()
{
  
}

bool Controller_MPU6050_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  this->accelgyro->getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  #ifdef OUTPUT_READABLE_ACCELGYRO
        // display tab-separated accel/gyro x/y/z values
    this->valueDevice += String(ax);
    this->valueDevice += ":";
    this->valueDevice += String(ay);
    this->valueDevice += ":";
    this->valueDevice += String(az);
  #endif

  return true;
}

bool Controller_MPU6050_Data::init()
{
  deInit();
  // Add your code here
  this->accelgyro = new MPU6050();
  this->pWire = new TwoWire();

  this->pWire->begin();
  this->pWire->beginTransmission(0x68);
  
  

  // #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  //       Wire.begin();
  //   #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  //       Fastwire::setup(400, true);
  //   #endif

  this->accelgyro->initialize();

  this->accelgyro->setXGyroOffset(220);
  this->accelgyro->setYGyroOffset(76);
  this->accelgyro->setZGyroOffset(-85);

  return 1;
}

bool Controller_MPU6050_Data::deInit()
{
  // Add your code here
  if(this->accelgyro != NULL){
    free(this->accelgyro);
    this->accelgyro = NULL;
  }

  if(this->pWire != NULL){
    free(this->pWire);
    this->pWire = NULL;
  }
  return 1;
}

Controller_MPU6050_Data device_Controller_MPU6050;