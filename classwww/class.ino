const int tempPin = A4;    
const int photorPin = A1;     
const int ledPin = 2;   
const int buzzerPin = 8; 
const int potPin = A0;

float tempThreshold = 30.0;
int lightThreshold = 300;  

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
 
  int tempRaw = analogRead(tempPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100; 
  
  int lightValue = analogRead(photorPin);
  
  int potValue = analogRead(potPin);
  float tempThreshold = map(potValue, 0, 1023, 20, 40);
  
  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.print(" C, Light: ");
  Serial.println(lightValue);
  Serial.print(", Temp Threshold: ");
  Serial.println(tempThreshold);
  
  if (temperatureC > tempThreshold || lightValue < lightThreshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  
  delay(1000); 
}