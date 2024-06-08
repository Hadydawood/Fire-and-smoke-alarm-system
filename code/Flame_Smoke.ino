#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
# define flame 3
# define smoke A0
# define buzzer 4
int Val = 0;
int sensorValue =0;
void setup() {
lcd.init(); // or some librarys are lcd.init();
lcd.backlight();
pinMode(flame,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}
void loop()
{
Val =digitalRead(flame);
 lcd.setCursor(0,0);  
 lcd.print("Flame:");
if (Val==1)
{
  lcd.setCursor(6,0);
  lcd.print("YES");
  tone(buzzer,110,1000);
}
else 
{
   lcd.setCursor(6,0);
  lcd.print("NO ");
  digitalWrite(buzzer, LOW);
}
sensorValue = analogRead(smoke);
Serial.println(sensorValue); 
 lcd.setCursor(0,1);  
 lcd.print("Smoke:");
if(sensorValue > 580) 
{
  lcd.setCursor(6,1);
  lcd.print("YES");
 tone(buzzer,880,1000);
}
else 
{
   lcd.setCursor(6,1);
  lcd.print("NO ");
  digitalWrite(buzzer, LOW);
}
}
