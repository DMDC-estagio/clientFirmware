#include "helper.h"

const char* SSID = "#####";
const char* PASSWORD = "######";

void initWifi() {
    // Set WiFi configs
    /*
    WiFi.config(
        (192, 168, 1, 360), // Set Static IP address
        (192, 168, 1, 1),   // Set Gateway IP address
        (255, 255, 0, 0),   // Set Stitic Subnet Mask
        (8, 8, 8, 8),       // Set Static DNS Server 1
        (8, 8, 4, 4)        // Set Static DNS Server 2
    );
    */

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