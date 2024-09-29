#include "Controller_HMC588L.h"
#include "debugkxn.h"

Controller_HMC588L_Data::Controller_HMC588L_Data()
{
  this->nameDevice = "HMC588L";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x1E);
  this->Add_HsCode(205);
  // Add your code here

}

Controller_HMC588L_Data::~Controller_HMC588L_Data()
{
  
}

bool Controller_HMC588L_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  this->mag->getHeading(&mx, &my, &mz);

  float heading = atan2(my, mx);
    if(heading < 0)
      heading += 2 * M_PI;

  this->valueDevice += String(heading * 180/M_PI);

  
  return true;
}

bool Controller_HMC588L_Data::init()
{
  deInit();
  // Add your code here
  this->accelgyro1 = new MPU6050();
  this->mag = new HMC5883L();
  this->pWire1 = new TwoWire();



  this->pWire1->begin();
  this->accelgyro1->setI2CMasterModeEnabled(false);

  this->accelgyro1->setI2CBypassEnabled(true);
  this->accelgyro1->setSleepEnabled(false);

  this->mag->initialize();

  return 1;
}

bool Controller_HMC588L_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_HMC588L_Data device_Controller_HMC588L;