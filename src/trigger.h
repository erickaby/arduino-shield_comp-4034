#ifndef TRIGGER_H
#define TRIGGER_H

#include <SPI.h>
#include <FastLED.h>
#include <Adafruit_DRV2605.h>

#define TRIGGER_PIN   12
#define LED_PIN       7
#define NUM_LEDS      4

class Trigger {
  private:
    static Trigger* _instance;

    Trigger();

    int _state;
    int _lastState;
    int _startPressed;
    int _endPressed;
    int _holdTime;
    int _idleTime;

    void updateCounter();
    void updateState();
  public:
    static Trigger* getInstance();

    void loop();

};

#endif