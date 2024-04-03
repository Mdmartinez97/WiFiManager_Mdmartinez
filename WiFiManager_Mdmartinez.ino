#include "CustomWiFiManager.h"

void setup() {
  Serial.begin(115200);

  pinMode(RstWF, INPUT_PULLUP); //Botón Reset WiFi

  // Llamado a función conectar Wi-Fi
  CustomWiFiManager();  

   //SETUP DE EJEMPLO*****************
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
   //*********************************    
}

void loop() {

  //BOTÓN DE RESET WIFI
 if(digitalRead(RstWF) == LOW){ //Restablecer configuración, borrar las credenciales almacenadas y reiniciar ESP
    delay(50);
      if(digitalRead(RstWF) == LOW){
        wifiManager.resetSettings();
        delay(1000);
        ESP.restart();
      }
 }

//LOOP DE EJEMPLO*********************
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);

//************************************
}
