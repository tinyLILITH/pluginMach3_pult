#include "GyverButton.h"

const int drvPin = 5;
const int lptPin = 6;
#define BTN_PIN 1	

GButton butt2(BTN_PIN);
bool lastButtonState = HIGH;  // Предыдущее состояние кнопки
unsigned long lastDebounceTime = 0;  
const unsigned long debounceDelay = 50;  // Антидребезг 50 мс

void setup() {

  Serial.begin(115200);

  pinMode(drvPin, OUTPUT);
  digitalWrite(drvPin, HIGH);

  pinMode(lptPin, OUTPUT);
  digitalWrite(lptPin, HIGH);

}

void loop() {
//butt1.tick();
butt2.tick();

if (butt2.isRelease()) {
  Serial.println("!JOGstp$");
  delay(50);
  Serial.println("!JOGstp$");
}

if (butt2.isStep(0)) {
  Serial.println("!JOGXp$");
}

if (butt2.isStep(1)) {
  Serial.println("!FJOGXp$");
}
  // Обработка входящих данных Serial
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    handleCommand(input);
  }
}

void handleCommand(const String& cmd) {
  if (cmd == "?PURDY$") {
    Serial.println("!PUOK$");
  }
  else if (cmd == "?DRVON$") {
    digitalWrite(drvPin, LOW);
    Serial.println("!DRVON$");
  } 
  else if (cmd == "?DRVOFF$") {
    digitalWrite(drvPin, HIGH);
    Serial.println("!DRVOFF$");
  }
  else if (cmd == "?LPTON$") {
    digitalWrite(lptPin, LOW);
    Serial.println("!LPTON$");
  } 
  else if (cmd == "?LPTOFF$") {
    digitalWrite(lptPin, HIGH);
    Serial.println("!LPTOFF$");
  }
  else {
    Serial.println("!UNKNOWN$");
  }
}
