#include <stdio.h>
#include "prime.c"

int main()
{
  int randNum = randPrime();
  printf("%d\n", randNum);
  return 0;
}
