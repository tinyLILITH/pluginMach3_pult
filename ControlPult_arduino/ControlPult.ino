#define EB_DEB_TIME 25      // таймаут гашения дребезга кнопки (кнопка)
#define EB_CLICK_TIME 50   // таймаут ожидания кликов (кнопка)

#include <EncButton.h>
byte swAxis,swOverride = 0;

EncButton eb(14, 12);
Button jogButton(5);
Button overrideButton(0);
Button butt1(4);
Button butt2(13);

void setup() {
  Serial.begin(115200); // Начинаем серийную связь на скорости 9600 бод
}

void loop() {
  eb.tick();
  jogButton.tick();
  overrideButton.tick();
  butt1.tick();
  butt2.tick();

  if (Serial.available()>0) { 
    // Если есть доступные данные для чтения
    String data = Serial.readStringUntil('\n'); // Читаем входные данные

    if (data == "?RDY$") {
      Serial.println("!OK$"); // Отправляем "!OK$" если получено "?RDY$"

    } 
  }

//Кнопки

if(butt1.click()) Serial.println("!START$");
if(butt2.click()||butt2.press()) Serial.println("!STOP$");

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


//----------Кнопки----------


//Энкодер

  if (eb.left()) Serial.println("!J-$");
  if (eb.right()) Serial.println("!J+$");

//Выбор осей перемещения

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
//-----------Энкодер-------------

}
