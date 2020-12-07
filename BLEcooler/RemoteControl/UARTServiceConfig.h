#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE_UART.h"

#define PACKET_BUTTON_LEN (6)
#define READ_BUFSIZE (20)

uint8_t packetbuffer[READ_BUFSIZE+1];

float parsefloat(uint8_t *buffer) 
{
  float f = ((float *)buffer)[0];
  return f;
}

uint8_t readPacket(Adafruit_BLE_UART *ble, uint16_t timeout) 
{
  uint16_t origtimeout = timeout, replyidx = 0;

  memset(packetbuffer, 0, READ_BUFSIZE);

  while (timeout--) {
    if (replyidx >= 20) break;
    if ((packetbuffer[1] == 'B') && (replyidx == PACKET_BUTTON_LEN))
      break;
    
    while (ble->available()) {
      char c =  ble->read();
      if (c == '!') {
        replyidx = 0;
      }
      
      packetbuffer[replyidx] = c;
      replyidx++;
      timeout = origtimeout;
    }
    if (timeout == 0) {
      break;
    }
    delay(1);
  }

  packetbuffer[replyidx] = 0;  // null term

  if (!replyidx) return 0;
  if (packetbuffer[0] != '!') return 0;
  return replyidx;
}
