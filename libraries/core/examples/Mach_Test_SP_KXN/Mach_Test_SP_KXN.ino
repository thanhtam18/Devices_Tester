#include "debugkxn.h"
#include "Manager_Content.h"
#include "Manager_I2C_Devices.h"
#include "Btn_Process.h"
#include "view_LCD_Text.h"

// #include "Controller_Sieu_Am.h"
#include "Controller_DHT.h"
#include "Controller_Test_Snippet.h"
// #include <Controller/Controller_DHT.h>
#include "Controller_SR04.h"
#include "Controller_LM35.h"
#include "Controller_DS18B20.h"


// // Include I2C Device
// #include "Controller_MKL_I2C_Motor.h"
#include "Controller_MKL_RTC.h"
// #include "Controller_Test_I2C_Snippet.h"
#include "Controller_MKL_RTC_Quoc.h"
#include "Controller_MKL_RTC_Quoc_Pointer.h"
#include "Controller_Oled_1_3Inch.h"
#include "Controller_Oled_0_96Inch.h"
#include "Controller_Oled_0_91Inch.h"
#include "Controller_SHT30.h"
#include "Controller_MPU6050.h"
#include "Controller_HMC588L.h"
#include "Controller_BMP180.h"
#include "Controller_AHT20.h"
#include "Controller_BH1750.h"
#include "Controller_MMA8452.h"
#include "Controller_ADXL345.h"
#include "Controller_L3G4200D.h"
#include "Controller_DS1307.h"
#include "Controller_LSM303DLHC.h"
#include "Controller_MS5611.h"

void AddManagerContent_Device()
{
  manager_Content.my_Devices_List.add(&Manager_I2C_Device);
  manager_Content.my_Devices_List.add(&Dht_Device);
  // manager_Content.my_Devices_List.add(&sieuAm_Device);
  manager_Content.my_Devices_List.add(&SR04_Device);
  manager_Content.my_Devices_List.add(&LM35_Device);
  manager_Content.my_Devices_List.add(&DS18B20_Device);

}

void Add_I2C_Device()
{
  // Manager_I2C_Device.myI2C_Devices_List.add(&MKL_I2C_Motor_Device);
  //Manager_I2C_Device.myI2C_Devices_List.add(&RTC_Device);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Test_I2C_Snippet);
  //Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MKL_RTC_Quoc);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MPU6050);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MKL_RTC_Quoc_Pointer);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_1_3Inch);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_0_96Inch);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_0_91Inch);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_SHT30);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_HMC588L);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_BMP180);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_AHT20);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_BH1750);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MMA8452);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_ADXL345);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_L3G4200D);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_DS1307);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_LSM303DLHC);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MS5611);

}

// ---------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  buttonInit();
  debug("Start!");
  View_LCD_Text_Init();
  manager_Content.begin();
}
void loop()
{
  buttonLoop();

  manager_Content.getData();
  runSerialLife();
}
// ---------------------------------------------------------------------------------------

// Hàm cho nút nhấn Start
void Start_do_1_Click()
{
  debugln("1 Click: Do it!");
  manager_Content.init();
  manager_Content.timeInterval = 250;
}
void Start_do_2_Click()
{
  debugln("2 Click: Re Start!");
  manager_Content.deInit();
  manager_Content.timeInterval = 250;
}

// Hàm cho nút nhấn Up
void Up_do_0_Click()
{

  manager_Content.deInit();
  manager_Content.Choseen_Menu++;
  manager_Content.timeInterval = 250;

  debug("0 Click: Menu");
  debugln(manager_Content.Choseen_Menu);
}
void Up_do_1_Click()
{
  manager_Content.deInit();
  manager_Content.Choseen_Menu++;
  manager_Content.timeInterval = 250;

  debug("1 Click: Menu");
  debugln(manager_Content.Choseen_Menu);
}

// Hàm cho nút nhấn Down
void Down_do_0_Click()
{
  debug("1 Click: Menu");
  debugln(manager_Content.Choseen_Menu);

  manager_Content.deInit();
  manager_Content.Choseen_Menu--;
  manager_Content.timeInterval = 250;
}
void Down_do_1_Click()
{
  debug("1 Click: Menu");
  debugln(manager_Content.Choseen_Menu);

  manager_Content.deInit();
  manager_Content.Choseen_Menu--;
  manager_Content.timeInterval = 250;
}

unsigned long timeSeriallife = millis();

void runSerialLife()
{
  if (millis() - timeSeriallife >= 1000)
  {
    timeSeriallife = millis();
    Serial.println("I live!");
  }
}
