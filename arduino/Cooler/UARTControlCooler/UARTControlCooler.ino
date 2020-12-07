#include <Servo.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BLE_Firmata.h>
#include "Adafruit_BLE_UART.h"
#include "BluefruitConfig.h"

// Change this to whatever is the Serial console you want, either Serial or SerialUSB
#define FIRMATADEBUG    Serial
// Pause for Serial console before beginning?
#define WAITFORSERIAL   true
// Print all BLE interactions?
#define VERBOSE_MODE    false
// Pullups on all input pins?
#define AUTO_INPUT_PULLUPS true


/************************  CONFIGURATION SECTION ***********************************/
/*
Don't forget to also change the BluefruitConfig.h for the SPI connection
and pinout you are using!

Then below, you can edit the list of pins that are available. Remove any pins
that are used for accessories or for talking to the BLE module!
*/

/*********************************************************************
This is an example for our nRF8001 Bluetooth Low Energy Breakout

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1697

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Kevin Townsend/KTOWN  for Adafruit Industries.
MIT license, check LICENSE for more information
All text above, and the splash screen below must be included in any redistribution
*********************************************************************/

#include <SPI.h>

#include "Adafruit_BLE_UART.h"

// Connect CLK/MISO/MOSI to hardware SPI
// e.g. On UNO & compatible: CLK = 13, MISO = 12, MOSI = 11
#define ADAFRUITBLE_REQ 8
#define ADAFRUITBLE_RDY 2     // This should be an interrupt pin, on Uno thats #2 or #3
#define ADAFRUITBLE_RST 9

// connect motor controller pins to Arduino digital pins
// motor one
int ENA = 3;
int IN1 = 0;
int IN2 = 1;
// motor two
int ENB = 5;
int IN3 = 7;
int IN4 = 4;

Adafruit_BLE_UART BTLEserial = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);
Adafruit_BLE_FirmataClass BLE_Firmata = Adafruit_BLE_FirmataClass(BTLEserial);
#define BLE_READPACKET_TIMEOUT         50   // Timeout in ms waiting to read a response

// function prototypes over in packetparser.cpp
uint8_t readPacket(Adafruit_BLE_UART *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);

// the packet buffer
extern uint8_t packetbuffer[];


/**************************************************************************/
/*!
    Configure the Arduino and start advertising with the radio
*/
/**************************************************************************/
void setup(void)
{ 
  Serial.begin(9600);
  while(!Serial); // Leonardo/Micro should wait for serial init

  BTLEserial.setDeviceName("Cooler"); /* 7 characters max! */

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

/**************************************************************************/
/*!
    Constantly checks for new events on the nRF8001
*/
/**************************************************************************/
aci_evt_opcode_t laststatus = ACI_EVT_DISCONNECTED;

void loop()
{
  // Tell the nRF8001 to do whatever it should be working on.
  BTLEserial.pollACI();

  // Ask what is our current status
  aci_evt_opcode_t status = BTLEserial.getState();
  // If the status changed....
  if (status != laststatus) {
    // print it out!
    if (status == ACI_EVT_DEVICE_STARTED) {
        Serial.println(F("* Advertising started"));
    }
    if (status == ACI_EVT_CONNECTED) {
        Serial.println(F("* Connected!"));
    }
    if (status == ACI_EVT_DISCONNECTED) {
        Serial.println(F("* Disconnected or advertising timed out"));
    }
    // OK set the last status change to this one
    laststatus = status;
  }

  if (status != ACI_EVT_CONNECTED) {
    return;
  }

  /* Wait for new data to arrive */
  uint8_t len = readPacket(&BTLEserial, BLE_READPACKET_TIMEOUT);
  if (len == 0) return;
  
  // Buttons
  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    boolean pressed = packetbuffer[3] - '0';
    if(buttnum == 5) {
      if (pressed) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 120);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, 120);
      } else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW); 
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      }
    }
  }
}
