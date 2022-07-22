#ifndef __HELPER_H_
#define __HELPER_H_

// uncoment if using a arduino board
//#define devBoard arduino

typedef struct {
    float max;
    float med;
    float min;
} measurements;

#include <WiFi.h>
#include <PubSubClient.h>
#include <HTTPClient.h>

// measure.cpp
float measureCurrent();
float measureVoltage();

// WiFi-handler.cpp
void initWifi();
void reconectWifi();

// MQTT-resolver.cpp
void initMQTT();
void reconnetMQTT();
void publishMQTT(void);

// HTTP-handler.cpp
String sendHttp(measurements voltage, measurements current);


#endif