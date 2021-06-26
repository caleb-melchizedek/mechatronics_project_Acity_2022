#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Welcome to Acity");
  Serial.begin(9600);
  }

void loop(){
  
  }
