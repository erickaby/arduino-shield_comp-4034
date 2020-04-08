#include <Arduino.h>
#include <SPI.h>

#include <Arduino_LSM6DS3.h>

#include "odisplay.h"
#include "trigger.h"

ODisplay* d;
Trigger* trigger;

void setup() {
  Serial.begin(9600);
  d = ODisplay::getInstance();
  trigger = Trigger::getInstance();

  // delay(1000);
  // d->updateHealth(80);
  // delay(1000);
  // d->updateHealth(40);
  // delay(2000);
  // d->updateAmmo(6);
}

void loop() {
  trigger->loop();
  
  // delay(1000);
  // int hit = 46;
  // for (int i = 0; i < hit; ++i)
  // {
  //   d->updateHealth(i);
  //   delay(100);
  // }
}