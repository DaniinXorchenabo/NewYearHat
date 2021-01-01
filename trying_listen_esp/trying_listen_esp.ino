/*
 * Тот провод, который был при загрузке прошивки в ESP8266
 * на Rx (0), необходимо переставить на 3 пин
 * тот провод, который был на Tx (1) - 
 * 
 * 
 * 
 * 
 */



#include <SoftwareSerial.h>
SoftwareSerial esp(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  esp.begin(115200);
  Serial.println("Начали!");
}

void loop() {
  while (esp.available() > 0){
    Serial.println(esp.readString());
  }
  delay(10);

}
