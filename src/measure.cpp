#include "helper.h"

//PINOUT
const int 
  inCurrent = 36,     // Current InPut GPIO 36
  offsetPin = 39,     // Current Offset GPIO 39
  CurrentSwitch = 34, // Current relay on GPIO 34
  inVoltage = 32;     // Voltage InPut GPIO 32

float measureCurrent(){
  float readVoltage = analogRead(inCurrent) - analogRead(offsetPin);
  int active = analogRead(CurrentSwitch) > 50 ? 1 : 0;
  
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
  float readVoltage = analogRead(inVoltage);
  readVoltage = ((readVoltage / 1023) * 5) - 1.50;
  return readVoltage * 20 * 17;
}