/*
 * ESP8266 NodeMCU AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
#include "index11.h"                          // Содержание нашей HTML веб-страницы с javascript  Our HTML webpage contents with javascripts
 
#define LED_PIN 2  //On board LED
                                              //SSID and Password of your WiFi router
const char* ssid = "ddd1";
const char* password = "wweerrtt";
 
ESP8266WebServer server(80);                  //Server on port 80

int t2222 = 4;
int a1 = 0;
String strok2="",t_in="",t_out="";
unsigned long timing;                         // Переменная для хранения точки отсчета

//==============================================================
//                                            SETUP
//==============================================================

void setup(void){
  Serial.begin(115200);
  Serial.println("start");
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  WiFi.begin(ssid, password);                 //Connect to your WiFi router

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
 
  /*//If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());*/           //IP address assigned to your ESP
 
  server.on("/",         handleRoot);         //Какую процедуру обрабатывать в корневом каталоге. Это страница дисплеяb   Which routine to handle at root location. This is display page

  server.on("/setLED",  led_controller);
//  server.on("/setLED",   test1);
  //server.on("/setLED1",  handleLED1);
//  server.on("/setLED4",  test2);
//  server.on("/setLED3",  test3);
 // server.on("/setLED1",  handleLED3);


  server.begin();                             //Start server
}
//==============================================================
//                                            LOOP
//==============================================================

void loop(void){
  server.handleClient();                      //Handle client requests
}

void handleRoot() {
  Serial.println("send main page");
  server.send(200, "text/html", MAIN_page);            //Отправить веб-страницу  Send web page
}

void led_controller(){
  String new_led_state  = server.arg("LEDstate"); 
  String ledState = "got it";
  Serial.println("set led in ");
  
  if(new_led_state == "1") { 
    Serial.println(new_led_state);
    digitalWrite(LED_PIN, HIGH);
  }
  else if(new_led_state == "0"){
    Serial.println(new_led_state);
    digitalWrite(LED_PIN, LOW);
  }
  else {
    Serial.println(new_led_state);
    Serial.println("Error! case not found!");
    ledState = "Error, I get " + new_led_state + " it is no 0 or 1";
  } 
  Serial.println("send answer in web-site");
  server.send(200, "text/plane", ledState);   //Send web page
  Serial.println("send answer in web-site got it");
  
}
 ///------------------------------------------ОТПРАВКА НА ESP------------------------------------------------------
 


///____________________________________________ПРИёМ С САЙТА____________________
//void handleLED() {
//  Serial.println("LED_Actived");
//  if (Serial.available())       {              //прием данных с ардуино
//    strok2 = ""; 
//    strok2 = Serial.readString(); 
//   
//  }
//  String ledState = "OFF";
//  String t_state  = server.arg("LEDstate");   //См. xhttp.открыть ("получить", " устроиться?Состояние светодиода= " +led, true);  Refer  xhttp.open("GET", "setLED?LEDstate="+led, true);
//  if(t_state == "1") { 
//    Serial.print('2');
//    ledState =   "ON"; 
//  }
//  else if(t_state == "0"){
//    Serial.print('3');
//    ledState =  "OFF";
//  } 
//  server.send(200, "text/plane", ledState);   //Send web page
//}
//
//void handleLED1() {
//  Serial.println("LED1_Actived");
//  String ledState1  = "OFF";
//  String t_state1   = server.arg("LEDstate1");
//  if(t_state1 == "1"){       
//    Serial.print('5');ledState1   = "ON";
//  }         
//  else if(t_state1 == "0"){ 
//    Serial.print('6');ledState1   = "OFF";
//  }
//  server.send(200, "text/plane", ledState1);                       
//}
//
//void handleLED4() {
//  Serial.println("LED4_Actived");
//  Serial.print('4');
//}
//
//void handleLED3() {
//  Serial.println("LED3_Actived");
// bool statu = digitalRead(2);
// digitalWrite(2, !statu);
//}
