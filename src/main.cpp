#include <Arduino.h>
#include <SPI.h>

#include <Arduino_LSM6DS3.h>

#include "odisplay.h"
#include "trigger.h"

//#include <mcp4xxx.h>

//using namespace icecave::arduino;

//MCP4XXX* pot;

ODisplay* d;
Trigger* trigger;

//int csPin = 3;
//int pwr3volt = 6;

void setup() {
  Serial.begin(9600);
  d = ODisplay::getInstance();
  trigger = Trigger::getInstance();

  //pot = new MCP4XXX(3);

  //pot->set(255);

  delay(1000);
  d->updateHealth(80);
  delay(1000);
  d->updateHealth(40);
  delay(2000);
  d->updateAmmo(6);
}

void loop() {
  trigger->loop();

  // Move the wiper to the lowest value
    //pot->set(200);

    // // Move the wiper to the highest value
    // pot->set(pot->max_value());

    // // Increment the wiper position by one
    // pot->increment();

    // // Decrement the wiper position by one
    // pot->decrement();

  // for (int i = 0; i < pot->max_value(); ++i) 
  // {
  //   pot->set(200);
  //   delay(500);
  // }
  
  // delay(1000);
  // int hit = 46;
  // for (int i = 0; i < hit; ++i)
  // {
  //   d->updateHealth(i);
  //   delay(100);
  // }
}