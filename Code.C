#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<SoftwareSerial.h>


SoftwareSerial B(10,11);    //10-RX,  11-TX
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int value = 0;
float voltage;
int smith=13;
int data;
void setup()
{
  B.begin(9600);
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
  Serial.begin(9600);
  delay(500);
  pinMode(13,INPUT);
}
void loop()
{
  lcd.setCursor(1, 0);
  delay(1000);
  lcd.clear();

//voltage reading
  value = analogRead(A0);
  voltage = value * 7.4/1023;
 int smith_val=digitalRead(smith);
 if(smith_val == 0)
 {
  Serial.print("Voltage= ");
  Serial.println(voltage);

  lcd.setCursor(1, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage);

  B.print("Hello");
  B.println(voltage);
 }
 else if(smith_val == 1)
 {
  Serial.println("Switch is OFF");
 }
}