#include "trigger.h"

CRGB leds[NUM_LEDS];

Adafruit_DRV2605 drv;

Trigger* Trigger::_instance = 0;

Trigger* Trigger::getInstance()
{
  if (_instance == 0) {
    _instance = new Trigger();
  }
  return _instance;
}

Trigger::Trigger() : _state{digitalRead(TRIGGER_PIN)}, _lastState{0}, _startPressed{0}, _endPressed{0}, _holdTime{0}, _idleTime{0}
{
  pinMode(TRIGGER_PIN, OUTPUT);
  Serial.println("TRIGGER_PIN set to OUTPUT");
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  Serial.println("Initialised LEDs");

  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);
  
}

void Trigger::loop() {
  _state = digitalRead(TRIGGER_PIN);
  Serial.println(_state);

  if (_state != _lastState) {
    updateState();
  } else {
    updateCounter();
  }

  _lastState = _state;
}

void Trigger::updateCounter() {
  // The button is still pressed.
  
  if (_state == HIGH) {
    _holdTime = millis() - _startPressed;

    // 500 ms
    if (_holdTime == 500) {
      leds[0] = CRGB::Green; FastLED.show();
    }
    if (_holdTime >= 500 && _holdTime < 1000) {
      drv.setWaveform(0, 51); drv.go();
    }

    // 1000 ms
    if (_holdTime == 1000) {
      leds[1] = CRGB::Green; FastLED.show();
    }
    if (_holdTime >= 1000 && _holdTime < 1500) {
      drv.setWaveform(0, 50); drv.go();
    }

    // 1500ms
    if (_holdTime == 1500) {
      leds[2] = CRGB::Green; FastLED.show();
    }
    if (_holdTime >= 1500 && _holdTime < 2000) {
      drv.setWaveform(0, 49); drv.go();
    }
    
    // 2000ms
    if (_holdTime == 2000) {
      leds[3] = CRGB::Green; FastLED.show();
    }
    if (_holdTime >= 2000 && _holdTime < 2500) {
      drv.setWaveform(0, 48); drv.go();
    }

    // 2500ms
    if (_holdTime == 2500) {
      for (int i = 0; i < 4; i++)
      {
        leds[i] = CRGB::DarkRed;
      }
      FastLED.show();
    }
    if (_holdTime >= 2500) {
      drv.setWaveform(0, 47); drv.go();
    }
     

  // The button is still released.
  } else {
    _idleTime = millis() - _endPressed;
  }
}

void Trigger::updateState() {
  // The button was just pressed.
  if (_state == HIGH) {
    _startPressed = millis();
    _idleTime = _startPressed - _endPressed;
    
  // The button was just released.
  } else {
    _holdTime = _endPressed - _startPressed;
    for (int i = 0; i < 4; ++i)
    {
      leds[i] = CRGB::Black; FastLED.show();
    }
    drv.setWaveform(2, 0);
    
    //  for (int i = 0; i < 3; ++i)
    //  {

    //  }
  }
}