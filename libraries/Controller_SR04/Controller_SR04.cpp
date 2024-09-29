#include "Controller_SR04.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_SR04_Data::Controller_SR04_Data()
{
  this->nameDevice = "SR04";
  this->timeInterval = 100;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_SR04_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  sr04.usonic_transmit();
  this->valueDevice += String(sr04.forLoopFunction(), 2);
  this->valueDevice += " (Cm)";
  
  return true;
}

bool Controller_SR04_Data::init()
{
  deInit();
  // Add your code here
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  return 1;
}

bool Controller_SR04_Data::deInit()
{
  // Add your code here
  pinMode(trig, INPUT);
  pinMode(echo, INPUT);

  return 1;
}

Controller_SR04_Data SR04_Device;