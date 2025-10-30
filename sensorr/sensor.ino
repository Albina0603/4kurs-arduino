#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int tempPin = A3;
const int photoPin = A1;
const int ledPin = 2;
const int buzzerPin = 8;
const int potPin = A0;

LiquidCrystal_I2C lcd(0x27, 16, 2); 

float tempThreshold = 30.0;
int lightThreshold = 300;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.println("Initializing LCD...");
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int tempRaw = analogRead(tempPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  int lightValue = analogRead(photoPin);
  int potValue = analogRead(potPin);
  tempThreshold = map(potValue, 0, 1023, 20, 40);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lightValue);
  lcd.print("    ");

  if (temperature > tempThreshold || lightValue < lightThreshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
