#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "prime.h"
#include "util.c"

/**
 * Checks if number is prime, return 1 if true 0 if false
 * @param number 
 */
int isPrime(int number)
{
  double n = floor(sqrt(number));
  if (number <= 3)
  {

    return number > 1;
  }

  if (number % 2 == 0 || number % 3 == 0)
  {

    return 0;
  }

  for (int i = 5; i <= n; i += 6)
  {

    if (number % i == 0 || number % i + 2 == 0)
    {
      return 0;
    }
  }

  return 1;
}

/**
 * Generates a random prime number
 */
int randPrime()
{
  int max = 20, min = 1, rand;
  rand = randomNumber(min, max);
  if (isPrime(rand))
  {
    printf("The selected prime number is: %d\n", rand);
    return rand;
  }
  int i = rand - 1, j = rand + 1;
  while (i >= min && j <= max)
  {
    if (isPrime(i))
    {
      printf("The selected prime number is: %d\n", i);
      return i;
    }
    if (isPrime(j))
    {
      printf("The selected prime number is: %d\n", j);
      return j;
    }
    i--;
    j++;
  }

  while (i >= min)
  {
    if (isPrime(i))
    {
      printf("The selected prime number is: %d\n", i);
      return i;
    }
    i--;
  }

  while (j <= max)
  {
    if (isPrime(j))
    {
      printf("The selected prime number is: %d\n", j);
      return j;
    }
    j++;
  }
  printf("No prime number found");
  return -1;
}

/**
 *  Returns 1 if the inputted numbers are coprime and 0 if not
 * @param num1 
 * @param num1 
 */
int coprime(int num1, int num2)
{
  return getGCDByModulus(num1, num2) == 1;
}