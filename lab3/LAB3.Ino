const int redLed = 5;
const int yellowLed = 6;
const int greenLed = 7;
const int startBtn = 13;
const int stopBtn = 12;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(startBtn, INPUT_PULLUP);  // Кнопка "Старт"
  pinMode(stopBtn, INPUT_PULLUP);   // Кнопка "Стоп"
}

void loop() {
  if (digitalRead(startBtn) == LOW) {   // Если нажата кнопка "Старт"
    digitalWrite(redLed, HIGH);
    delay(3000);
    if (digitalRead(stopBtn) == LOW) return;

    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    if (digitalRead(stopBtn) == LOW) return;

    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(3000);
    if (digitalRead(stopBtn) == LOW) return;

    digitalWrite(greenLed, LOW);
  }
}