#include "../c/FizzBuzz.h"
#include "../unity/unity.h"

void whenPassedANumberReturnsItself()
{
  char expected[2] = "1";
  TEST_ASSERT_EQUAL_STRING(expected, fizzBuzz(1));
}

void whenPassed3ReturnFizz()
{
  char expected[5] = "Fizz";
  TEST_ASSERT_EQUAL_STRING(expected, fizzBuzz(3));

}

void whenPassed5ReturnBuzz()
{
  char expected[5] = "Buzz";
  TEST_ASSERT_EQUAL_STRING(expected, fizzBuzz(5));
}

void whenPassed15ReturnFizzBuzz()
{
  char expected[10] = "FizzBuzz";
  TEST_ASSERT_EQUAL_STRING(expected, fizzBuzz(15));
}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(whenPassedANumberReturnsItself);
RUN_TEST(whenPassed3ReturnFizz);
RUN_TEST(whenPassed5ReturnBuzz);
RUN_TEST(whenPassed15ReturnFizzBuzz);
return UNITY_END();
}
