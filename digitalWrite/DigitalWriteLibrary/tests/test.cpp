#include "CppUTest/TestHarness.h"
#include "digitalWrite.h"


TEST_GROUP(BitTwiddles)
{
    #define HIGH 1
    #define LOW 0

    int registerState;
    void setup()
    {
        registerState = 0;
    }
};

TEST(BitTwiddles, OneShiftOnAnInteger)
{
    registerState = 64;
    int fakePin = 7;
    int actual = togglePinOn(registerState, fakePin);
    CHECK_EQUAL(192, actual);
}

TEST(BitTwiddles, TurnOnPort7AndPort5)
{
    int fakePin7 = 7;
    int fakePin5 = 5;

    registerState = togglePinOn(registerState, fakePin7);
    registerState = togglePinOn(registerState, fakePin5);

    CHECK_EQUAL(160, registerState);
}
TEST(BitTwiddles, TurnOffPort5)
{
    int fakeRegister = 160;
    int fakePin5 = 5;

    fakeRegister = togglePinOff(fakeRegister, fakePin5);
    CHECK_EQUAL(128, fakeRegister);
}

TEST(BitTwiddles, WritetoPin)
{
    int fakeRegister = 0;
    int fakePin0 = 0;
    int fakePin1 = 1;
    int fakePin2 = 2;

    fakeRegister = writeToPin(fakeRegister, fakePin0, HIGH);
    fakeRegister = writeToPin(fakeRegister, fakePin1, HIGH);
    fakeRegister = writeToPin(fakeRegister, fakePin2, HIGH);
    fakeRegister = writeToPin(fakeRegister, fakePin1, LOW); 

    CHECK_EQUAL(5, fakeRegister);
}
