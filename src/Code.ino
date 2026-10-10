
#include "EmonLib.h"
EnergyMonitor emon1;

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int Relay_PIN = 7;
const int LED_PIN = 6;

void setup()
{
  pinMode(Relay_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Start safely with relay OFF
  digitalWrite(Relay_PIN, LOW);
  digitalWrite(LED_PIN, HIGH);

  Serial.begin(9600);

  emon1.voltage(A0, 187, 1.7);

  lcd.begin(20, 4);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("VOLTAGE PROTECTION");

  Serial.println("Voltage Protection System Started");
  Serial.println("---------------------------------");
}

void loop()
{
  emon1.calcVI(20, 2000);

  float Voltage = emon1.Vrms;
  const char* status;

  lcd.setCursor(0, 2);
  lcd.print("VOLTAGE = ");
  lcd.print(Voltage, 1);
  lcd.print(" V       ");

  if (Voltage >= 180 && Voltage <= 250)
  {
    digitalWrite(Relay_PIN, HIGH);
    digitalWrite(LED_PIN, LOW);

    status = "NORMAL";
    lcd.setCursor(0, 3);
    lcd.print("STATUS: NORMAL      ");
  }
  else if (Voltage > 250)
  {
    digitalWrite(Relay_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);

    status = "OVER VOLTAGE";
    lcd.setCursor(0, 3);
    lcd.print("STATUS: OVER VOLTAGE");
  }
  else
  {
    digitalWrite(Relay_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);

    status = "UNDER VOLTAGE";
    lcd.setCursor(0, 3);
    lcd.print("STATUS: UNDER VOLTAGE");
  }

  // Display relay status on LCD
  lcd.setCursor(0, 1);
  lcd.print("RELAY: ");
  lcd.print(digitalRead(Relay_PIN) == HIGH ? "ON " : "OFF");
  lcd.print("             ");

  // Display all information on Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(Voltage, 1);
  Serial.print(" V | Protection Status: ");
  Serial.print(status);
  Serial.print(" | Relay Status: ");
  Serial.println(digitalRead(Relay_PIN) == HIGH ? "ON" : "OFF");

  Serial.println("---------------------------------");

  delay(200);
}
