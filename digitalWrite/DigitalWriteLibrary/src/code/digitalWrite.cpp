#include <stdlib.h>
#include "digitalWrite.h"


int togglePinOn (int currentStateOfRegister, int pinNumber)
{
  currentStateOfRegister |= (1 << pinNumber);

  return currentStateOfRegister;
}

int togglePinOff (int currentStateOfRegister, int pinNumber)
{
  currentStateOfRegister &= ~(1 << pinNumber);

  return currentStateOfRegister;
}

int writeToPin(int currentStateOfRegister, int pinNumber, int pinOn)
{
  if(pinOn == 1)
  {
    return togglePinOn(currentStateOfRegister, pinNumber);
  } else return togglePinOff(currentStateOfRegister, pinNumber);

}
