#include "arduino.h"

const int sensorPin = A0;
const float baselineTemp = 5.0;


void setup(){
  Serial.begin(9600);//open serial port at 9600 bit/sec

  for (int pinNumber = 0; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin); //Represents the voltage of the pin (0 -> 1023)
  float voltage = (sensorVal/1024.0) * 5.0; // The actual vlotage of the pin
  float temperature = (voltage - 0.5) * 100;

  Serial.print("Sensor Value : ");
  Serial.println(sensorVal);

  Serial.print("Voltage Value : ");
  Serial.println(voltage);

  Serial.print("Temperature : ");
  Serial.println(temperature);
  Serial.println("------------");

  if (temperature < baselineTemp + 2) {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp+4) {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp+6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }else if (temperature >= baselineTemp+6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }

  delay(1);
}
