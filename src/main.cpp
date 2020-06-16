#include <Arduino.h>
#include <SPI.h>

#include <Wire.h>

//#include <Arduino_LSM6DS3.h>

#include "odisplay.h"
#include "trigger.h"

ODisplay* d;
Trigger* trigger;

//int csPin = 3;
//int pwr3volt = 6;

#include <IRLibSendBase.h>    // First include the send base
//Now include only the protocols you wish to actually use.
//The lowest numbered protocol should be first but remainder 
#include <IRLibDecodeBase.h> 
//can be any order.
#include <IRLib_P01_NEC.h>    
#include <IRLibCombo.h>  

#include <IRLib_HashRaw.h>  //Must be last protocol
#include <IRLibCombo.h>     // After all protocols, include this

// All of the above automatically creates a universal decoder
// class called "IRdecode" containing only the protocols you want.
// Now declare an instance of that decoder.

IRsend mySender;

// IRdecode myDecoder;



// #include <IRLibRecv.h> 

// const int IR_RECEIVER_PIN = 5;

// IRrecv myReceiver(IR_RECEIVER_PIN);//pin number for the receiver

// const int switchPin = 7;

// int buttonState = 0;



void setup() {
  Serial.begin(9600);

  // myReceiver.enableIRIn();
  Serial.println(F("Ready to receive IR signals"));

  

  pinMode(8, OUTPUT);

  // pinMode(5, HIGH);
  // pinMode(6, HIGH);
  // pinMode()
  d = ODisplay::getInstance();
  trigger = Trigger::getInstance();




  //pot = new MCP4XXX(3);

  //pot->set(255);

  // delay(1000);
  // d->updateHealth(80);
  // delay(1000);
  // d->updateHealth(40);
  // delay(2000);
  d->updateAmmo(6);
}

void loop() {

  trigger->loop();
  // delay(1000);
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

  
  // digitalWrite(8, HIGH);
  // delay(1000);
  // digitalWrite(8, LOW);
  // delay(1000);

  // mySender.send(SONY,0xa8bca, 20);
  // Serial.println(F("Sent signal."));
  // delay(1000);

  
  
}