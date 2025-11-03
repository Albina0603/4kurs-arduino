const int trig = 13;
const int echo = 12;
const int redLed = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int buzzerPin = 8;

long duration;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  noTone(buzzerPin);

  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
 
  duration = pulseIn(echo, HIGH, 30000); 
  
  if (duration == 0) {
   
    Serial.println("Нет сигнала");
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    noTone(buzzerPin);
    delay(200);
    return;
  }

  distance = duration * 0.034 / 2; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  noTone(buzzerPin);

  
  if (distance > 30) {
    digitalWrite(greenLed, HIGH);
    tone(buzzerPin, 1000, 100);
    delay(1000);
  } 
  else if (distance <= 30 && distance > 15) {
    digitalWrite(yellowLed, HIGH);
    tone(buzzerPin, 1200, 100);
    delay(300);
  } 
  else if (distance <= 15) {
    digitalWrite(redLed, HIGH);
    tone(buzzerPin, 1500, 100);
    delay(100);
  }

  noTone(buzzerPin); 
}

