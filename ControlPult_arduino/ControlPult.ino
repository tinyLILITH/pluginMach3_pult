
uint32_t tmr1;

//#define EB_DEB_TIME 200 //без сбоев , но медленно 
//#define EB_DEB_TIME 100 // 20 запусков без сбоя

//lgt8f and arduino nano
//#define RELAY_OUTPUT 9

//nodemcu
#define RELAY_OUTPUT 14

#include <EncButton.h>
//byte swAxis,swOverride = 0;

//EncButton eb(8, 7);
//Button jogButton(6);

//lgt8f and arduino nano

Button butt1(D10);
Button butt2(D11);
Button butt3(D12);

/*
//nodemcu

Button butt1(5);  // START
Button butt2(4);  // STOP
Button butt3(12); // ESTOP
*/

void setup() {
  Serial.begin(115200); // Начинаем серийную связь на скорости 9600 бод
  pinMode(RELAY_OUTPUT,OUTPUT);
  digitalWrite(RELAY_OUTPUT,1);
}

void loop() {
  //eb.tick();
  //jogButton.tick();
  butt1.tick();
  butt2.tick();
  butt3.tick();

  if (Serial.available()>0) { 
    // Если есть доступные данные для чтения
    String data = Serial.readStringUntil('\n'); // Читаем входные данные

    if (data == "?RDY$") {
      Serial.println("!OK$"); // Отправляем "!OK$" если получено "?RDY$"
      
    }

    if (data == "?RLYON$") {
      Serial.println("!RLYOK$"); // Отправляем "!OK$" если получено "?RDY$"
      digitalWrite(RELAY_OUTPUT,0);
    }
        if (data == "?RLYOFF$") {
      Serial.println("!RLYOK$"); // Отправляем "!OK$" если получено "?RDY$"
      digitalWrite(RELAY_OUTPUT,1);
    }
  }

//Кнопки

if(butt1.click()) Serial.println("!START$"); //NO
if(butt2.click()) Serial.println("!STOP$"); //NO

if(butt3.release()) Serial.println("!ESTP$");//NC


/*
if (overrideButton.click()){

    switch (swOverride) {

      case 0:
        Serial.println("!FstM$");
        swOverride++;
        break;

      case 1:
        Serial.println("!SlwM$");
        swOverride = 0;
        break;

    }
}
*/

//----------Кнопки----------


//Энкодер

  //if (eb.left()) Serial.println("!J-$");
 // if (eb.right()) Serial.println("!J+$");

//Выбор осей перемещения
/*
  if (jogButton.click()){

    switch (swAxis) {
      case 0:
        Serial.println("!aZ$");
        swAxis++;
        break;

      case 1:
        Serial.println("!aX$");
        swAxis = 0;
        break;
    }

  }
  */
//-----------Энкодер-------------

/*

  if (millis() - tmr1 >= 5) {  // ищем разницу
    tmr1 = millis(); 
    int rnd = random (1,10);
    Serial.print("try:"); 
    Serial.print(rnd);
    Serial.print(" ");                  // сброс таймера
    for (int i =0 ;i < rnd; i++){
      Serial.println(i);
    }
  }
*/


}
