#include "GyverButton.h"

// Назначаем пины для выходов
const int drvPin = 10;
const int lptPin = 11;

// Назначаем пины для кнопок (2–9)
GButton butt1(0);
GButton butt2(1);
GButton butt3(2);
GButton butt4(3);
// пульт перемещения
GButton butt5(4);
GButton butt6(5);
GButton butt7(6);
GButton butt8(7);

void setup() {
  Serial.begin(115200);

  attachInterrupt(0, isr, RISING); // прерывание для STOP

  // Настраиваем выходы
  pinMode(drvPin, OUTPUT);
  digitalWrite(drvPin, HIGH);

  pinMode(lptPin, OUTPUT);
  digitalWrite(lptPin, HIGH);

  // Включаем автоопрос кнопок
  butt1.setTickMode(AUTO);
  butt2.setTickMode(AUTO);
  butt3.setTickMode(AUTO);
  butt4.setTickMode(AUTO);
  butt5.setTickMode(AUTO);
  butt6.setTickMode(AUTO);
  butt7.setTickMode(AUTO);
  butt8.setTickMode(AUTO);
}

void isr() {
  butt1.tick();  // опрашиваем в прерывании, чтобы поймать нажатие в любом случае
}

void loop() {

if (butt1.isHolded()) Serial.println("!ESTP$");
if (butt1.isRelease()) Serial.println("!ERLS$");

 if (butt2.isStep(0)) {
    Serial.println("!CS$");
  }

  //---------перемещение осей------------

    if (butt5.isRelease() || butt6.isRelease() || butt7.isRelease() || butt8.isRelease()) {
    Serial.println("?JOGSTP$");
    delay(50);
    Serial.println("?JOGSTP$");
  }

  if (butt5.isStep(0)) {
    Serial.println("!JOGXp$");
  }

  if (butt5.isStep(1)) {
    Serial.println("!FJOGXp$");
  }

  if (butt6.isStep(0)) {
    Serial.println("!JOGXm$");
  }

  if (butt6.isStep(1)) {
    Serial.println("!FJOGXm$");
  }

  if (butt7.isStep(0)) {
    Serial.println("!JOGZp$");
  }

  if (butt7.isStep(1)) {
    Serial.println("!FJOGZp$");
  }

  if (butt8.isStep(0)) {
    Serial.println("!JOGZm$");
  }

  if (butt8.isStep(1)) {
    Serial.println("!FJOGZm$");
  }
  //---------------------------

  // Обработка команд по Serial
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
  else if (cmd == "?ERLS$") {
    if (digitalRead(0)==HIGH) {Serial.println("!ERLS$");}
  }
  else {
    Serial.println("!UNKNOWN$");
  }
}

