#ifndef __HELPER_H_
#define __HELPER_H_

//#define devBoard arduino

#include <WiFi.h>
#include <PubSubClient.h>

//FUNCTIONS
float measureCurrent();
float measureVoltage();
void initWifi();
void reconectWifi();

void initMQTT();
void reconnetMQTT();
void publishMQTT(void);

#endif