#include <Arduino.h>
#include "helper.h"

void setup() {
  Serial.begin(115200);
  initWifi();
}

void loop() {
  if (!WL_CONNECTED) {
    reconectWifi();
  }

  float measuredCurrent = measureCurrent();
  float measuredVoltage = measureVoltage();

  Serial.print("  ");
  Serial.print(measuredCurrent);
  Serial.print("  ");
  Serial.println(measuredVoltage);
}