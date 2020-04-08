#include "trigger.h"

CRGB leds[NUM_LEDS];

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
    if (_holdTime == 500) {
      Serial.println("2");
      leds[0] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 1000) {
      leds[1] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 1500) {
      leds[2] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 2000) {
      leds[3] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 2500) {
      leds[4] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 3000) {
      leds[5] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 3500) {
      leds[6] = CRGB::Green; FastLED.show();
    }
    if (_holdTime == 4000) {
      for (int i = 0; i < 8; i++)
      {
        leds[i] = CRGB::DarkRed;
      }
      FastLED.show();
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
    for (int i = 0; i < 8; ++i)
    {
      leds[i] = CRGB::Black; FastLED.show();
    }
    
    _holdTime = _endPressed - _startPressed;
  }
}