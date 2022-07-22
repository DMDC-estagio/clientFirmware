#include "helper.h"

//------------//
// DEPRECATED //
//------------//

/*
    URL mqtt3.thingspeak.com
    Port 1883

    Client credentials:
    User: JjQZFhodDDghISIALBYQNS8
    Pass: P0j6b3/tUHGdXg6FMye3mXdH
*/

const char* MQTT_SERVER = "mqtt3.thingspeak.com";
const char* MQTT_SERVER2 = "maqiatto.com";

char msg[50];
WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

void initMQTT() {
    MQTT.setServer(MQTT_SERVER, 1883);
}

void reconnetMQTT(){
  while (!MQTT.connected()){
  Serial.println("Connecting to the MQTT broker...");

  if (MQTT.connect("JjQZFhodDDghISIALBYQNS8")){
    Serial.println("Connected successfully");
  }else{
    Serial.print("Connection failed, rc=");
    Serial.print(MQTT.state());
    Serial.println(" ...trying to reconnect...");
    delay(3000);
    }
  }
}

void publishMQTT(void) {
    if (!MQTT.connected()) {
        reconnetMQTT();
    }
    long int value;
    MQTT.loop();
    snprintf (msg, 75, "%ld", value);
    MQTT.publish("###/###", msg);
  
}