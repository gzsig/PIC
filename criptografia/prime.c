#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "prime.h"

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
  int max = 1000, min = 1, rand;
  rand = randomNumber(min, max);
  if (isPrime(rand))
  {
    return rand;
  }
  int i = rand - 1, j = rand + 1;
  while (i >= min && j <= max)
  {
    if (isPrime(i))
    {
      return i;
    }
    if (isPrime(j))
    {
      return j;
    }
    i--;
    j++;
  }

  while (i >= min)
  {
    if (isPrime(i))
    {
      return i;
    }
    i--;
  }

  while (j <= max)
  {
    if (isPrime(j))
    {
      return j;
    }
    j++;
  }

  return -1;
}

/**
 * Generates a random number inside range
 * @param min_num 
 * @param max_num 
 */
int randomNumber(int min_num, int max_num)
{
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num)
  {
    low_num = min_num;
    hi_num = max_num + 1; // include max_num in output
  }
  else
  {
    low_num = max_num + 1; // include max_num in output
    hi_num = min_num;
  }

  srand(time(NULL));
  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}