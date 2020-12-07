#include <stdio.h>

int main(void){
  int numberInput = 0;

  printf("WELCOME!!! LET\'S GET FIZZBUZZED!!!\n\n\n\n");

  printf("Please enter a whole number:\n");
  scanf("%d", &numberInput );

  if(numberInput%15 == 0){
    printf("FIZZBUZZ\n");
  }
  else if(numberInput%5 == 0){
    printf("BUZZ\n");
  }
  else if(numberInput%3 == 0){
    printf("FIZZ\n");
  }
  else {
    printf("%d", numberInput );
  }
  return 0;
}
