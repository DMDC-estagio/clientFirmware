#include "helper.h"
const char* SSID = "#######";
const char* PASSWORD = "#######";

void initWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void reconectWifi() {
    Serial.println("WIFI CONNECTIONS LOST!");
    WiFi.mode(WIFI_STA);
    Serial.println("Trying to connect to WIFI ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println("Reconnected successfully");
}