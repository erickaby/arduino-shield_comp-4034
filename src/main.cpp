#include <Arduino.h>
#include <SPI.h>

#include <Arduino_LSM6DS3.h>

#include "odisplay.h"


void setup() {
  Serial.begin(9600);
  ODisplay* d{ODisplay::getInstance()};
  delay(5000);
  d->updateHealth(80);
  delay(5000);
  d->updateHealth(40);
  delay(5000);
  d->updateAmmo(6);
}

void loop() {
  Serial.println("Hello World!");
  delay(1000);
}