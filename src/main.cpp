#include <Arduino.h>
#include "helper.h"


unsigned int measureCount = 0;

void setup() {
  // Since arduino cant handle Wifi nor HTTP, those lines are not necesary 
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

    if(millis() - lastMillis >= 0x15F90) { // Waits 1'30" until the next http request
      voltage.med = voltage.med / measureCount;
      current.med = current.med / measureCount;
      sendHttp(voltage, current);
      lastMillis = millis();

      measureCount = 0; 
      current.max = 0; current.min = 1000;
      voltage.max = 0; voltage.min = 1000; // Setting minimum values to 1000 garants that it wont receive a faulty value
    }
    // Measure voltage and current
    float measuredCurrent = measureCurrent();
    float measuredVoltage = measureVoltage();

    voltage.med += measuredVoltage;
    current.med += measuredCurrent;
    measureCount++;

    if(measuredCurrent > current.max) { current.max = measuredCurrent; }
    if(measuredVoltage > voltage.max) { voltage.max = measuredVoltage; }

    if(measuredCurrent < current.min) { current.min = measuredCurrent; }
    if(measuredVoltage < voltage.min) { voltage.min = measuredVoltage; }

    delayMicroseconds(100);
  }
}