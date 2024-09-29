#include "view_LCD_Text.h"
#include "Manager_I2C_Devices.h"
/* Cài đặt màn hình LCD */
LiquidCrystal_I2C lcd(0x27, 16, 2); // Cài đặt địa chỉ 0x27, hiển thị 16 cột 2 dòng
unsigned long curentTimeShowLCD = 0;
void View_LCD_Text_Init()
{
    lcd.init();          // Khởi động màn hình. Bắt đầu cho phép Arduino sử dụng màn hình
    lcd.backlight();     // Bật đèn nền
    lcd.clear();         // Xóa màn hình
    lcd.setCursor(3, 0); // Cột 3 dòng 0
    lcd.print("TrungKuro");
    lcd.setCursor(1, 1); // Cột 1 dòng 0
    lcd.print("Hello yours");
}

void ShowLCD(String nameDevice__, String valueDevice__)
{
    if (millis() - curentTimeShowLCD >= 100)
    {
        curentTimeShowLCD = millis();
        lcd.clear();         // Xóa màn hình
        lcd.setCursor(0, 0); // Cột 2 dòng 0
        lcd.print(nameDevice__);
        lcd.setCursor(0, 1); // Cột 2 dòng 0
        lcd.print(valueDevice__);
    }
}