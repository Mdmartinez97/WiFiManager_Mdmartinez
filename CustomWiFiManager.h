#include <WiFiManager.h> // --> https://github.com/tzapu/WiFiManager/ ; https://randomnerdtutorials.com/solved-reconnect-esp8266-nodemcu-to-wifi/

const uint8_t RstWF = 4; //Botón Reset WiFi

WiFiManager wifiManager;

void CustomWiFiManager(){
  
    WiFi.mode(WIFI_STA);
    wifiManager.setDebugOutput(true); //Habilita debug serie, deshabilitar a gusto

    wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0)); //Definir IP de acceso a Panel WiFi Manager
    //⬇⬇ COMENTAR PARA USAR DHCP ⬇⬇
    wifiManager.setSTAStaticIPConfig(IPAddress(192,168,100,99), IPAddress(192,168,100,1), IPAddress(255,255,255,0)); //Configuración de red MANUAL (opcional DNS 4to argumento)

    wifiManager.setCustomHeadElement("<style>button{background-color: #9c103c;}</style>"); //CSS botones
    wifiManager.setClass("invert"); //Tema oscuro
    WiFiManagerParameter custom_text("<p>Custom Version by Marcos Martinez</p>"); //Texto HTML al pie
    wifiManager.addParameter(&custom_text);    
    
    bool res;    
    res = wifiManager.autoConnect("WiFi Manager (by Mdmartinez)","12345678"); //SSID & Pass / Contraseña opcional (min 8 caracteres)
   
    if(!res) {
        Serial.println("Error al conectar!");
        Serial.println("Por favor, reinicie manualmente");
        delay(30000);    // 30 segundos de gracia
        ESP.restart(); //Automatic restart
    }

    //Tries to reconnect automatically when the connection is lost
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
}