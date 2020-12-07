#include "../../unity/unity.h"
#include "../src/LedDriver.h"

void whenLedDriverIsCreatedLedsAreOff()
{
  uint16_t mockLeds = 0xffff;
  LedDriver_Create(&mockLeds);
  TEST_ASSERT_EQUAL_HEX16(0, mockLeds);
}

void turnOnOneLed()
{
  uint16_t mockLeds;
  LedDriver_Create(&mockLeds);
  LedDriver_TurnOn(1);
  TEST_ASSERT_EQUAL_HEX16(1, mockLeds);
}

void turnOffOneLed()
{
  uint16_t mockLeds;
  LedDriver_Create(&mockLeds);
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  TEST_ASSERT_EQUAL_HEX16(0, mockLeds);
}

void turnOnMultipleLeds()
{
  uint16_t mockLeds;
  LedDriver_Create(&mockLeds);
  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);
  TEST_ASSERT_EQUAL_HEX16(0x180, mockLeds);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(whenLedDriverIsCreatedLedsAreOff);
  RUN_TEST(turnOnOneLed);
  RUN_TEST(turnOffOneLed);
  RUN_TEST(turnOnMultipleLeds);
  return UNITY_END();
}
