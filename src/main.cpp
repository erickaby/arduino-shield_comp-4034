#include <Arduino.h>
#include <SPI.h>

#include <Wire.h>
#include "Adafruit_DRV2605.h"

//#include <Arduino_LSM6DS3.h>

//#include "odisplay.h"
#include "trigger.h"

//#include <mcp4xxx.h>

//using namespace icecave::arduino;

//MCP4XXX* pot;

//ODisplay* d;
Trigger* trigger;

//int csPin = 3;
//int pwr3volt = 6;

// #include <IRLibSendBase.h>    // First include the send base
//Now include only the protocols you wish to actually use.
//The lowest numbered protocol should be first but remainder 
// #include <IRLibDecodeBase.h> 
//can be any order.
// #include <IRLib_P01_NEC.h>    
// #include <IRLibCombo.h>  

// #include <IRLib_HashRaw.h>  //Must be last protocol
// #include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal decoder
// class called "IRdecode" containing only the protocols you want.
// Now declare an instance of that decoder.

// IRsend mySender;

// IRdecode myDecoder;



// #include <IRLibRecv.h> 

// const int IR_RECEIVER_PIN = 5;

// IRrecv myReceiver(IR_RECEIVER_PIN);//pin number for the receiver

// const int switchPin = 7;

// int buttonState = 0;

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);

  // myReceiver.enableIRIn();
  Serial.println(F("Ready to receive IR signals"));


  pinMode(5, HIGH);
  pinMode(6, HIGH);
  // pinMode()
  //d = ODisplay::getInstance();
  trigger = Trigger::getInstance();

  drv.begin();

  drv.setMode(DRV2605_MODE_INTTRIG);

  drv.selectLibrary(1);
  drv.setWaveform(0, 84);  // ramp up medium 1, see datasheet part 11.2
  drv.setWaveform(1, 1);  // strong click 100%, see datasheet part 11.2
  drv.setWaveform(2, 0);  // end of waveforms

  //pot = new MCP4XXX(3);

  //pot->set(255);

  //delay(1000);
  //d->updateHealth(80);
  //delay(1000);
  //d->updateHealth(40);
  //delay(2000);
  //d->updateAmmo(6);
}

void loop() {
  drv.go();
  delay(1000);
  // if(myReceiver.getResults()) {
  //   myDecoder.decode();
  //   if(myDecoder.protocolNum==UNKNOWN) {
  //     Serial.print(F("Unknown protocol. Hash value is: 0x"));
  //     Serial.println(myDecoder.value,HEX);
  //   } else {
  //     myDecoder.dumpResults(false);
  //   };
  //   myReceiver.enableIRIn(); 
  // }

  // buttonState = digitalRead(switchPin);

  // if (buttonState == HIGH) {
    
  //   mySender.send(NEC, 0xFDB04F, 32);
  //   Serial.println(F("Sent signal."));
  //   //delay(200);
  // }

  
  // trigger->loop();

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