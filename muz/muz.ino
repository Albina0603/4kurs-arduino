const int ledPin = 9;
const int buzzerPin = 8;
const int shockPin = A3;


int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int noteDur = 200; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(shockPin, INPUT);
}

void playSong() {
  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, melody[i]);
    digitalWrite(ledPin, HIGH);
    delay(100);

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
}

void loop() {
  int shockValue = digitalRead(shockPin);

  if (shockValue == HIGH) {
    playSong();
  }
}
  