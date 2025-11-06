#include<Servo.h>
const int tempPin = A5;
const int servoPin = 3;
const float TEMP_LIMIT = 28.0;
const float VREF = 5.0;

Servo windowServo;

void setup (){
  Serial.begin(9600);
  windowServo.attach(servoPin);
  windowServo.write(0); 
  Serial.println("System ready.Monitoring temperature...");
}

void loop () {
  int sensorValue=analogRead(tempPin);
  float voltage = sensorValue * (VREF/1023.0);
  float temperature = voltage * 100.0;
  
  Serial.print("Temperature:");
  Serial.print(temperature);
  Serial.println("C");
  windowServo.write(90);
  
  if(temperature > TEMP_LIMIT){
    windowServo.write(90);
    Serial.println("Window opened!");
    
  }
  
  else {    
    windowServo.write(0);
    Serial.println("Window closed!");
  }
  delay(500);
}