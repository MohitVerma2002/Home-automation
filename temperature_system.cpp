#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


void init_temperature_system(void) {
  pinMode(TEMPERATURE_SENSOR, INPUT);
  pinMode(HEATER, OUTPUT);
  pinMode(COOLER, OUTPUT);
}
// read the temperature from the temperature sensor and return the temperature
float read_temperature(void) {
  float temperature;
  temperature = ((analogRead(TEMPERATURE_SENSOR) * (float) 5/1024) / (float)0.01);
  return temperature;
}

// to turen on and off the cooler
void cooler_control(bool control) {
  if(control){
    digitalWrite(COOLER, HIGH);
  }
  else{
    digitalWrite(COOLER, LOW);
  }
}
void heater_control(bool control) {
  if(control){
    digitalWrite(HEATER, HIGH);
  }
  else{
    digitalWrite(HEATER, LOW);
  }
}
