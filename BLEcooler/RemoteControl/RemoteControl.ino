#include <SPI.h>
#include "Adafruit_BLE_UART.h"
#include "UARTServiceConfig.h"

// motor one
#define ENA 3
#define IN1 0
#define IN2 1
// motor two
#define ENB 6
#define IN3 4
#define IN4 5

#define ADAFRUITBLE_REQ 8
#define ADAFRUITBLE_RST 9
#define ADAFRUITBLE_RDY 2  

#define BLE_READPACKET_TIMEOUT 50

Adafruit_BLE_UART UARTService = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);

aci_evt_opcode_t lastBTLEstatus, BTLEstatus;

uint8_t readPacket(Adafruit_BLE_UART *ble, uint16_t timeout);
extern uint8_t packetbuffer[];

void setup() 
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  while (!Serial) delay(1);
  Serial.begin(9600);
  bool serviceOn = UARTService.begin();
  UARTService.setDeviceName("COOLER");
}

void loop() 
{
  UARTService.pollACI();
  BTLEstatus = UARTService.getState();
  
  uint8_t len = readPacket(&UARTService, BLE_READPACKET_TIMEOUT);
  if (len == 0) return;

  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    boolean pressed = packetbuffer[3] - '0';
    if(buttnum == 5) {
      if (pressed) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 200);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, 200);
      } else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW); 
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      }
    }
  }
}
