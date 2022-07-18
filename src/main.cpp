#include <Arduino.h>
#include "helper.h"

void setup() {
  Serial.begin(115200);

  #ifndef devBoard arduino
    initWifi();
    initMQTT();
  #endif
}

void loop() {
  #ifndef devBoard arduino
    if (!WL_CONNECTED) {
      reconectWifi();
    }
  #endif

  float measuredCurrent = measureCurrent();
  float measuredVoltage = measureVoltage();

  Serial.print("  ");
  Serial.print(measuredCurrent);
  Serial.print("  ");
  Serial.println(measuredVoltage);
}