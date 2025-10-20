const int ledPin = 2;        
const int buzzerPin = 8;     
const int potPin = A0; 
const int lightSensorPin = A1;
const int ButtonPin = 11;
const int hysteresis = 15;

int threshold = 400;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode (ButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  int lightValue = analogRead(lightSensorPin); 
  int ButtonState = digitalRead(ButtonPin); 
  Serial.println("Light:");
  Serial.println(lightValue); 
  if (lightValue < threshold) {
    
    if (ButtonState == HIGH && lightValue < threshold){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
  
    digitalWrite(buzzerPin, LOW);
  }

  delay(100); 
  }
}
