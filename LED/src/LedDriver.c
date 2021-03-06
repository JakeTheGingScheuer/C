#include "LedDriver.h"

static uint16_t * ledsAddress;
static uint16_t convertLedNumberToBit(int ledNumber)
{
  return 1 << (ledNumber-1);
}

void LedDriver_Create(uint16_t * addressOfPort)
{
  ledsAddress = addressOfPort;
  *ledsAddress = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
  *ledsAddress |= 1 << (ledNumber-1);
}

void LedDriver_TurnOff(int ledNumber)
{
  *ledsAddress = 0;
}
void LedDriver_Destroy(void){}
