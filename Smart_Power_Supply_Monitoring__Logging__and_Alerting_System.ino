#include "DS3231.h"
DS3231  rtc(SDA, SCL);
const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0x0;
double currentValue = 0;
void setup()
{
  Serial.begin(9600);
  rtc.begin();
  rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(12, 22, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(10, 4, 2019);   // Set the date to January 1st, 2014
}
void loop()
{
  digitalWrite(2, HIGH);
  Serial.println("\n");
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  Serial.print(rtc.getTimeStr());
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  Serial.print("\nRaw Sensor Value = " );
  Serial.print(adcValue);
  Serial.print("\nADC Value =     ");
  Serial.print(adcValue);
  Serial.print("\nVoltage(mV) = ");
  Serial.print(adcVoltage,3);
  Serial.print("\nV in mV =       ");
  Serial.print(adcVoltage,1);
  Serial.print("\nCurrent = ");
  Serial.print(currentValue,3);
  Serial.print("\nCurrent =       ");
  Serial.print(currentValue,2);
  delay(500);
}
