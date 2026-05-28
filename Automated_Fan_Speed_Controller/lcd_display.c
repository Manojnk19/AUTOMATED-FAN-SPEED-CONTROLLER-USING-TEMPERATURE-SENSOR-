#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void lcd_init()
{
    lcd.begin();
    lcd.backlight();
}

void display_temperature(int temp)
{
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");
}
