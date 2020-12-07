#include "FizzBuzz.h"

char output[10];
int numbsOfFizzBuzz[] = {15, 5, 3};
char* wordsOfFizzBuzz[] = {"FizzBuzz", "Buzz", "Fizz"};

char* fizzBuzz(int inputNumber)
{
  sprintf(output, "%d", inputNumber);

  for(int i = 0; i < 3; i++)
  {
    if(inputNumber % numbsOfFizzBuzz[i] == 0){
      sprintf(output, "%s", wordsOfFizzBuzz[i]);
      break;
    }
  }

  return output;
}
