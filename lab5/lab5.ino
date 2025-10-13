const int ledPin = 2;        // Светодиод
const int buzzerPin = 8;     // Зуммер
const int buttonPin = 4;     // Кнопка
const int potPin = A5;       // Потенциометр

bool armed = false;          // Флаг охраны
bool alarmTriggered = false; // Флаг сработавшей тревоги

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Подтяжка к питанию
  Serial.begin(9600);
}

void loop() {
  // Проверяем нажатие кнопки с защитой от дребезга
  if (digitalRead(buttonPin) == LOW) {
    armed = !armed;           // Переключаем охрану
    alarmTriggered = false;   // Сбрасываем тревогу при переключении
    Serial.print("Armed = ");
    Serial.println(armed ? "TRUE" : "FALSE");
    delay(300);
  }

  // Если охрана включена и тревога ещё не сработала — запускаем
  if (armed && !alarmTriggered) {
    int potValue = analogRead(potPin);
    unsigned long timeMs = map(potValue, 0, 1023, 2000, 5000); // 2..5 сек
    Serial.print("Potentiometer: ");
    Serial.print(potValue);
    Serial.print(" -> Alarm time (ms): ");
    Serial.println(timeMs);

    runAlarm(timeMs);
    alarmTriggered = true;
  }
}

void runAlarm(unsigned long duration) {
  unsigned long start = millis();

  while (millis() - start < duration) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);

    // Возможность отключить тревогу по кнопке во время срабатывания
    if (digitalRead(buttonPin) == LOW) {
      armed = false;
      Serial.println("Alarm stopped by button");
      delay(300);
      break;
    }
  }
}
