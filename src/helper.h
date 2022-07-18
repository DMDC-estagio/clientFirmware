#ifndef __HELPER_H_
#define __HELPER_H_

// uncoment if using a arduino board
//#define devBoard arduino

#include <WiFi.h>
#include <PubSubClient.h>

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

#endif