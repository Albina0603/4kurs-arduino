const int ledPin = 2;        
const int buzzerPin = 8;     
const int potPin = A0; 
const int lightSensorPin = A1;

int threshold = 400;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int lightValue = analogRead(lightSensorPin); 
  Serial.println(lightValue); 
  if (lightValue < threshold) {
    
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
  
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(100); 
}
