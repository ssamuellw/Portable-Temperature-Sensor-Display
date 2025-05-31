#include <LiquidCrystal.h>
int rs = 3;
int en = 4;
int d4 = 5;
int d5 = 6;
int d6 = 8;
int d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT (sensePin, Type);
float humidty;
float tempC;
float tempF;
int setTime = 250;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
HT.begin();
delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
humidty = HT.readHumidity();
tempC = HT.readTemperature();
tempF = HT.readTemperature(true);
lcd.setCursor(0,0);
lcd.print("Humidty:");
lcd.print(humidty);
lcd.setCursor(0,1);
lcd.print("Temp:");
lcd.print(tempC);
Serial.print("Humidity: ");
Serial.print(humidty);
Serial.print("Temp in Celcius: ");
Serial.print(tempC);
Serial.print("Temp in fara: ");
Serial.println(tempF);
delay(setTime);
}
