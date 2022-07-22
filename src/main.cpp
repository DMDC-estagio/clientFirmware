#include <Arduino.h>
#include "helper.h"

void setup() {
  #ifndef devBoard arduino
    initWifi();
    initMQTT();
  #endif
}

unsigned long lastMillis;

void loop() {
  measurements voltage, current;

  while(true){
    #ifndef devBoard arduino
      if (!WL_CONNECTED) {
        reconectWifi();
      }
    #endif

    if(millis() - lastMillis >= 0x15F90) {
      sendHttp(voltage, current);
      lastMillis = millis();
    }
    float measuredCurrent = measureCurrent();
    float measuredVoltage = measureVoltage();

    voltage.med = (voltage.med + measuredVoltage) / 2;
    if(measuredVoltage > voltage.max) { voltage.max = measuredVoltage; }
  }
}