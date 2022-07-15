#include "helper.h"

float measureCurrent(){
  float readVoltage = analogRead(36) - analogRead(34);
  int active = analogRead(33) > 50 ? 1 : 0;
  
  #ifndef devBoard arduino
  readVoltage = (readVoltage / 4095) * 3.3; // ESP32
  #endif
  
  #ifdef devBoard arduino
  readVoltage = (readVoltage / 1023) * 5; // Arduino
  #endif
    
  if (active) {
    readVoltage = readVoltage * 10,625;
  }
  readVoltage = readVoltage / 1.4142;
  
  return readVoltage / 2.4;
}

float measureVoltage(){
  float readVoltage = analogRead(35);
  readVoltage = ((readVoltage / 1023) * 5) - 1.50;
  return readVoltage * 20 * 17;
}