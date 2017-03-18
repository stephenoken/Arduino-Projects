#include "Arduino.h"

void redLEDState(int firstLedState,int secondLedState);
void ledActionState(int duration);

void setup() {
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
pinMode(2,INPUT);
}

void loop() {
  int switchState = digitalRead(2);
  digitalWrite(3,HIGH);
  (switchState == LOW) ? redLEDState(LOW,LOW) : ledActionState(250);
}

void redLEDState(int firstLedState,int secondLedState){
  digitalWrite(4,firstLedState);
  digitalWrite(5,secondLedState);
}

void ledActionState(int duration){
  redLEDState(HIGH,HIGH);
  delay(duration);
  redLEDState(HIGH,LOW);
  delay(duration);
}
