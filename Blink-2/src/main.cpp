#include "Arduino.h"

int ledResponse(int duration);
int ledProtocol(int duration);

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop(){
  ledResponse(2000);
}


int ledResponse(int duration){
  return (duration <= 0)? 0 : ledProtocol(duration);
}

int ledProtocol(int duration){
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  // wait for a second
  delay(duration);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(duration);

  return ledResponse(duration / 2);
}
