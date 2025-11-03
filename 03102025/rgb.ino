// Определяем пины как константы
const int TRIG_PIN = 8;
const int ECHO_PIN = 9;
const int RED_PIN = 4;
const int GREEN_PIN = 3;
const int BLUE_PIN = 2;
const int BUZZER_PIN = 7;

void setup() {
  // Настройка пинов
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Отправляем импульс
  digitalWrite(TRIG_PIN, LOW);
  delay(200);
  digitalWrite(TRIG_PIN, HIGH);
  delay(500);
  digitalWrite(TRIG_PIN, LOW);

  // Измеряем время отклика
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // в сантиметрах

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 15) {
    // Слишком близко
    setColor(LOW, HIGH, HIGH); // Красный (R)
    tone(BUZZER_PIN, 1200);   // Громче (выше частота)
    delay(200);   // Быстрые звуки
    noTone(BUZZER_PIN);
  } 
  else if (distance >= 15 && distance <= 30) {
    // Среднее расстояние
    setColor(LOW, LOW, HIGH); // Желтый (R+G)
    tone(BUZZER_PIN, 900);    // Средняя громкость
    delay(300);   // Быстрые звуки
    noTone(BUZZER_PIN);
  } 
  else {
    // Безопасно
    setColor(HIGH, LOW, LOW); // Зеленый (G)
    tone(BUZZER_PIN, 600);    // Тихо
    delay(400);   // Быстрые звуки
    noTone(BUZZER_PIN);
  }

  delay(100);  // Маленькая задержка перед следующим измерением
}

void setColor(bool r, bool g, bool b) {
  // Логика для общих анодов
  // Для общего анода: LOW включает, HIGH выключает
  digitalWrite(RED_PIN, r);    // Если r = LOW, включается красный
  digitalWrite(GREEN_PIN, g);  // Если g = LOW, включается зеленый
  digitalWrite(BLUE_PIN, b);   // Если b = LOW, включается синий
}


