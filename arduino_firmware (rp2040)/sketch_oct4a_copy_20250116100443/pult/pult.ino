#include "GyverButton.h"

// Назначаем пины для выходов
const int drvPin = 15;
const int lptPin = 14;
const int uSSR1 = 26;
const int uSSR2 = 27;  


int buzzer = 10;  // You can change this to any other pin



// Назначаем пины для кнопок (2–9)
GButton buttESTP(0);
GButton buttCS(1);
GButton buttCSS(2);

//Кнопки назначаемые пользователем
GButton buttUCB1(3);
GButton buttUCB2(4);
GButton buttUCB3(5);
GButton buttUCB4(6);
GButton buttUCB5(7);

//other signal (alarm stepper motor etc..)
GButton alarmX(8);
GButton alarmZ(9);

GButton butt11(10);
GButton butt12(11);
GButton butt13(12);
GButton butt14(13);


void setup() {
  Serial.begin(115200);

  // Настраиваем выходы для реле (симисторов)
  pinMode(drvPin, OUTPUT); //driver stepper motor
  digitalWrite(drvPin, LOW);

  pinMode(lptPin, OUTPUT); //lpt / coolant
  digitalWrite(lptPin, LOW);


  // Включаем автоопрос кнопок
  buttESTP.setTickMode(AUTO); //  e-stop
  buttCS.setTickMode(AUTO);   //  cycle start
  buttCSS.setTickMode(AUTO);  //  cycle soft stop/pause


  // user control buttons (UCB)
  buttUCB1.setTickMode(AUTO);
  buttUCB2.setTickMode(AUTO);
  buttUCB3.setTickMode(AUTO);
  buttUCB4.setTickMode(AUTO);
  buttUCB5.setTickMode(AUTO);

//other signal (alarm stepper motor etc..)
  alarmX.setTickMode(AUTO);
  alarmZ.setTickMode(AUTO);
}

void isr() {
  buttESTP.tick();  // опрашиваем в прерывании, чтобы поймать нажатие в любом случае
}

void loop() {

  if (buttESTP.isPress()) Serial.println("!ERLS$");
  if (buttESTP.isRelease()) Serial.println("!ESTP$");

  if (alarmX.isPress()) Serial.println("!ALMX$");
  if (alarmX.isRelease()) Serial.println("!ALMX_RLS$");

  if (alarmZ.isPress()) Serial.println("!ALMZ$");
  if (alarmZ.isRelease()) Serial.println("!ALMZ_RLS$");


  if (buttCS.isClick()) {
    Serial.println("!CS$");
  }

  if (buttCSS.isClick()) {
    Serial.println("!CSS$");
  }

  if (buttUCB1.isClick()) {
    Serial.println("!UCB1$");
  }

  if (buttUCB2.isClick()) {
    Serial.println("!UCB2$");
  }
  if (buttUCB3.isClick()) {
    Serial.println("!UCB3$");
  }
  if (buttUCB4.isClick()) {
    Serial.println("!UC466$");
  }

  if (buttUCB5.isClick()) {
    Serial.println("!UCB5$");
  }



  // Обработка команд по Serial
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    handleCommand(input);
  }
}

void handleCommand(const String& cmd) {
  if (cmd == "?PURDY$") 
  {
    Serial.println("!PUOK$");
  } 
  else if (cmd == "?DRVON$") 
  {
    digitalWrite(drvPin, HIGH);
    Serial.println("!DRVON$");
  } 
  else if (cmd == "?DRVOFF$") 
  {
    digitalWrite(drvPin, LOW);
    Serial.println("!DRVOFF$");
  } 
  else if (cmd == "?LPTON$") 
  {
    digitalWrite(lptPin, HIGH);
    Serial.println("!LPTON$");
  } 
  else if (cmd == "?LPTOFF$") 
  {
    digitalWrite(lptPin, LOW);
    Serial.println("!LPTOFF$");
  } 
  else if (cmd == "?ERLS$") 
  {
    if (digitalRead(0) == HIGH) 
    { 
      Serial.println("!ERLS$"); 
    }
  } 
  else {
    Serial.println("!UNKNOWN$");
  }
}
