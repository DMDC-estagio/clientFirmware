#ifndef __HELPER_H_
#define __HELPER_H_

//#define devBoard arduino

#include <WiFi.h>

//FUNCTIONS
float measureCurrent();
float measureVoltage();
void initWifi();
void reconectWifi();

#endif