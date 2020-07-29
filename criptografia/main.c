#include <stdio.h>
#include "prime.c"

int main()
{
  int randNum = randPrime();
  printf("%d\n", randNum);
  for (int i = 0; i < randNum + 1; i++)
  {
    if (coprime(i, randNum))
    {
      printf("%d\n", i);
    }
  }
  return 0;
}
