
void setup() {
  // Настроим последовательный порт на скорость 115200 бод
  Serial.begin(115200);

  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}

void loop() {

  if (Serial.available() > 0) {
    // Если есть доступные данные для чтения
    String data = Serial.readStringUntil('\n');
    // Читаем входные данные

    // Проверяем, если строка содержит "RDY"
    if (data.indexOf("?PURDY$") != -1) {
      Serial.println("!PUOK$");
      // Отправляем "!OK$" если найдена строка "RDY"
    }

  }
}